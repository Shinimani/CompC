package GFG_practice;

public class longest_increasing {
    public static void main(String[] args) throws Exception {
        FastScanner f = new FastScanner();
        int T = f.nextInt();
        while (T-- > 0) {
            int N = f.nextInt();
            int[] a = f.nextIntArray(N);
            int total_long = 0;
            int temp_long=0;
            int last = a[0];

            for (int i = 0; i < N; i++) {
                if (a[i]>=last)
                {
                    temp_long++;
                    if (temp_long>total_long)
                        total_long=temp_long;
                } else temp_long=1;
                last = a[i];
            }
            System.out.println(total_long);

        }
    }

}
