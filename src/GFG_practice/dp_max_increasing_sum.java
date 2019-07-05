package GFG_practice;

//https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence/0
public class dp_max_increasing_sum {

    public static void main(String[] args) throws Exception {
        FastScanner f = new FastScanner();
        int T = f.nextInt();
        while (T-- > 0) {
            int n = f.nextInt();
            int[] a = f.nextIntArray(n);
//            System.out.println(helper(a[0],a,1,));
//            int ans = Math.max(helper())
            System.out.println(helper(0, a, 0, 0));

        }
    }
//
//    static int helper2(int prev, int[] a, int index) {
//
//    }


    static int helper(int last, int[] a, int index, int lastSum) {
//        int ans = lastS;
        if (index == a.length - 1) {
            if (a[index] > last) {
                return lastSum + a[index];
            } else return lastSum;
        } else {
            if (a[index] > last) {
                return Math.max(helper(last, a, index + 1, lastSum), helper(a[index], a, index + 1, lastSum + a[index]));
            } else return helper(last, a, index + 1, lastSum);
        }
//        return lastSum;
    }
}
