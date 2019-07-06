package Codeforces;

import java.util.Arrays;

public class cf_572_2_b {
//    https://codeforces.com/contest/1189/problem/B


    public static void main(String[] args) throws Exception {
        FastScanner f = new FastScanner();
//        int T = f.nextInt();
//        while (T-- > 0) {
        int n = f.nextInt();
        int[] a = f.nextIntArray(n);
        Arrays.sort(a);
        int k = a[n - 1] - a[n - 2];
        int pos = Arrays.binarySearch(a, k);
        if (pos < 0) {
            if (-pos > n - 2)
                System.out.println("NO");
            else {
                pos = -pos;
                int temp = a[pos];
                for (int i = pos; i > 0; i--) {
                    a[i] = a[i - 1];
                }
                a[0] = temp;
                System.out.println("YES");
                StringBuilder ans = new StringBuilder();
                for (int i = 0; i < n; i++) {
                    ans.append(a[i] + " ");
                }
                ans.deleteCharAt(ans.length() - 1);
                System.out.println(ans);
            }
        } else {
            pos++;
            if (pos >= n - 2)
                System.out.println("NO");
            else {
                int temp = a[pos];
                for (int i = pos; i > 0; i--) {
                    a[i] = a[i - 1];
                }
                a[0] = temp;
                System.out.println("YES");
                StringBuilder ans = new StringBuilder();
                for (int i = 0; i < n; i++) {
                    ans.append(a[i] + " ");
                }
                ans.deleteCharAt(ans.length() - 1);
                System.out.println(ans);


            }
        }

//        }
    }
}
