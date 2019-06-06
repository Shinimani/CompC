package GFG_practice;

public class bin_search {
    public static void main(String[] args) {
        int[] A = {1,2,3,4,5};
        System.out.println(bin_search_loop(A,0,4,3));
    }


    static int bin_search(int A[], int left, int right,  int k) {

// 	 int ans = -1;
        if (A[left] == A[right]) {
            if (A[left] == k)
                return left;
            else return -1;
        } else if (k<A[left] || k>A[right])
            return -1;
        else if (right == (left + 1))
        {
            if (k == A[left]) return left;
            else if (k==A[right]) return right;
            else return -1;
        }
        else
        {
            if (k>A[(left+right)/2])
                return bin_search(A,(left+right)/2,right,k);
            else return bin_search(A,left,(left+right)/2,k);
        }
//        while (left)

        // Your code here
    }

    static int bin_search_loop(int A[], int left, int right, int k)
    {
        if (k<A[left] || k>A[right])
            return -1;
        else
        {
            while (left < right -1)
            {
                int temp = (left+right)/2;
                if (k < A[temp])
                    right = temp;
                else left = temp;
            }
            if (k==A[left]) return left;
            else if (k==A[right]) return right;
            else return -1;

        }
    }
}
