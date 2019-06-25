package GFG_practice;

public class dp_max_substring {
    public static void main(String[] args) throws Exception {
        FastScanner f = new FastScanner();
        int T = f.nextInt();
        while (T-- > 0) {
            int n = f.nextInt();
            int m = f.nextInt();
            String na = f.next();
            String ma = f.next();
            int[][] a = new int[n+1][m+1];
            int ans = 0;
            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= m; j++) {
                    if (i==0||j==0)
                        a[i][j] = 0;
                    else if (na.charAt(i-1)==ma.charAt(j-1)) {
                        a[i][j] = a[i - 1][j - 1] + 1;
                        ans = Math.max(ans, a[i][j]);
                    } else a[i][j]=0;
                }
            }
            System.out.println(ans);

        }
    }

//    static int lCS(char[] a, char[] b, )
}
