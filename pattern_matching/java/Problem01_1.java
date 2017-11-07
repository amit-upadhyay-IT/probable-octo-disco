package sols;

public class Problem01_1 {

	public static void main(String[] args) {
		
		String str1 = "abbabbaaabba";
		
		System.out.println("The number occurrence(s) of 'abba' in 'abbabbaaabba' is "+ getOccurrence(str1));
	}
	
	private static int getOccurrence(String str1)
	{
		int cnt = 0;
		DFA obj = new DFA();
		
		for (int i = 0; i < str1.length(); ++i)
		{
			obj.setNextState(str1.charAt(i));
			
			if (obj.currentState == STATES.FIFTH)
				cnt++;
		}
		return cnt;
	}

}

enum STATES {FIRST, SECOND, THIRD, FOURTH, FIFTH};

// a static DFA for accepting input sequence 'abba'
class DFA
{
	STATES currentState = STATES.FIRST, nextState;
	char input;
	
	public void setNextState(char input)
	{
		if (input == 'a')
		{
			switch (currentState)
			{
				case FIRST:
					currentState = STATES.SECOND;
					break;
				case SECOND:
					currentState = STATES.SECOND;
					break;
				case THIRD:
					currentState = STATES.SECOND;
					break;
				case FOURTH:
					currentState = STATES.FIFTH;
					break;
				case FIFTH:
					currentState = STATES.SECOND;
					break;
				
			}
		}
		else if (input == 'b')
		{
			switch (currentState)
			{
				case FIRST:
					currentState = STATES.FIRST;
					break;
				case SECOND:
					currentState = STATES.THIRD;
					break;
				case THIRD:
					currentState = STATES.FOURTH;
					break;
				case FOURTH:
					currentState = STATES.FIRST;
					break;
				case FIFTH:
					currentState = STATES.THIRD;
					break;
				
			}
		}
	}
}

// Time for getting number of occurrence is O(n)
