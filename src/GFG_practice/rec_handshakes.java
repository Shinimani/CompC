package GFG_practice;

//https://practice.geeksforgeeks.org/problems/handshakes/0
public class rec_handshakes {
    public static void main(String[] args) throws Exception {
        FastScanner f = new FastScanner();
        int T = f.nextInt();
        while (T-- > 0) {
            int N = f.nextInt();
            System.out.println(helper(N));
//            int[] a = f.nextIntArray(N);

        }
    }

    static int helper(int n)
    {
        if (n==0)
            return 0;
        else if (n==2)
            return 1;
        else
        {
            int ans = 0;
            for (int i = 2; i <= n; i+=2) {

            ans += Math.max(helper(i-2),1)*Math.max(helper(n-i),1);
            }
            return ans;
        }
    }
}
