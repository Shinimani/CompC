package Interview_bit;

import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;

public class Arrays {

    public ArrayList<Integer> repeatedNumber(final List<Integer> A) {
//        https://www.interviewbit.com/problems/repeat-and-missing-number-array/



        /*
        BigInteger sum = new BigInteger("0");
        BigInteger sumsq = new BigInteger("0");
        BigInteger num;
        int n = A.size();
        for (int i = 0; i < n; i++) {
            num = (BigInteger.valueOf((long)A.get(i)));
            sum = sum.add(num);
            sumsq = sumsq.add(num.multiply(num));
        }
        sum = sum.subtract ((BigInteger.valueOf((long)(n*(n+1)/2))));
        sumsq = sumsq.subtract ((BigInteger.valueOf((long)(n*(n+1)*((2*n)+1)/6))));
        sumsq = sumsq.divide(sum);
        ArrayList<Integer> ans = new ArrayList<>();
        ans.add((sum.add(sumsq)).divide(BigInteger.valueOf((long)2)).longValue());
        ans.add((sumsq.subtract(sum)).divide(BigInteger.valueOf((long)2)).longValue());
        return ans;
//        ArrayList<Lo>
        */
        long sum = 0;
        long sumsq = 0;
        int n = A.size();
        //Bhot zyada typecasting!
        for (int i = 0; i < n; i++) {
            long num = (long) A.get(i);
            sum = sum + num - (long) (i + 1);
            sumsq = sumsq + (num * num) - (long) (i + 1) * (i + 1);
        }
//        sum -= (long)(n*(n+1)/2);
//        sumsq -= (long) (n*(n+1)*((2*n)+1)/6);
        sumsq = sumsq / sum;
        ArrayList<Integer> ans = new ArrayList<>();
        ans.add((int) (sum + sumsq) / 2);
        ans.add((int) (sumsq - sum) / 2);
        return ans;


    }
}
