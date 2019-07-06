package Codeforces;

//import java.util.ArrayList;

//https://codeforces.com/contest/1189/problem/D1
public class cf_572_2_d1 {

    public static void main(String[] args) throws Exception {
        FastScanner f = new FastScanner();
//        int T = f.nextInt();
//        while (T-- > 0) {
//            int n = f.nextInt();
//            int[] a = f.nextIntArray(n);
//
//        }
        int n = f.nextInt();
        int[] a = new int[n + 1];
        for (int i = 0; i < n + 1; i++) {
            a[i] = 0;
        }
        for (int i = 0; i < n - 1; i++) {
            a[f.nextInt()]++;
            a[f.nextInt()]++;
        }

        boolean flag = true;

        for (int i = 1; i < n + 1; i++) {
            if (a[i] == 2) {
                flag = false;
                break;
            }
        }

        if (flag)
            System.out.println("YES");
        else
            System.out.println("NO");


        /*
        ArrayList<Integer>[] a = new ArrayList[n+1];
        for (int i = 0; i < n+1; i++) {
            a[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < n-1; i++) {
            int u = f.nextInt();
            int v = f.nextInt();
            a[u].add(v);
            a[v].add(u);
        }
        boolean flag = true;

        if (n==2)
            System.out.println("YES");
        else if (n==3)
            System.out.println("NO");
        else
        {
            for (int i = 1; i < n+1; i++) {
                if (a[i].size()==1)
                {
                    int parent = a[i].get(0);
                    if (a[parent].size()==2)
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag)
                System.out.println("YES");
            else
                System.out.println("NO");

        }*/


    }

}
