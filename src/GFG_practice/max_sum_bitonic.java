package GFG_practice;

public class max_sum_bitonic {

    public static void main(String[] args) throws Exception {
        FastScanner f = new FastScanner();
        int T = f.nextInt();
        while (T-- > 0) {
            int N = f.nextInt();
            int[] a = f.nextIntArray(N);
            long[] mx = new long[N];
            long[] mn = new long[N];
            mx[0] = a[0];
            for (int i = 1; i < N; i++) {
                if (a[i]>a[i-1])
                    mx[i] = a[i]+mx[i-1];
                else mx[i] = a[i];
            }

            mn[N-1] = a[N-1];

            for (int i = N-2; i >=0; i--) {
                if (a[i] > a[i+1])
                    mn[i] = mn[i+1] + a[i];
                else mn[i] = a[i];
            }

            long max_sum = Integer.MIN_VALUE;

            for (int i = 0; i < N; i++) {
                if ((mn[i]+mx[i]-a[i])>max_sum)
                    max_sum=mn[i]+mx[i]-a[i];
            }

            System.out.println(max_sum);


        }
    }
}
