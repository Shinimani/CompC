package GFG_practice;

public class unique_paths {
    static int path(int a, int b)
    {
        if (a<2 || b<2)
            return 1;
        else return path(a-1,b) + path(a,b-1);
    }


    public static void main(String[] args) throws Exception {
        FastScanner f = new FastScanner();
        int T = f.nextInt();
        while (T-- > 0) {
//            int N = f.nextInt();
            System.out.println(path(f.nextInt(),f.nextInt()));

        }
    }
}
