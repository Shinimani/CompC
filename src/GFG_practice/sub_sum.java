package GFG_practice;
public class sub_sum {
    public static void main(String[] args) {

        FastScanner f = new FastScanner();
        int T = f.nextInt();
        while(T-->0)
        {
            int N = f.nextInt();
            int S = f.nextInt();
            int[] a = new int[N];
            int k = 0;
            int ans = -1;
            boolean fl = true;
            int[] num = f.nextIntArray(N);

            for (int i = 0; i < N; i++) {
//                int num = f.nextInt();
                if (num[i] == S)
                {
                    k=i;
                    ans=i;
                    fl = false;
                    break;
                }


                for (int j = k; j < i; j++) {
                    a[j]+=num[i];
                    if (a[j]==S){
                        k=j;
                        ans = i;
                        fl = false;
                        break;
                    } else if (a[j]>S)
                    {
                        k = j;
                    }
                }

                if (!fl) break;
                a[i] = num[i];

            }
            if (ans == -1) System.out.println("-1"); else System.out.println(++k + " " + ++ans);
        }
    }

//    https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0
}


