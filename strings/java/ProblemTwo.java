public class ProblemTwo {

    private void removeDuplicates(char []cStr)
    {
        int hash[] = new int[256];// all values are initialized to 0
        int j = 0;// for filling up the cStr
        for (int i = 0; i < cStr.length; ++i)
        {
            if (hash[cStr[i]] == 0)
            {
                hash[cStr[i]] = 1;
                cStr[j++] = cStr[i];
            }
        }
        cStr[j] = '\0';
        System.out.println(cStr);
    }

    public static void main(String[] args) {
        //StringBuilder str = new StringBuilder("gaadbbaaggaiij");
        String str = new String("gaadbbaaggaiij");
        char []cStr = str.toCharArray();
        new ProblemTwo().removeDuplicates(cStr);

    }

}

