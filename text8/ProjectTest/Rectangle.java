class Rectangle implements Fingure
{
	Rectangle()
	{
		
	}
	Rectangle(double length,double width)
	{
		setLength(length);
		setWidth(width);
	}
	
	public double Perimeter() //周长
	{
		return (this.length+this.width)*2;
	}
	
	public double Square()  //面积
	{
		double sum=length*width;
		return sum;
	}

	public void setLength(double length)
	{
		this.length=length;
	}
	
	public void setWidth(double width)
	{
		this.width=width;
	}
	
	public double getLength()
	{
		return this.length;
	}
	public double getWidth()
	{
		return this.width;
	}
	public String tostring()
	{
		return "I am a Rectangle,square is"+Square()+"and Perimeter is"+Perimeter();
	}
	private double  length=0,width=0;
}