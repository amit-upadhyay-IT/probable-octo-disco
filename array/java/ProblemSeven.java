/*
 * get two elements whose sum is near to zero
 * we relate this question to the one where we need to find the elements whose sum is x, assuming x is zero here.
 */

class Elements
{
    private static int a, b;

    public static Elements getElements(int arr[], int n)
    {
        Elements e = new Elements();
        int maxValue = Integer.MAX_VALUE;
        int i = 0, j = n-1;
        while (i < j)
        {
            int sum = arr[i] + arr[j];
            if (sum < 0)
            {
                if (Math.abs(sum) < maxValue)
                {
                    maxValue = Math.abs(sum);
                    e.a = arr[i]; e.b = arr[j];
                }
                i++;
            }
            else if (sum > 0)
            {
                if (Math.abs(sum) < maxValue)
                {
                    maxValue = Math.abs(sum);
                    e.a = arr[i]; e.b = arr[j];
                }
                j--;
            }
            else // sum seems to be zero
            {
                e.a = arr[i];
                e.b = arr[j];
                break;
            }
        }
        return e;
    }

    public static void printElements(Elements e)
    {
        System.out.println("("+a+","+b+")");
    }
}

public class ProblemSeven {

    public static void main(String []args)
    {
        int []arr = {1, 12, 3, -2, 4, 5, 7, 9,};
        java.util.Arrays.sort(arr);
        Elements.printElements(Elements.getElements(arr, arr.length));

    }
}

// This problem can't be solved in O(n) even after using hashmap
