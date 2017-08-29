public class ProblemThirteen {
	
	public void printArray(int arr[], int firstIndex, int lastIndex)
	{
		for (int i = firstIndex; i <= lastIndex; ++i)
		{
			System.out.print(arr[i]+" ");
		}
		System.out.println();
	}

	public void createHash(int arr[], int n, int x)
	{
		java.util.HashMap<Integer, Integer> hm = new java.util.HashMap<>();
		int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			sum = sum + arr[i];
			hm.put(sum, i);
			
			if (hm.get(sum - x) != null)// found
			{
				int firstIndex = hm.get(sum - x)+1;
				int lastIndex = i;
				printArray(arr, firstIndex, lastIndex);
				break;
			}
		}
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
		System.out.println("Enter required sum");
		int x = sc.nextInt();
		
		new ProblemThirteen().createHash(arr, n, x);
		sc.close();
	}

}

