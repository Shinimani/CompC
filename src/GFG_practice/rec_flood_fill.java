package GFG_practice;

public class rec_flood_fill {

    public static void main(String[] args) throws Exception {
        FastScanner f = new FastScanner();
        int T = f.nextInt();
        while (T-- > 0) {
            int n = f.nextInt();
            int m = f.nextInt();
            int[][] a = new int[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    a[i][j] = f.nextInt();
                }
//                a[i] = f.nextIntArray(m);
            }
            int y = f.nextInt();
            int x = f.nextInt();
            int k = f.nextInt();
            int num = a[y][x];
            helper(a, y, x, k, num);
//                        System.out.println(a[0][0]);
            System.out.println(printarray(a));


        }
    }

    static StringBuilder printarray(int[][] a)
    {
        StringBuilder ans = new StringBuilder();
        int n = a.length;
        int m = a[0].length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans.append(a[i][j] + " ");
            }
//                a[i] = f.nextIntArray(m);
        }
        ans.deleteCharAt(ans.length()-1);
        return ans;
//
    }

    static void helper(int[][] a, int locy, int locx, int numtobemade, int numtobechecked) {
        int y = a.length;
        int x = a[0].length;
        if (a[locy][locx] != numtobechecked)
            return;
        else {
            a[locy][locx] = numtobemade;
            if (locx > 0)
                helper(a, locy, locx - 1, numtobemade, numtobechecked);
            if (locy > 0)
                helper(a, locy - 1, locx, numtobemade, numtobechecked);
            if (locx < x - 1)
                helper(a, locy, locx + 1, numtobemade, numtobechecked);
            if (locy < y - 1)
                helper(a, locy + 1, locx, numtobemade, numtobechecked);
        }
    }
}


