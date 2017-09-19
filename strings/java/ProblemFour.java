public class ProblemFour {
	
	private void reverse(char []c, int i, int j)
	{
		if (i >= j)
			return;
		for (int k = i; k <= (i+j)/2; ++k)
		{
			char t = c[k];
			c[k] = c[i+j-k];
			c[i+j-k] = t;
		}
	}
	
	private void revWords(char []c)
	{
		int firstPos = 0;
		reverse(c, 0, c.length-1);
		for (int i = 0; i < c.length; ++i)
		{
			if (c[i] == ' ')
			{
				reverse(c, firstPos, i-1);
				firstPos = i+1;
			}
			else if (i+1 == c.length)
				reverse(c, firstPos, i);
		}
	}

	
	
	public static void main(String[] args) {

		String str = "my name is amit";
		char s[] = str.toCharArray();
		ProblemFour obj =new ProblemFour();
		obj.revWords(s);
		System.out.println(s);
	}
}
