import java.sql.SQLOutput;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class cf_561_div2_C {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i<n;i++)
        {
            arr[i] = Math.abs(s.nextInt());
        }
        long ans = 0;
        Arrays.sort(arr);

        for (int i = 0; i < n; i++) {
//            int k =bins(arr,i,n,arr[i]);
//            System.out.println(k);
            ans += bins(arr,i,n,arr[i]) - i;
        }

        System.out.println(ans);

//        int ans = 0;


    }

    static int bins(int[] arr, int p, int q, int k)
    {
        k = 2*k;
        int ans = 0;
        boolean f = true;
        while (f)
        {
            if (arr[ans] == k)
            {
                if (ans + 1 < q && arr[ans+1] == k)
                    ans = ans+1;
                f = false;
            } else if (arr[ans] > k)
            {
                if (ans - 1 >=p && arr[ans-1] <= k )
                {
                    ans = ans-1;
                    f = false;
                } else if (ans - 1 == p)
                {
                    ans= p;
                    f = false;
                }
                else
                {
                    q = ans;
                    ans = (p+q)/2;
                }
            } else if (arr[ans] < k)
            {
                if (ans + 1 < q && arr[ans + 1] > k)
                {
                    f = false;
                } else if (ans + 1 < q && arr[ans + 1] == k)
                    ans = ans + 1;
                else if (ans +1 == q-1)
                {
                    ans = q-1;
                    f = false;
                }
                else if (ans == q-1)
                {
                    f= false;
                } else
                {
                    p = ans;
                    ans = (p+q)/2;
                }

            }
        }
        return ans;
    }



}
