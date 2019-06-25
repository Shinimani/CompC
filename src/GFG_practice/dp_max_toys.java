package GFG_practice;

import java.util.Arrays;

public class dp_max_toys {

    public static void main(String[] args) throws Exception {
        FastScanner f = new FastScanner();
        int T = f.nextInt();
        while (T-- > 0) {
            int n = f.nextInt();
            int k = f.nextInt();

            int[] a = f.nextIntArray(n);
            int ans = 0;

            Arrays.sort(a);
            for (int i = 0; i < n; i++) {
                k-=a[i];
                if (k<0)
                    break;
                else ans++;
            }
            System.out.println(ans);

        }
    }
}
