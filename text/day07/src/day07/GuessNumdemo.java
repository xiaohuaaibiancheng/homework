//package day07;
//import java.util.Scanner;
//public class GuessNumdemo {
//public static void main(String [] args)
//{
//	int num=(int) (Math.random()*100+1);
//	System.out.print(num);
//	while(true)
//	{
//	 Boolean m=judement(num);
//	 if(m==true)
//		 break;
//	}
//	
//	
//}
//static Boolean judement(int n)
//{
//	System.out.println("请输入你需要猜的数字:(1--100)");
//		Scanner sc=new Scanner(System.in);
//		int n2=sc.nextInt();
//		if(n==n2)
//			{System.out.println("恭喜你猜对了！");
//			return true;
//			}
//		
//		else
//			{
//			if(n>n2)
//			{
//				System.out.println("猜错了，请重新输入：");
//				System.out.println("猜小了");
//			}
//			if(n<n2)
//				{
//				System.out.println("猜错了，请重新输入：");
//				System.out.println("猜大了");
//				}
//			
//			return false;
//			}
//
//}
//	
//}
