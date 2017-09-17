import java.util.Arrays;

public class ProblemOne2 {

private static int max_cnt = 0;

    private static char getMaxOccurredChar(String str)
    {
        char max_char = str.charAt(0);
        int cnt = 0;
        for (int i = 0; i < str.length()-1; ++i)
        {
            if (str.charAt(i) == str.charAt(i+1))
                cnt++;
            else
                cnt = 0;

            if (cnt > max_cnt)
            {
                max_cnt = cnt;
                max_char = str.charAt(i);
            }
        }
        return max_char;
    }

    public static void main(String[] args) {

        java.util.Scanner sc = new java.util.Scanner(System.in);
        String str = sc.nextLine();
        char []cStr = str.toCharArray();
        Arrays.sort(cStr);
        str = new String(cStr);
        System.out.println("Max occurred char:"+getMaxOccurredChar(str)+"\nCount: "+String.valueOf(max_cnt+1));
        sc.close();

    }

}

// TIme is O(n*log2(n))
// space is constant
