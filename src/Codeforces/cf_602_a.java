package Codeforces;

//import Codeforces.FastScanner;

import java.util.Scanner;

public class cf_602_a {
    public static void main(String[] args) throws Exception {
        Scanner f = new Scanner(System.in);
        int T = f.nextInt();
        while (T-- > 0) {
            int n = f.nextInt();
            int[] qs = new int[n];
            for (int i = 0; i < n; i++) {
                qs[i] = f.nextInt();
            }
            int[] ans = new int[n];
            int max = qs[0];
            boolean[] occupied = new boolean[n + 1];
            occupied[max] = true;
            int index = 1;
            ans[0] = max;
            boolean flag = true;
            for (int i = 1; i < n; i++) {
                if (qs[i] > max) {
                    ans[i] = qs[i];
                    max = qs[i];
                    occupied[max] = true;
                } else {
                    while (occupied[index]) {
                        index++;
                    }
                    if (index + 1 > max) {
                        flag = false;
                    } else {
                        ans[i] = index;
                        occupied[index] = true;
                    }
                }
            }
            if (flag) {
                for (int i = 0; i < n - 1; i++) {
                    System.out.print(ans[i] + " ");
                }
                System.out.println(ans[n - 1]);
            } else System.out.println("-1");


        }
    }
}
