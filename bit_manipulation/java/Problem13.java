public class Problem13
{
    public static String printBinary(double num)
    {
        if (num >= 1 || num <= 0)
            return "Error";

        StringBuilder binary = new StringBuilder();
        binary.append(".");
        while (num > 0)
        {
            if (binary.length() >= 32)
                return "Error";

            double r = num * 2;
            if (r >= 1)
            {
                binary.append(1);
                num = r - 1;
            }
            else
            {
                binary.append(0);
                num = r;
            }
        }
        return binary.toString();
    }

    public static void main(String []args)
    {
        String output = printBinary(0.60);
        System.out.println(output);
    }
}
