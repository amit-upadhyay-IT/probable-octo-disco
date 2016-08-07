import java.util.Scanner;

public class One
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
	public static boolean isUnique(String str)
	{
		boolean char_set[] = new boolean[256];
		for(int i = 0; i < str.length(); ++i)
		{
			if(char_set[str.charAt(i)])
				return false;
			char_set[str.charAt(i)] = true;
		}
		return true;
	}
}
