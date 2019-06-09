package GFG_practice;

//import java.io.BufferedInputStream;
//import java.io.File;
//import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.Collections;

public class segregate_even_odd {

//    https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-numbers/0/?ref=self

    public static void main(String[] args) {

        FastScanner f = new FastScanner();
        int T = f.nextInt();

        while (T-- > 0) {
            int N = f.nextInt();
            int[] inp = f.nextIntArray(N);
//            int[] even = new int[N];
//            int[] odd = new int[N];
            ArrayList<Integer> even = new ArrayList<Integer>();
            ArrayList<Integer> odd = new ArrayList<Integer>();
            int k = 0, l = 0;
            for (int i = 0; i < N; i++) {
                if (inp[i] % 2 == 0) {
                    even.add(inp[i]);
                } else odd.add(inp[i]);
            }

            Collections.sort(even);
            Collections.sort(odd);

            StringBuffer ans = new StringBuffer();
//            ans.
            for (int i = 0; i < even.size(); i++) {
                ans.append(even.get(i) + " ");
            }

            for (int i = 0; i < odd.size(); i++) {
                ans.append(odd.get(i) + " ");
            }

            ans.deleteCharAt(ans.length() - 1);
            System.out.println(ans);
        }

    }
}