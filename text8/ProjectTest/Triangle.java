class Triangle implements Fingure
{
	Triangle()
	{
		
	}
	Triangle(double  length1,double length2,double length3)
	{
		setLength1(length1);
		setLength2(length2);
		setLength3(length3);
	}
	public double Perimeter()
	{
		return this.length1+this.length2+this.length3;
	}
	
	public double Square()
	{
		double p=(this.length1+this.length2+this.length3)/2.0;
		double sum=p*(p-this.length1)*(p-this.length2)*(p-this.length3);
		return Math.sqrt(sum);
	}
	
	public void setLength1(double length)
	{
		this.length1=length;
	}
	public void setLength2(double length)
	{
		this.length2=length;
	}
	public void setLength3(double length)
	{
		this.length3=length;
	}

	public double getLength1()
	{
			return this.length1;
	}

	public double getLength2()
	{
			return this.length2;
	}

	public double getLength3()
	{
			return this.length3;
	}
	
	public String tostring()
	{
		return "I am a Triangle,square is"+Square()+"and Perimeter is"+Perimeter();
	}
	private double  length1=0,length2=0,length3=0;
}