public class ProblemNine {
	
	private static int compareTwoArrays(int []a, int []b)
	{
		int len1 = a.length, len2 = b.length;
		int result = -1;
		if (len1 != len2)
			return result;
		
		for (int i = 0; i < len1-1; ++i)
		{
			if (a[i] == b[i+1])
			{
				result = i;
				break;
			}
		}
		return result;
	}
	
	public static int[] getLeftArray(int arr[], int n)
	{
		int left[] = new int[n];// all entries are zero bydefault
		int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			sum = sum + arr[i];
			left[i] = sum;
		}
		return left;
	}
	private static int[] getRightArray(int arr[], int n)
	{
		int right[] = new int[n];// all entries are zero bydefault
		int sum = 0;
		for (int i = n-1; i >= 0; --i)
		{
			sum = sum + arr[i];
			right[n-i-1] = sum;
		}
		return right;
	}
	
	private static void printArray(int []arr, int n)
	{
		for(int i = 0; i < n; ++i)
		{
			System.out.print(arr[i]+" ");
		}
		System.out.println();
	}

	public static void main(String []args)
	{
		int arr[] = {10, 5, 15, 3, 4, 21, 2};
		
		int []left = getLeftArray(arr, arr.length);
		int []right = getRightArray(arr, arr.length);
		
		//printArray(left, left.length);
		//printArray(right, right.length);
		
		int e_index = compareTwoArrays(left, right);
		
		System.out.println(e_index);
	}
	
}

