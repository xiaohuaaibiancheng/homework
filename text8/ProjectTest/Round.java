class Round implements Fingure
{
	Round()
	{
		
	}
	Round(double  radius)
	{
		setRadius(radius);
	}
	public double Perimeter() //周长
	{
		return Math.PI*2*radius;
	}
	
	public double Square()  //面积
	{
		double sum=Math.PI*Math.pow(radius, 2);
		return sum;
	}

	public void setRadius(double radius)
	{
		this.radius=radius;
	}
	

	public double getRadius()
	{
		return this.radius;
	}

	public String tostring()
	{
		return "I am a Round,square is"+Square()+"and Perimeter is"+Perimeter();
	}
	private double  radius=0;
}