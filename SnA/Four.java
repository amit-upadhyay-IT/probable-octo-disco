public class Four {
	
	public static void main(String []args)
	{
		String str = new String();
		java.util.Scanner scanner = new java.util.Scanner(System.in);
		str = scanner.nextLine();
		Four obj = new Four();
		int len = str.length();
		str = obj.changedString(str, len);
		System.out.println("New String Formed : "+str);
		scanner.close();
	}
	
	public String changedString(String str, int len)
	{
		int sCount = 0;
		for(int i = 0; i < len; ++i)
		{
			if (str.charAt(i) == ' ')
				sCount++;
		}
		int newLen = (2*sCount) + len;
		
		char str2[] = new char[newLen+1];
		str2[newLen] = '\0';
		
		for (int i = len-1; i >= 0; i--) 
		{
			if (str.charAt(i) == ' ')
			{
				str2[newLen -1] = '0';
				str2[newLen -2] = '2';
				str2[newLen -3] = '%';
				newLen = newLen-3;
			}
			else
			{
				str2[newLen-1] = str.charAt(i);
				newLen = newLen - 1;
			}
		}
		return new String(str2);
	}
}
