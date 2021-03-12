import java.math.BigInteger; 
import java.util.Scanner; 

public class fact
{ 
	// Returns Factorial of N 
	static BigInteger factorial(int N) 
	{ 
		// Initialize result 
		BigInteger f = new BigInteger("1"); // Or BigInteger.ONE 

		// Multiply f with 2, 3, ...N 
		for (int i = 2; i <= N; i++) 
			f = f.multiply(BigInteger.valueOf(i)); 

      	BigInteger n= new BigInteger("10");

      BigInteger zero= new BigInteger("0");


int count=0;
      while(f.compareTo(zero)==1)
      {
        f= f.divide(n);
         count++;

      }

      System.out.println("Number of digits : "+count);

		return f; 
	} 

	// Driver method 
	public static void main(String args[]) throws Exception 
	{ 
		int N = 50000; 
		
		
		System.out.println(factorial(N)); 
	} 
} 