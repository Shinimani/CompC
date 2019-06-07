package GFG_practice;

public class merge_sort {

    void merge(int arr[], int l, int m, int r)
    {
        int[] temp = new int[r-l+1];
        int i=l,j=m+1,k=0;
        while (i<=m && j<=r)
        {
            if (arr[i]<arr[j])
            {
                temp[k++] = arr[i++];
            } else temp[k++] = arr[j++];
        }
        while (i<=m)
        {
            temp[k++]=arr[i++];
        }
        while (j<=r)
        {
            temp[k++]=arr[j++];
        }
        for (int n = 0; n < r-l+1; n++) {
            arr[n+l]=temp[n];
        }

        // Your code here
    }
}
