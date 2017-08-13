
import java.util.Arrays;
import java.util.Scanner;

class Info
{
	private char maxChar;
	private int charCnt;

	public Info(char maxChar, int charCnt)
	{
		this.maxChar = maxChar;
		this.charCnt = charCnt;
	}

	public char getMaxChar()
	{
		return maxChar;
	}

	public int getMaxCnt()
	{
		return charCnt;
	}
}

public class ProblemOne {

	private static Info getMaxOccurrence(char []c_arr)
	{
		int maxCnt = 0, currCnt = 0;
		char maxChar = 0;

		for (int i = 0; i < c_arr.length-1; ++i)
		{
			if (c_arr[i] == c_arr[i+1])
				currCnt++;
			else
				currCnt = 0;

			if (currCnt > maxCnt)
			{
				maxCnt = currCnt;
				maxChar = c_arr[i];
			}
		}
		return new Info(maxChar, maxCnt+1);
	}

	public static void main(String []args)
	{
		Scanner sc = new Scanner(System.in);
		String inputString = sc.nextLine();

		char []c_arr = inputString.toCharArray();

		Arrays.sort(c_arr);

		System.out.println(c_arr);

		Info obj = getMaxOccurrence(c_arr);
		System.out.printf("Maximum occurrence is %c and count is %d ", obj.getMaxChar(), obj.getMaxCnt());

		sc.close();
	}

}

