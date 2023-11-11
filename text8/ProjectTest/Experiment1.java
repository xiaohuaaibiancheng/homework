import java.util.Scanner;
public class Experiment1 {
	
static void Compare_Square(double a,double b)
{
	
	if(a>b)
		System.out.println("1的面积大于2的面积");
	else if(a==b)
	{
		System.out.println("1的面积等于2的面积");
	}
	else 
	{
		System.out.println("1的面积小于2的面积");
	}
}

static void Compare_Perimeter(double a,double b)
{
	if(a>b)
		System.out.println("1的周长大于2的周长");
	else if(a==b)
	{
		System.out.println("1的周长等于2的周长");
	}
	else 
	{
		System.out.println("1的周长小于2的周长");
	}
}
static void Compare_Perimeterdemo(Fingure a,Fingure b)
{
	if(a.Perimeter()>b.Perimeter())
		System.out.println("a的周长大于b的周长");
	else if(a.Perimeter()==b.Perimeter())
	{
		System.out.println("a的周长等于b的周长");
	}
	else 
	{
		System.out.println("a的周长小于b的周长");
	}
}

public static void main(String [] args)
{
	Scanner sc = new Scanner(System.in); 
	//比较两个图像的周长
//	Fingure rectange = new Rectangle(3,4);
//	Fingure round = new Round(5);
//	System.out.println(rectange.Perimeter());
//	System.out.println(rectange.tostring());

//	Compare_Perimeterdemo(rectange,round);
	Rectangle rectange1 = new  Rectangle();
	Rectangle rectange2 = new  Rectangle();

	Round round = new Round();
	Triangle triangel = new Triangle();
	System.out.println("请输入第一个长方形的参数：");
	System.out.println("长1：");
	rectange1.setLength(sc.nextDouble());
	System.out.println("宽1：");
	rectange1.setWidth(sc.nextDouble());
	System.out.println("请输入第二个长方形的参数：");
	System.out.println("长2：");
	rectange2.setLength(sc.nextDouble());
	System.out.println("宽2：");
	rectange1.setWidth(sc.nextDouble());
	System.out.println("第一个图形的描述为：");
	System.out.println(rectange1.tostring());
	System.out.println("第二个图形的描述为：");
	System.out.println(rectange2.tostring());
	System.out.println("周长面积的比较为：");
	System.out.println("周长面积的比较为：");
	Compare_Perimeter(rectange1.Perimeter(), rectange2.Perimeter());
	Compare_Square(rectange1.Square(),rectange2.Square());
//	Round round1 = new Round();
//	Round round2 = new Round();
//	System.out.println("请输入第一个圆形的参数：");
//	System.out.println("半径1：");
//	round1.setRadius(sc.nextDouble());
//	System.out.println("请输入第二个圆形的参数：");
//	System.out.println("半径2：");
//	round2.setRadius(sc.nextDouble());
//	System.out.println("第一个图形的描述为：");
//	System.out.println(round1.tostring());
//	System.out.println("第二个图形的描述为：");
//	System.out.println(round2.tostring());
//	System.out.println("周长面积的比较为：");
//	Compare_Perimeter(round1.Perimeter(), round2.Perimeter());
//	Compare_Square(round1.Square(),round2.Square());

	sc.close();
}


}



