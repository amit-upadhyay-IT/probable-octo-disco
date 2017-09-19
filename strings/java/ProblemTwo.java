public class ProblemTwo {

    public static void main(String[] args) {

        StringBuilder str = new StringBuilder("gaadbbaaggaiij");

        str = new ProblemTwo().removeDuplicates(str);
        System.out.println(str);

    }

    private StringBuilder removeDuplicates(StringBuilder str)
    {
        int []hash = new int[256];
        int j = 0;
        for (int i = 0; i < str.length(); ++i)
        {
            if (hash[str.charAt(i)] == 0)// first time occurrence
            {
                hash[str.charAt(i)] = 1;
                str.insert(j, str.charAt(i));
                j++;
            }
        }
        str = str.delete(j, str.length());
        return str;
    }
}
// time is linear and space is constant
