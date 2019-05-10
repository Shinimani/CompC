import java.util.ArrayList;
import java.util.Scanner;

public class max_not_adjacent
{

    // Driver program to test above functions
    public static void main(String[] args)
    {
        Scanner s = new Scanner(System.in);
        int T = s.nextInt();
        for (int k = 0; k < T; k++) {
            int n = s.nextInt();
            int[] arr = new int[n];
            for (int j = 0; j < n; j++) {
                arr[j] = s.nextInt();
            }


            int incl = arr[0];
            int excl = 0;
            int excl_new;
            int i;
            int prev = incl;

            ArrayList<Integer> store = new ArrayList<Integer>();


            for (i = 1; i < n; i++)
            {
                /* current max excluding i */
                if (incl > excl)
                {
                    excl_new = incl;
                    store.add(prev);
                }
                else
                {
                    excl_new = excl;
                }

                /* current max including i */
                incl = excl + arr[i];
                excl = excl_new;
                prev = arr[i];
            }

            /* return max of incl and excl */
            if (incl > excl)
            {
                excl_new = incl;
                store.add(prev);
            }
            else
            {
                excl_new = excl;
            }

            String ans = "";
            for (int j = 0; j < store.size() ; j++) {
                ans = store.get(j) + ans;
            }
            System.out.println(ans);



        }

    }
}