public class ProblemFive {

    public int getOddlyOccurredElement(int []arr, int n)
    {
        int val = 0;
        for (int i = 0; i < n; ++i)
        {
            val = val ^ arr[i];
        }
        return val;// doesn't work when we have 0 occurring odd number of times.
    }

    public static void main(String []args)
    {
        int arr[] = {10, 20, 30, 40, 30, 20, 10};
        int val = new ProblemFive().getOddlyOccurredElement(arr, arr.length);
        System.out.println("Oddly occurred Element is "+val);
    }
}

