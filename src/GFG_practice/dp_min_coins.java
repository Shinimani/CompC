package GFG_practice;

public class dp_min_coins {
    public static void main(String[] args) throws Exception {
        FastScanner f = new FastScanner();
        int T = f.nextInt();
        int[] coins = new int[]{1,2,5,10,20,50,100,200,500,2000};
        while (T-- > 0) {
            int n = f.nextInt();
            int i = 9;
            int ans = 0;
            StringBuilder anss = new StringBuilder();
            while (n>0)
            {
                while (n>=coins[i])
                {
                    n-=coins[i];
                    anss.append((coins[i] + " "));
                    ans++;
                }
                i--;
            }

            System.out.println(anss.deleteCharAt(anss.length()-1));



        }
    }
}
