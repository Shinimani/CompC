package GFG_practice;

public class quick_sort {

    int partition (int arr[], int low, int high)
    {
        int pi = arr[high];
//        int firstbig ;
        int ex = low - 1 ;
//        boolean firstf = false,secondf = false;
        for (int i = low; i < high; i++) {
            if (arr[i] <= pi)
            {
                ex++;
                int temp = arr[ex];
                arr[ex] = arr[i];
                arr[i] = temp;

            }
        }

        ex++;
        int temp = arr[ex];
        arr[ex] = arr[high];
        arr[high] = temp;


//        while()
        return ex;
    }
    void sort(int arr[], int low, int high)
    {
        if (low < high)
        {
			/* pi is partitioning index, arr[pi] is
			now at right place */
            int pi = partition(arr, low, high);

            // Recursively sort elements before
            // partition and after partition
            sort(arr, low, pi-1);
            sort(arr, pi+1, high);
        }
    }
    static void printArray(int arr[])
    {
        int n = arr.length;
        for (int i=0; i<n; ++i)
            System.out.print(arr[i]+" ");
        System.out.println();
    }
    public static void main(String args[])
    {
        int arr[] = {10, 7, 8, 9, 1, 5};
        int n = arr.length;
        printArray(arr);

        quick_sort ob = new quick_sort();
        ob.sort(arr, 0, n-1);

        System.out.println("sorted array");
        printArray(arr);
    }


}
