public class ProblemTwentyOne {

	private int getTrianlgeCount(int []arr, int n)
	{
		int i, j, k;
		int cnt = 0;

		for (i = 0; i < n-2; ++i)
		{
			for (j = i+1; j < n-1; ++j)
			{
				k = j+1;
				while (k < arr.length && arr[i] + arr[j] > arr[k])
					k++;
				cnt = cnt + k-j-1;
			}
		}
		return cnt;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		java.util.Scanner sc = new java.util.Scanner(System.in);

		int arr[] = {8, 7, 10, 6, 14, 12, 50};

		java.util.Arrays.sort(arr);

		int count = new ProblemTwentyOne().getTrianlgeCount(arr, arr.length);

		System.out.println("The possible trianlges are "+ count);

		sc.close();


	}

}

