package example;

class Validator<T>
{
	public var invalid:Bool = false;

	public function new()
	{
		
	}

	public function invalidate()
	{
		invalid = true;
	}

	public function validate()
	{
		if(invalid)
			invalid = false;
	}
}