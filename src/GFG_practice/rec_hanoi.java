package GFG_practice;

public class rec_hanoi {

    public static void main(String[] args) throws Exception {
        FastScanner f = new FastScanner();
        int T = f.nextInt();
        while (T-- > 0) {
            int N = f.nextInt();
//            int[] a = f.nextIntArray(N);
            System.out.println(helper(N,1,3,2));
            System.out.println(Math.pow(2,N) - 1);


        }
    }

    static StringBuilder helper(int n, int ra, int rb, int rc)
    {
        if (n==1)
            return(new StringBuilder("move disk 1 from rod "+ ra +" to rod "+rb + "\n"));
        else
            return(new StringBuilder(helper(n-1,ra,rc,rb) + "move disk "+n+" from rod "+ ra +" to rod "+rb + "\n"+ helper(n-1,rc,rb,ra)));
    }

}
