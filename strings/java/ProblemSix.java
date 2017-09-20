public class ProblemSix {

    private char[] str;

    private ProblemSix()
    {
        str = new String("MADAM").toCharArray();
    }

    private boolean checkPalindrome(int begin, int end)// two indices inbetween which we need to check if its palindrome or not.
    {
        while (begin < end)
        {
            if (str[begin] != str[end])
                return false;
            begin++;
            end--;
        }
        return true;
    }

    public static void main(String[] args) {

        ProblemSix obj = new ProblemSix();
        boolean val = obj.checkPalindrome(0, obj.str.length-1);
        if (val)
            System.out.println("YES");
        else
            System.out.println("NO");
    }

}

// time is linear and space is constant

