public class Power {

	// calculate x^y in O(n) time
	private static java.math.BigInteger power(int x, int y)
	{
		if (y == 0)
			return new java.math.BigInteger("1");
		else
			return new java.math.BigInteger(String.valueOf(x)).multiply(power(x, y-1));  // return x * power(y-1)
	}
	
	// calculate x^y in O(log2(n)) time
	private static java.math.BigInteger power_optimized(int x, int y)
	{
		// base case
		if (y == 0)
			return new java.math.BigInteger("1");
		// recursive case
		else
		{
			java.math.BigInteger res = power_optimized(x, y/2);
			// y is odd
			if ((y & 1) != 0)
				return res.multiply(res.multiply(new java.math.BigInteger(String.valueOf(x))));  // return x * res * res
			else
				return res.multiply(res);  // return res * res
		}
	}
	
	public static void main(String []args)
	{
		java.io.BufferedReader br = new java.io.BufferedReader(new java.io.InputStreamReader(System.in));
		try {
			System.out.println("Enter x: ");
			int x = Integer.parseInt(br.readLine());
			System.out.println("Enter y: ");
			int y = Integer.parseInt(br.readLine());
			long startTime = System.nanoTime();
			System.out.println(power(x, y));
			long endTime   = System.nanoTime();
			System.out.println("Execution time for power: " + (endTime - startTime) + " ns");
			System.out.println("---------------");
			startTime = System.nanoTime();
			System.out.println(power_optimized(x, y));
			endTime   = System.nanoTime();
			System.out.println("Execution time for power_optimized: " + (endTime - startTime) + " ns");
		} catch (java.io.IOException e) {
			e.printStackTrace();
		}
	}
}
