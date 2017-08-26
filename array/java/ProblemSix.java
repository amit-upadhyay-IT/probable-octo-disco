public class ProblemSix {
	
	public void swap(int []arr, int index1, int index2)
	{
		int temp = arr[index1];
		arr[index1] = arr[index2];
		arr[index2] = temp;
	}
	
	public void partitionArray(int arr[], int n)
	{
		int pIndex = 0;
		int pivot = 1;
		
		for (int i = 0; i < n-1; ++i)
		{
			if (arr[i] < pivot)
			{
				swap(arr, i, pIndex);// swap if element is lesser than pivot 
				pIndex++;
			}
		}
		swap(arr, pIndex, n-1);
	}
	
	public void printArray(int []arr, int n)
	{
		for (int i = 0; i < n; ++i)
		{
			System.out.printf("%d ", arr[i]);
		}
	}
	
	public static void main(String []args)
	{
		int arr[] = {0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0};
		
		ProblemSix obj = new ProblemSix();
		
		obj.partitionArray(arr, arr.length);
		obj.printArray(arr, arr.length);
		
	}
	
}

