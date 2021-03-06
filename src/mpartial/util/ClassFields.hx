package mpartial.util;

#if macro

import haxe.macro.Expr;
import haxe.macro.Context;
import haxe.macro.Compiler;
import haxe.macro.Type;
import haxe.PosInfos;
import tink.macro.tools.Printer;

using tink.macro.tools.MacroTools;
using tink.macro.tools.ExprTools;
using tink.macro.tools.Printer;

#if haxe3
import haxe.ds.StringMap;
#else
typedef StringMap<T> = Hash<T>;
#end

typedef ParamDeclaration = 
{
	name:String,
	type:Type
}

/**
Macro for recursively converting ClassFields to Field types
*/
class ClassFields
{
	@:extern static inline var PRETTY = true;

	static var count:Int=0;

	/**
	Recursively aggregates fields from class and super classes, ensuring that
	inherited/overriden fields take precidence.

	@param c 				classType to convert to fields
	@param paramTypes 		typed paramaters for the current classType
	@param fieldHash 		cache of current super fields (optional)
	@param includeStatics 	indicates whether static fields should also be copied
	@param flattenSupers 	indicates whether calls to super() and super.xxx()
							should be flattened in the generated fields

	*/
	public static function getClassFields(c:ClassType, ?paramTypes:Array<Type>, ?fieldHash:StringMap<Field>, ?includeStatics:Bool=false, ?flattenSupers:Bool = true):Array<Field>
	{
		if(paramTypes == null) paramTypes = [];
		if(fieldHash == null) fieldHash = new StringMap();

		trace(c.name + ":" + paramTypes);

		var paramMap = getParamDeclarations(c.params, paramTypes);
		
		// recurse through super classes (or interfaces if an interface)
		var superTypes:Array<{ t : Ref<ClassType>, params : Array<Type> }> = [];

		if(c.superClass != null)
			superTypes.push(c.superClass);
		else if(c.isInterface)
			superTypes = superTypes.concat(c.interfaces);

		for(type in superTypes)
		{
			var superParams = replaceParamTypeArray( type.params, paramMap);

			trace("     superParams: " + superParams);
			var superFields = getClassFields(type.t.get(), superParams, fieldHash, includeStatics, flattenSupers);

			for(field in superFields)
			{
				fieldHash.set(field.name, field);
			}
		}
		
		for(classField in c.fields.get())
		{
			var field = getClassField(classField, paramMap);
			if(fieldHash.exists(field.name))
			{
				if(flattenSupers)
					field = mergeSuperField(field, fieldHash.get(field.name));
				else
					Context.error("MPartial does not support partials fragments with super classes.", Context.currentPos());
			}

			fieldHash.set(field.name, field);
		}

		if(includeStatics)
		{
			for(classField in c.statics.get())
			{
				var field = getClassField(classField, paramMap, true);
				fieldHash.set(field.name, field);
			}
		}

		if(c.constructor != null)
		{
			var field = getConstructorField(c,paramMap);

			if(fieldHash.exists(field.name))
			{
				if(flattenSupers)
					field = mergeSuperField(field, fieldHash.get(field.name), true);
				else
					Context.error("MPartial does not support partials fragments with super classes.", Context.currentPos());
			}
			fieldHash.set(field.name, field);
		}

		return Lambda.array(fieldHash);
	}

	/*
	Replaces the calls to super with the contents of the super constructor
	*/
	static function mergeSuperField(field:Field, superField:Field, ?isConstructor:Bool=false):Field
	{
		field.access.remove(AOverride);

		// trace(Printer.printField("", field));
		// trace(Printer.printField("", superField));

		var fieldExprs:Array<Expr> = [];
		var superFunction:Function = null;

		switch(field.kind)
		{
			case FFun(f):
				fieldExprs = toExprArray(f.expr);
			default:null;
		}

		switch(superField.kind)
		{
			case FFun(f):
				superFunction = f;
			default:null;
		}

		if(isConstructor)
			replaceSuperInConstructor(fieldExprs, superFunction);
		else
			replaceSuperInField(fieldExprs, superFunction);

		trace(Printer.printField("", field));
		
		return field;

	}
	
	static function replaceSuperInConstructor(fieldExprs:Array<Expr>, superFunction:Function)
	{
		for(expr in fieldExprs)
		{
			switch(expr.expr)
			{
				case ECall(e, params):
					switch(e.expr)
					{
						case EConst(c):
							switch(c)
							{
								case CIdent(s):
									if(s == "super")
									{
										//replace
										var eSuperfunc = EFunction(null, superFunction).at();
										var varName = "super_temp" + count++;
										var eSuperVar = varName.define(eSuperfunc);
										fieldExprs.unshift(eSuperVar);
										expr.expr  = ECall(EConst(CIdent(varName)).at(), params);
									}
								default:null;
							}
						default:null;
					}
				default:null;
			}
		}
	}

	static function replaceSuperInField(fieldExprs:Array<Expr>, superFunction:Function)
	{
		for (expr in fieldExprs)
		{
			switch (expr.expr)
			{
				case ECall(ecall, params):

					switch (ecall.expr)
					{
						case EField(e, _):
							switch (e.expr)
							{
								case EConst(c):
									switch(c)
									{
										case CIdent(s):
											if(s == "super")
											{
												//replace
												var eSuperfunc = EFunction(null, superFunction).at();
												var varName = "super_temp" + count++;
												var eSuperVar = varName.define(eSuperfunc);
												fieldExprs.unshift(eSuperVar);
												expr.expr  = ECall(EConst(CIdent(varName)).at(), params);
											}
										default:null;
									}
								default:null;
							}
						default:null;
					}
				default:null;
			}
		}
	}

	static function toExprArray(expr:Expr):Array<Expr>
	{
		switch(expr.expr)
		{
			case EBlock(exprs): return exprs;
			default: return [expr];
		}
	}
		/**
	Replaces abstract types (T, TData, etc) with concrete ones
	*/
	static function getParamDeclarations(paramTypes:Array<{t:Type, name:String}>, paramDecls:Array<Type>):Array<ParamDeclaration>
	{
		var results:Array<ParamDeclaration> = [];

		for(i in 0...paramTypes.length)
		{
			var param = paramTypes[i];

			var decl =
			{
				name:param.name,
				type:paramDecls[i]
			}
			results.push(decl);

		}
		return results;

	}

	/**
	Replaces abstract types with concrete declarations
	*/
	static function replaceParamTypeArray(superParams:Array<Type>, paramMap:Array<ParamDeclaration>):Array<Type>
	{
		var results:Array<Type> = [];

		for(param in superParams)
		{
			var paramType:Type = replaceParamType(param, paramMap);
			results.push(paramType);
		}

		return results;
	}

	static function replaceParamType(param:Type, paramMap:Array<ParamDeclaration>):Type
	{

		var paramId = param.getID();
		var paramName = paramId != null ? paramId.split(".").pop() : "";
		var paramType:Type = null;
		for(p in paramMap)
		{
			if(p.name == paramName)
				paramType = p.type;
		}

		if(paramType == null) paramType = param;


		return paramType;
	}

	static function isParamType(param:Type, paramMap:Array<ParamDeclaration>):Bool
	{
		var paramId = param.getID();
		var paramName = paramId != null ? paramId.split(".").pop() : "";
		for(p in paramMap)
		{
			if(p.name == paramName) return true;
		}
		return false;
	}


	public static function getClassField(field:ClassField, paramMap:Array<ParamDeclaration>, ?isStatic:Bool=false):Field
	{

		var kind = getFieldType(field,paramMap);

		var access = getFieldAccess(field);

		if(isStatic) access.push(AStatic);

		var meta = field.meta.get();

		if(kind == null)
			throw "FieldType is null. Cannot create field [" + field + "]";

		return {
			name:field.name,
			pos:field.pos,
			kind:kind,
			access: access,
			meta:meta
		}
	}

	static function getFieldAccess(field:ClassField)
	{
		var access:Array<Access> = field.isPublic ? [APublic] : [APrivate];

		switch(field.kind)
		{
			case FMethod(k):
				switch(k)
				{
					case MethInline: access.push(AInline);
					case MethDynamic: access.push(ADynamic);
					default: null;
				}
			default: null;
		}

		return access;
	}

	static function getConstructorField(c:ClassType, paramMap:Array<ParamDeclaration>):Field
	{
		var classField = c.constructor.get();

		classField.name = "new";

		var field = getClassField(classField,paramMap);

		return field;
	}

	/**
	Converts a Type to ComplexType and subsitutes Param types (e.g. <T>) with concrete ones
	*/
	static function convertType(type:Type, paramMap:Array<ParamDeclaration>):ComplexType
	{
		trace(type);
		if(isParamType(type, paramMap))
		{
			type = replaceParamType(type, paramMap);
		}

		switch(type)
		{
			case TDynamic(t):
				if(t == null)
					return TPath({pack:[], name:"StdTypes", sub:"Dynamic", params:[]});

				var param = TPType(t.toComplex(true));
				return TPath({pack:[], name:"StdTypes", sub:"Dynamic", params:[param]});
			default:
				return type.toComplex(PRETTY);
		}
	}

	public static function getFieldType(field:ClassField, paramMap:Array<ParamDeclaration>):FieldType
	{
		var expr = getFieldExpr(field);

		switch(field.kind)
		{
			case FVar(read, write):
			{
				return FProp(getVarAccess(read), getVarAccess(write), convertType(field.type, paramMap), expr);
			}
			case FMethod(k):
			{
				switch(k)
				{
					case MethMacro: null;
					default:
						switch(Context.follow(field.type))
						{
							case TFun(args, ret):

								return FFun(
								{
									args:convertTFunArgsToFunctionArgs(args, paramMap),
									ret: convertType(ret, paramMap),
									expr:expr,
									params:[]
								});

							default: throw "not implemented for type [" + field.type + "]";
						}
				}
			}
		}

		return null;
	}

	static function convertTFunArgsToFunctionArgs(args : Array<{ t : Type, opt : Bool, name : String }>, paramMap:Array<ParamDeclaration>):Array<FunctionArg>
	{
		var converted:Array<FunctionArg> = [];

		for(arg in args)
		{
			var value = 
			{
				value : null, //Null<Expr>
				type : convertType(arg.t, paramMap), //<ComplexType>
				opt : arg.opt,
				name : arg.name
			}
			converted.push(value);
		}

		return converted;
	}

	static function getVarAccess(access:VarAccess):String
	{
		return switch (access)
		{
			case AccNormal, AccInline: "default";
			case AccNo: "null";
			case AccNever: "never";	
			case AccResolve: throw "not implemented for VarAccess [" + access + "]";
			#if haxe3
			case AccCall: throw "not implemented VarAccess [" + access + "]";
			case AccRequire(_,_): throw "not implemented VarAccess [" + access + "]";
			#else
			case AccCall(m): m;
			case AccRequire(_): throw "not implemented VarAccess [" + access + "]";
			#end
		}		
	}

	/**
	Converts a ClassField's TypedExpr to an Expr
	*/
	public static function getFieldExpr(classField:ClassField):Expr
	{
		var typedExpr = classField.expr();

		if(typedExpr == null) return null;

		var expr = Context.getTypedExpr(typedExpr);

		switch (classField.kind)
		{
			case FMethod(_):
			{
				switch (expr.expr)
				{
					case EFunction(_, f):
						return f.expr;
					default: throw "not implemented for ExprDef [" + expr.expr + "]";//return null;
				}
			}
			case FVar(_,_):
			{
				return expr;
			}
		}
	}
}

#end