package GFG_practice;

import java.util.Arrays;

//https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence/0/?ref=self
public class longest_conseq_subseq {

    public static void main(String[] args) throws Exception {
        FastScanner f = new FastScanner();
        int T = f.nextInt();
        while (T-- > 0) {
            int N = f.nextInt();
            int[] a = f.nextIntArray(N);
            Arrays.sort(a);
            int atill = 1, amax = 1, prev = a[0];
            for (int i = 1; i < N; i++) {
                if (a[i]==a[i-1]+1)
                {
//                    prev = a[i];
                    atill++;
                    if (atill>amax)
                        amax=atill;
                } else
                {
                    atill=1;
//                    prev=a[i];
                }
            }
            System.out.println(amax);

        }
    }
}
