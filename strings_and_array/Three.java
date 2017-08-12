//check if one string is permutation of other or not

//assuming the comparisons will be done case sensitive also taking space into consideration.
public class Three {

	public static String sort(String str)
	{
		char []cStr = str.toCharArray();
		java.util.Arrays.sort(cStr);
		return new String(cStr);
	}
	public static boolean isPermutation(String str1, String str2)
	{
		if (str1.length() != str2.length())
			return false;
		else if (sort(str1).equals(sort(str2)))
			return true;
		return false;
		
	}
	public static void main(String []args)
	{
		String str1, str2;
		java.util.Scanner scanner = new java.util.Scanner(System.in);
		str1 = scanner.nextLine();
		str2 = scanner.nextLine();
		if (isPermutation(str1, str2))
			System.out.println("Permutation");
		else
			System.out.println("Not Permutation");
		scanner.close();
	}
	
}
