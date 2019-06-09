package GFG_practice;

public class kadanes {
    public static void main(String[] args) throws Exception {
        FastScanner f = new FastScanner();
        int T = f.nextInt();
        while (T-- > 0) {
            int N = f.nextInt();
            int[] a = f.nextIntArray(N);
            int max_till_here=0;
            int max_overall=0;
            int max_num = a[0];
            for (int i = 0; i < N; i++) {
                max_till_here += a[i];
                if (max_till_here<0) max_till_here=0;
                if (max_overall<max_till_here)
                    max_overall=max_till_here;
                if(max_num<a[i])
                    max_num=a[i];
            }




        }
    }

}
