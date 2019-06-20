package GFG_practice;

public class dp_minoperations {

    public static void main(String[] args) throws Exception {
        FastScanner f = new FastScanner();
        int T = f.nextInt();
        while (T-- > 0) {
            int n = f.nextInt();
            int ans = 0;
            while (n!=0)
            {
                if (n%2==0)
                {
                    ans++;
                    n= n/2;
                }
                else
                {
                    ans++;
                    n--;
                }
            }
            System.out.println(ans);;


//            int[] a = f.nextIntArray(N);

        }
    }

}
