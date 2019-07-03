package GFG_practice;

import java.util.Arrays;

public class count_the_triplets {

//    https://practice.geeksforgeeks.org/problems/count-the-triplets/0


    public static void main(String[] args) throws Exception {
        FastScanner f = new FastScanner();
        int T = f.nextInt();
        while (T-- > 0) {
            int n = f.nextInt();
            int[] a = f.nextIntArray(n);
            Arrays.sort(a);
            int ans = 0;
            for (int i = 0; i < n; i++) {
//                int k = a[i];
                for (int j = i + 1; j < n; j++) {
                    if (Arrays.binarySearch(a, a[i] + a[j]) >= 0) ans++;
                }
            }

            System.out.println(ans);

        }
    }
}
