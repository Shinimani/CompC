package Codeforces;

//import Codeforces.FastScanner;

public class cf_572_2_a {
    public static void main(String[] args) throws Exception {
        FastScanner f = new FastScanner();
        int T = f.nextInt();
//        while (T-- > 0) {
//            int n = f.nextInt();
//            int[] a = f.nextIntArray(n);
//
//        }
        String a = f.next();
        int zeros = 0;
        int ones = 0;
        for (int i = 0; i < T; i++) {
            if (a.charAt(i) == '0')
                zeros++;
            else ones++;
        }

        if (zeros == ones) {
            System.out.println("2");
            System.out.print(a.substring(0, T - 1) + " " + a.charAt(T - 1));

        } else {
            System.out.println("1");
            System.out.println(a);
        }
    }
}
