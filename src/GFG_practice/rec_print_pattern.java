package GFG_practice;

public class rec_print_pattern {
    public static void main(String[] args) throws Exception {
        FastScanner f = new FastScanner();
        int T = f.nextInt();
        while (T-- > 0) {
            int N = f.nextInt();
//            int[] a = f.nextIntArray(N);
            System.out.println(helper(N,N));
        }
    }

    static StringBuilder helper(int k, int N)
    {
        if (k>0)
            return(new StringBuilder(k+" "+helper(k-5,N)));
        else return(helneg(k,N));
    }

    static StringBuilder helneg(int k, int N)
    {
        if (k<N)
            return((new StringBuilder(k + " " + helneg(k+5,N))));
        else return ((new StringBuilder("" + N)));
    }
}
