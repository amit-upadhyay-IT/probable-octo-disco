public class ProblemFive {
	
	private char []str;
	
	private void rev2(char []str, int i, int j)
	{
		if (i >= j)
			return ;
		for (int k = i; k <= (i+j)/2; ++k)
		{
			char t = str[k];
			str[k] = str[i+j-k];
			str[i+j-k] = t;
		}
	}
	
	private void revStr(char []str, int begin, int end)
	{
		while (begin < end)
		{
			char temp = str[begin];
			str[begin] = str[end];
			str[end] = temp;
			begin++;
			end--;
		}
	}
	
	public static void main(String []args)
	{
		ProblemFive obj = new ProblemFive();
		obj.str = String.valueOf("amit upadhyay").toCharArray();
		obj.revStr(obj.str, 0, obj.str.length-1);
		System.out.println(obj.str);
	}

}

