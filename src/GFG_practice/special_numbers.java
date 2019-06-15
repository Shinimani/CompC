package GFG_practice;

public class special_numbers {

    public static void main(String[] args) throws Exception {
        FastScanner f = new FastScanner();
        int T = f.nextInt();
        while (T-- > 0) {
            int N = f.nextInt();
            N--;

            int a = 0, ans = 0;
            while(six(a) < N)
            {
                int h = N % six(a+1);
                h = h/six(a);
                ans += h*ten(a);
                a++;
            }

            System.out.println(ans);
        }
    }

    static int six(int x)
    {
        return (int) Math.pow(6,x);
    }

    static int ten(int x)
    {
        return (int) Math.pow(10,x);
    }
}
