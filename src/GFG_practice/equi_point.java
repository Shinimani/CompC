package GFG_practice;
//https://practice.geeksforgeeks.org/problems/equilibrium-point/0/?ref=self
public class equi_point {

    public static void main(String[] args) throws Exception {
        FastScanner f = new FastScanner();
        int T = f.nextInt();
        while (T-- > 0) {
            int N = f.nextInt();
            int[] a = f.nextIntArray(N);
            int totsum = 0;
//            int[] tillsum = new int[N];
            for (int i = 0; i < N; i++) {
                totsum +=a[i];
            }

            int sum=0;
            int ans = -2;
            for (int i = 0; i < N; i++) {
                if ((totsum-a[i]) == sum*2)
                {
                    ans = i;
                    break;
                }
                sum+=a[i];
            }



            System.out.println(++ans);


        }
    }
}
