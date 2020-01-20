package GFG_practice;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class ICPC192 {


    public static boolean[] helper(int k) {
        boolean[] ans = new boolean[30];
        for (int i = 0; i < 30; i++) {
            int temp = 1 << i;
            temp = temp & k;
            if (temp > 0) ans[i] = true;
            else ans[i] = false;
        }
        return ans;
    }

    public static int counter(int[] count) {
        int ans = 0;
        for (int i = 0; i < 30; i++) {
            if (count[i] > 0) {
                ans += 1 << i;
            }
        }
        return ans;
    }

    public static void main(String[] args) throws Exception {
        Scanner f = new Scanner(System.in);
        int T = f.nextInt();
        while (T-- > 0) {
            int n = f.nextInt();

            boolean[][] loc = new boolean[n][30];

            int[] count = new int[30];

            for (int j = 0; j < 30; j++) {
                count[j] = 0;
            }

            int orr = 0;

            boolean[] taken = new boolean[n];

            int[] numbers = new int[n];

            for (int i = 0; i < n; i++) {
                numbers[i] = f.nextInt();
                taken[i] = true;
            }

            Arrays.sort(numbers);

            for (int i = 0; i < n; i++) {
                int k = numbers[i];
                orr = k | orr;
                loc[i] = helper(k);
                for (int j = 0; j < 30; j++) {
                    if (loc[i][j]) count[j]++;
                }
            }

            int[] ans = new int[n];
            int last = 0;


            for (int i = 0; i < n; i++) {

                int maxIndex = 0;
                int maxHa = 0;

                for (int j = 0; j < n; j++) {
                    if (taken[j]) {
                        last = j;
                        int[] temp = new int[30];
                        for (int k = 0; k < 30; k++) {
                            if (loc[j][k]) temp[k] = count[k] - 1;
                            else temp[k] = count[k];
                        }

                        int temp1 = counter(temp);
                        if (maxHa < temp1) {
                            maxHa = temp1;
                            maxIndex = j;
                        }

                    }
                }
                orr += maxHa;
                taken[maxIndex] = false;
                ans[i] = maxIndex;
                for (int j = 0; j < 30; j++) {
                    if (loc[maxIndex][j]) count[j]--;
                }

            }


            System.out.println(orr);
            for (int i = 0; i < n - 1; i++) {
                System.out.print(ans[i] + " ");
            }
            System.out.print(last);
        }
    }
}
