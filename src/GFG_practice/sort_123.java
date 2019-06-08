package GFG_practice;

//https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s/0/?ref=self
public class sort_123 {
    public static void main(String[] args) throws Exception {
        FastScanner f = new FastScanner();
        int T = f.nextInt();
        while(T-->0) {
            int N = f.nextInt();
            int[] a = f.nextIntArray(N);
            int a0 = 0,a1=0,a2=0;
            for (int i = 0; i < N; i++) {
                if(a[i]==0)
                    a0++;
                else if (a[i]==1)
                    a1++;
                else a2++;
            }
            StringBuffer s = new StringBuffer();
            while (a0-->0)
                s = s.append("0 ");
            while (a1-->0)
                s = s.append("1 ");
            while (a2-->0)
                s = s.append("2 ");

            s.deleteCharAt(s.length()-1);
            System.out.println(s);





        }
    }
}
