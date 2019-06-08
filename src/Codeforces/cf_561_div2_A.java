package Codeforces;

import java.util.Scanner;

public class cf_561_div2_A {

    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int[] arr = new int[26];

        for (int i = 0; i<n;i++)
        {
            String temp = s.next();
            char c = temp.charAt(0);
            int asc = (int) c;
            asc = asc-97;
            arr[asc]++;
        }
        int ans = 0;

        for (int i = 0;i<26;i++)
        {
            int m = arr[i];
            int k = (m/2);
            int l = m-k;
            ans = ans + (k*(k-1)/2) + (l*(l-1)/2);
        }
        System.out.println(ans);


    }
}
