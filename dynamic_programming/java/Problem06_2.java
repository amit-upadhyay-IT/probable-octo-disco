public class Problem06_2 {
	
	public static void main(String[] args) {
		
		java.util.Scanner sc = new java.util.Scanner(System.in);
		
		int k = sc.nextInt();
		
		int U[] = new int[k+1]; // since we have to generate kth num
		
		System.out.println(getKthUglyNumber(U, k));
		
		sc.close();
		
	}
	
	private static int getMin(int a, int b, int c)
	{
		if (a < b)
		{
			if (c < a)
				return c;
			else
				return a;
		}
		else  // b < a
		{
			if (c < b)
				return c;
			else
				return b;
		}
	}
	
	private static int getKthUglyNumber(int []U, int pos)
	{
		U[0] = 1; //  the first ugly number is 1
		
		int i, j, k;
		i = j = k = 0;
		
		int mini = 0;
		int index = 1;
		while (index < pos)
		{
			mini = getMin(U[i]*2, U[j]*3, U[k]*5);
			U[index] = mini;
			
			// incrementing the index only if we found distinct number adjacently
			if (U[index-1] != U[index])
			{
				index++;
			}
			
			// incrementing the required pointer
			if (mini == U[i]*2)
				i++;
			else if (mini == U[j]*3)
				j++;
			else
				k++;
		}
		
		return U[index-1];
	}

}
package dymamic_programming;

public class Problem06_2 {
	
	public static void main(String[] args) {
		
		java.util.Scanner sc = new java.util.Scanner(System.in);
		
		int k = sc.nextInt();
		
		int U[] = new int[k+1]; // since we have to generate kth num
		
		System.out.println(getKthUglyNumber(U, k));
		
		sc.close();
		
	}
	
	private static int getMin(int a, int b, int c)
	{
		if (a < b)
		{
			if (c < a)
				return c;
			else
				return a;
		}
		else  // b < a
		{
			if (c < b)
				return c;
			else
				return b;
		}
	}
	
	private static int getKthUglyNumber(int []U, int pos)
	{
		U[0] = 1; //  the first ugly number is 1
		
		int i, j, k;
		i = j = k = 0;
		
		int mini = 0;
		int index = 1;
		while (index < pos)
		{
			mini = getMin(U[i]*2, U[j]*3, U[k]*5);
			U[index] = mini;
			
			// incrementing the index only if we found distinct number adjacently
			if (U[index-1] != U[index])
			{
				index++;
			}
			
			// incrementing the required pointer
			if (mini == U[i]*2)
				i++;
			else if (mini == U[j]*3)
				j++;
			else
				k++;
		}
		
		return U[index-1];
	}

}

// time complexity = O(k)
// space complexity = O(k), for the auxilary array U[]
