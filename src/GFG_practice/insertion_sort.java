package GFG_practice;

public class insertion_sort {

    static void insert(int arr[], int k)

    {
        int kk = arr[k];
        int i = k-1;
        while (i>=0 && arr[i] > kk)
        {
            arr[i+1] = arr[i--];
        }
        arr[++i] = kk;

    }
}
