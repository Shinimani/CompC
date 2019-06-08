package Codeforces;

import java.util.Scanner;

public class cf_561_div2_B {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int k = s.nextInt();
        boolean f = false;
        for (int n = 5; n<(Math.sqrt(k) + 1);n++)
        {
            if ((k/n) < 5)
            {
                break;
            }
            if (k%n == 0)
            {
                f = true;
                int m = k/n;
                StringBuilder helper = new StringBuilder();
                while (helper.length()< m + 5)
                {
                    helper.append("aeiou");
                }
//                int s = 0;
                StringBuilder ans = new StringBuilder();
                for (int i = 0; i< n ;i++)
                {
                    int st = i%5;
                    ans = ans.append(helper.substring(st,st + m));
                }
                System.out.println(ans);
                break;
//                while (helper.l)
            }
        }

        if (!f) System.out.println("-1");
    }
}
