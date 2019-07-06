package Codeforces;
/*

import java.util.ArrayList;
import java.util.Arrays;

public class cf_572_2_c extends ArrayList<Integer>{
//    https://codeforces.com/contest/1189/problem/C
public static void main(String[] args) {
    FastScanner f = new FastScanner();
    int n = f.nextInt();
    int[] a = f.nextIntArray(n);
    int q = f.nextInt();
    while (q-->0)
    {
        int l = f.nextInt()-1;
        int r = f.nextInt()-1;

        cf_572_2_c working = new cf_572_2_c();
        for (int i = l; i <=r ; i++) {
            working.add(a[i]);
        }
        int ans = 0;

        while (working.size() != 1)
        {
            int newn = working.size();
            for (int i = 0; i < newn; i++) {
                if (i%2 != 0)
                {
                    int k = working.get(i) + working.get(i-1);
                    if (k>=10)
                    {
                        ans++;
                        k-=10;
                    }
                    working.set((i-1)/2,k);
                }
            }
            working.removeRange(newn/2,newn);
        }
        System.out.println(ans);

    }
}
}
*/

//the above code works, but takes time
//trying with Stringbuilder

/*

public class cf_572_2_c {
    public static void main(String[] args) {
        FastScanner f = new FastScanner();
        int n = f.nextInt();
        int[] a = f.nextIntArray(n);
        int q = f.nextInt();
        while (q-- > 0) {
            int l = f.nextInt() - 1;
            int r = f.nextInt() - 1;
            StringBuilder s = new StringBuilder();
            for (int i = l; i <=r ; i++) {
                s.append(a[i]);
            }
            int ans = 0;

            while (s.length()!=1)
            {
                int newn = s.length();
                for (int i = 0; i < newn; i++) {
                    if (i%2 != 0)
                    {

                        int k = Character.getNumericValue(s.charAt(i)) + Character.getNumericValue(s.charAt(i-1));
                        if (k>=10)
                        {
                            ans++;
                            k-=10;
                        }

                        s.setCharAt((i-1)/2,(char)(k+'0'));
                    }
                }
                s.setLength(newn/2);
            }

            System.out.println(ans);

        }
    }


}*/

//Stringbuilder also slow :(

//very good algorithm


public class cf_572_2_c {
    public static void main(String[] args) {
        FastScanner f = new FastScanner();
        int n = f.nextInt();
        int a = 0;
        int[] ar = new int[n + 1];
        ar[0] = 0;
        for (int i = 1; i < n + 1; i++) {
            ar[i] = a += f.nextInt();
        }
//        int[] a = f.nextIntArray(n);
        int q = f.nextInt();
        while (q-- > 0) {
            int l = f.nextInt();
            int r = f.nextInt();
            int ans = ar[r] - ar[l - 1];

//            for (int i = l; i <=r ; i++) {
//                ans+=a[i];
//            }

            ans /= 10;
            System.out.println(ans);


        }
    }


}

