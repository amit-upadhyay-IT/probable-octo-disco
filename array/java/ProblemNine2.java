public class ProblemNine2 {

    private int getEquilibriumIndex(int arr[])
    {
        int sum = 0;
        // find the sum of the elements in array
        for (int i = 0; i < arr.length; ++i)
            sum = sum + arr[i];

        int leftSum = 0;
        // iterate through array and find the leftSum
        for (int i = 0; i < arr.length; ++i)
        {
            sum = sum - arr[i];
            if (sum == leftSum)
                return i;
            leftSum = leftSum + arr[i];
        }
        return -1;
    }

    public static void main(String[] args) {

        int arr[] = {-7, 1, 5, 2, -4, 3, 0};

        int index = new ProblemNine2().getEquilibriumIndex(arr);
        if (index != -1)
            System.out.println("Equilibrium index is "+index);
        else
            System.out.println("No equilibrium index");

    }

}

// time is linear
// space is constant
