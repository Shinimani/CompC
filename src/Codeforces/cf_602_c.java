package Codeforces;

import java.util.Scanner;

public class cf_602_c {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int T = s.nextInt();
        int n;
        int k;
        char[] temp;
        while(T-->0)
        {
            n = s.nextInt();
            k = s.nextInt();
            temp = s.next().toCharArray();
            int count = 1;
            int i =0;
            char[] ans= new char[n];

            while(i<2*(k-1))
            {
                ans[i]='(';
                ans[i+1]=')';
                i+=2;
//                count++;
            }
            count = n/2 - k + 1;
            while(count-->0)
            {
                ans[i]='(';
            }
            count = n/2 - k + 1;
            while(count-->0)
            {
                ans[i]=')';
            }

            for (int j = 0; j <n; j++) {
                
            }


        }

    }
}
