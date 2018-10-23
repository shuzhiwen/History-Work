
import java.util.Scanner;

class MyException extends Exception{
	public MyException(String s){
		super(s);
	}
}

public class Score{
	public static void main(String[] args){
		int scores[] = new int[10];
		Scanner scan = new Scanner(System.in);
		
		try{
			for(int i=0; i<scores.length; i++)
			{
				System.out.print("the score of "+(i+1)+"th student:");
				scores[i] = scan.nextInt();
				if(scores[i] <0 || scores[i]>100){
					throw new MyException("score <0 or score > 100");
				}
			}
		}catch(MyException e){
			System.out.println(e);
		}
	}
}