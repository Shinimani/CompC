package Codeforces;

import java.util.ArrayList;

public class cf_572_2_e {
    //    https://codeforces.com/contest/1189/problem/E
    public static void main(String[] args) {
        FastScanner f = new FastScanner();
        int n = f.nextInt();
        int p = f.nextInt();
        int k = f.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = f.nextInt();
        }

    }

    static ArrayList<Integer> factors(int k) {
        if (k == 0)
            return null;
        else {
            ArrayList<Integer> a = new ArrayList<Integer>();
            a.add(1);
            for (int i = 0; i < Math.sqrt(k); i++) {

            }
        }
    }

}
