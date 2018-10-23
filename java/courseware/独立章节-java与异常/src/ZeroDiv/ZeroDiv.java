
public class ZeroDiv{
	public void div(int a, int b){
		int c = 0;
		try{
			c = a/b;
		}catch(ArithmeticException e){
			System.out.println("can not divide zero");
		}catch(Exception e){
			System.out.println("some other errors than dividing zero");
		}finally{
			System.out.println("please try again");
		}
		System.out.println("the result = "+c);
	}
	public static void main(String[] args){
		ZeroDiv zd = new ZeroDiv();
		zd.div(10, 0);
		System.out.println("---------------");
		zd.div(10, 1);
	}
}