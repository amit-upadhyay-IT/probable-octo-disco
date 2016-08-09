public class Five {

	public static void main(String []arsg)
	{
		String str;
		java.util.Scanner scanner = new java.util.Scanner(System.in);
		str = scanner.nextLine();
		String str2 = compressBad(str);
		if(str.length() < str2.length())
			System.out.println(str);
		else
			System.out.println(str2);
		scanner.close();
	}
	
	public static String compressBad(String str)
	{
		String myStr = "";
		char last = str.charAt(0);
		int count = 1;
		for(int i = 1; i < str.length(); ++i)
		{
			if(str.charAt(i) == last)
				count++;
			else
			{
				myStr = myStr + last + "" + count;
				last = str.charAt(i);
				count = 1;
			}
		}
		
		return myStr + last + count;
	}
	
}
