public class FileProg
{
	private String s1, s2;
	
	public FileProg(String s1, String s2)
	{
		this.setS1(s1);
		this.setS2(s2);
	}
	
	public static void main(String []args)
	{	
		java.util.Scanner scanner = new java.util.Scanner(System.in);
		
		System.out.println("Enter first string");
		String s1 = scanner.nextLine();
		System.out.println("Enter second string");
		String s2 = scanner.nextLine();
		
		FileProg classObject = new FileProg(s1, s2);
		
		
		boolean b = classObject.isRotation(s1, s2);
		
		if (b) {
			System.out.println("true");
		} else {
			System.out.println("false");
		}
		
		scanner.close();
	}
/*	
	public boolean isSubString(String s1, String s2)
	{
		int counter = 0;
		
		int i, j;
		
		for(i = 0, j = 0; i < s1.length() && j < s2.length(); i++)
		{
			if (s2.charAt(j) == s1.charAt(i))
			{
				counter++;
				j++;
			}
			else
			{
				j = 0;
				counter = 0;
			}
		}
		return (counter == s2.length());
	}*/
	
	public boolean isRotation(String s1, String s2)
	{
		//FileProg obj = new FileProg(s1, s2);
		String s1s1 = s1.concat(s1);
		return s1s1.contains(s2);
		//return (obj.isSubString(s1s1, s2));
	}

	public String getS1() {
		return s1;
	}

	public void setS1(String s1) {
		this.s1 = s1;
	}

	public String getS2() {
		return s2;
	}

	public void setS2(String s2) {
		this.s2 = s2;
	}
	
}
