public class ProblemThree {

	private static boolean isRotation(StringBuilder s1, StringBuilder s2)
	{
		s1 = s1.append(s1);
		return s1.indexOf(s2.toString()) != -1;
	}
	
	public static void main(String[] args) {

		StringBuilder s1 = new StringBuilder("AMIT");
		StringBuilder s2 = new StringBuilder("TAMI");
		if (isRotation(s1, s2))
			System.out.println("YES");
		else
			System.out.println("NO");
	}
}
