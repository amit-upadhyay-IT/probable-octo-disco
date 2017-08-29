class DetailsOfSubArray
{
	public int size, lowerBound, upperBound;
	
	public DetailsOfSubArray(int size, int lowerBound, int upperBound)
	{
		this.size = size;
		this.lowerBound = lowerBound;
		this.upperBound = upperBound;
	}
}

public class ProblemFourteen {
	
	void printArray(int []arr, int firstIndex, int lastIndex)
	{
		for (int i = firstIndex; i <= lastIndex; ++i)
			System.out.print(" "+arr[i]);
		System.out.println();
	}

	void replaceZerosOrNegOnes(int []arr, int n, boolean repZero)
	{
		for (int i = 0; i < n; ++i)
		{
			if (repZero)
			{
				if (arr[i] == 0)
					arr[i]  = -1;
			}
			else
			{
				if (arr[i] == -1)
					arr[i] = 0;
			}
		}	
	}
	
	DetailsOfSubArray getMaxSubArray(int []arr, int n)
	{
		java.util.HashMap<Integer, Integer> hm = new java.util.HashMap<>();
		int sum = 0;
		int size = 0, lowerBound = 0, upperBound = 0;
		
		for (int i = 0; i < n; ++i)
		{
			sum = sum + arr[i];
			
			if (hm.get(sum) != null)
			{
				// the sum is already mapped to something in hashmap
				int currentSize = i - hm.get(sum);
				if (currentSize > size)
				{
					size = currentSize;
					lowerBound = hm.get(sum);
					upperBound = i;
				}
			}
			else
				hm.put(sum, i);
		}
		return new DetailsOfSubArray(size, lowerBound+1, upperBound);
	}
	
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		java.util.Scanner sc = new java.util.Scanner(System.in);
		System.out.println("Enter n");
		int n = sc.nextInt();
		int arr[] = new int[n];
		System.out.println("Enter elements");
		for (int i = 0; i < n; ++i)
		{
			arr[i] = sc.nextInt();
		}
		ProblemFourteen o = new ProblemFourteen();
		o.replaceZerosOrNegOnes(arr, n, true);
		DetailsOfSubArray details = o.getMaxSubArray(arr, n);
		o.replaceZerosOrNegOnes(arr, n, false);
		o.printArray(arr, details.lowerBound, details.upperBound);
		sc.close();
	}

}

