class Pairs
{
	private int a, b;
	private int k;
	
	public Pairs()
	{
		a = 0; b = 0;
	}
	
	public Pairs[] getPairs(int []arr, int val, int n)
	{
		k = 0;
		java.util.Map <Integer, Boolean> hm = new java.util.HashMap<>();
		
		Pairs []p = new Pairs[100];// declaring array of Pairs to store possible pairs
		
		for (int i = 0; i < n; ++i)
		{
			int temp = val - arr[i];
			
			if (hm.containsKey(temp) && hm.get(temp) && temp>=0)
			{
				p[k] = new Pairs();
				p[k].a = arr[i];
				p[k++].b = temp;
			}
			hm.put(arr[i], true);
		}
		
		return p;
	}
	
	public void printPairs(Pairs[] p)
	{
		for (int i = 0; i < k; ++i)
		{
			System.out.printf("(%d, %d)", p[i].a, p[i].b);
		}
	}
}

public class ProblemOne {
	
	public static void main(String []args)
	{
		java.util.Scanner sc = new java.util.Scanner(System.in);
		
		System.out.println("Enter n");
		int n = sc.nextInt();
		System.out.println("Enter elements");
		int arr[] = new int[n];
		
		for (int i = 0; i< n; ++i)
		{
			arr[i] = sc.nextInt();
		}
		
		System.out.println("Enter value :");
		int val = sc.nextInt();
		
		Pairs obj = new Pairs();
		Pairs []p = obj.getPairs(arr, val, n);
		obj.printPairs(p);
		
		sc.close();
	}

}

