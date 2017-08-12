import java.util.Scanner;

public class OneOptimized
{
	public static void main(String []args)
	{
		Scanner scanner = new Scanner(System.in);
		String str = scanner.nextLine();
		if (isUnique(str))
			System.out.println("Unique Characters");
		else
			System.out.println("Repeated Chars");
		scanner.close();
	}
	
	// assuing the string only uses the lower case letters.
	// Space complexity further reduced by factor of 8 (as compared to One.java)
	public static boolean isUnique(String str)
	{
		int checker = 0;
		for(int i = 0; i <  str.length(); ++i)
		{
			int val = str.charAt(i) - 'a';
			if ((checker & (1 << val)) > 0)
				return false;
			checker |= (1 << val);
		}
		return true;
	}
}
