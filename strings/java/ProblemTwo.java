package practive;

public class ProblemTwo {

	private void removeDuplicates(char []cStr)
	{
		int hash[] = new int[256];// all values are initialized to 0
		int i = 0, j = 0;
		while (i < cStr.length && j < cStr.length)
		{
			if (hash[cStr[i]] == 0)
			{
				// no such value was ever present, so we just increment i
				hash[cStr[i]] = 1;
				i++;
			}
			else
			{
				// value is repeating so we search for value which is not into hash
				while (hash[j] == 0)
					j++;
				cStr[i] = cStr[j];
				i++;
			}
		}
		System.out.println(cStr);
	}
	
	public static void main(String[] args) {
		
		//StringBuilder str = new StringBuilder("gaadbbaaggaiij");
		
		String str = new String("gaadbbaaggaiij");
		char []cStr = str.toCharArray();
		
		new ProblemTwo().removeDuplicates(cStr);

	}

}

