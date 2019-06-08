package GFG_practice;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class sort_qs {
    public static void main(String[] args) throws Exception{
        InputStreamReader ir = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(ir);

            int T = Integer.parseInt(br.readLine());
            while (T-->0)
        {
            int N = Integer.parseInt(br.readLine());
            String[] inp = br.readLine().split(" ");
            int[] arr = new int[N];
            for (int i = 0; i < N; i++) {
                arr[i] = Integer.parseInt(inp[i]);
            }
            quicksort q = new quicksort();
            q.qs(arr,0,N-1);
            System.out.println(q.arrprint(arr));



        }

    }


}

class quicksort
{
    void qs(int[] arr, int l, int r)
    {
        if (l<r)
        {
            int p = partition(arr, l, r);
//            System.out.println(p);
            qs(arr, l, p-1);
            qs(arr, p+1, r);
        }
    }

    int partition(int[] arr, int l, int r)
    {
        int ex = l-1;
        for (int i = l; i < r; i++) {
            if (arr[r]>arr[i])
            {
                ex++;
                int t = arr[ex];
                arr[ex] = arr[i];
                arr[i] = t;
            }
        }
        ex++;
        int t = arr[r];
        arr[r]=arr[ex];
        arr[ex]=t;
        return ex;
    }

    String arrprint(int[] arr)
    {
        String ans = "";
        for (int i = 0; i < arr.length; i++) {
            ans = ans + arr[i] + " ";
        }
        ans = ans.substring(0,ans.length()-1);
        return ans;
    }
}
