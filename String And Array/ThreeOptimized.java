// the other way of solving problem is to check if the two strings have identical character counts or not.
public class ThreeOptimized {
	
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
	
	public static boolean isPermutation(String str1, String str2)
	{
		int arr1[] = new int[256];
		int arr2[] = new int[256];
		if (str1.length() != str2.length())
			return false;
		for(int i = 0; i < str1.length(); ++i)
		{
			arr1[str1.charAt(i)]++;
		}
		for(int i = 0; i < str2.length(); ++i)
		{
			arr2[str2.charAt(i)]++;
		}
		if (java.util.Arrays.equals(arr1, arr2))
			return true;
		else
			return false;
	}

}
