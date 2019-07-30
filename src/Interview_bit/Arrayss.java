package Interview_bit;

import java.lang.reflect.Array;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class Arrayss {

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

    public ArrayList<Interval> insert(ArrayList<Interval> intervals, Interval newInterval) {

//        https://www.interviewbit.com/problems/merge-intervals/

        int s = newInterval.start;
        int e = newInterval.end;
        int i = 0;
        while (i < intervals.size() && intervals.get(i).end < s) {
            i++;
        }

        if (i == intervals.size())
            intervals.add(newInterval);
        else {
            int startofnew = Math.min(intervals.get(i).start, s);
            while (i < intervals.size() && intervals.get(i).end < e) {
                intervals.remove(i);
            }
            if (i == intervals.size()) {
                intervals.add(new Interval(startofnew, e));
            } else {
                if (intervals.get(i).start > e) {
                    Interval tob = new Interval(startofnew, e);
                    intervals.add(i, tob);
                } else {
                    int endofnew = intervals.get(i).end;
                    Interval tobeadded = new Interval(startofnew, endofnew);
                    intervals.set(i, tobeadded);
                }
            }
        }

        return intervals;


    }

    public ArrayList<Interval> merge(ArrayList<Interval> intervals) {

        Comparator<Interval> compareByStart = new Comparator<Interval>() {
            @Override
            public int compare(Interval o1, Interval o2) {
                return o1.start - o2.start;
            }
        };
        Collections.sort(intervals, compareByStart);


        ArrayList<Interval> ans = new ArrayList<>();
        Interval current = new Interval(intervals.get(0).start, intervals.get(0).end);
        for (int i = 0; i < intervals.size(); i++) {
            Interval temp = intervals.get(i);
            if (temp.start < current.end) {
                if (temp.end >= current.end) {
                    current.end = temp.end;
                    if (!ans.isEmpty() && ans.get(ans.size() - 1).end != current.end)
                        ans.add(current);
                }
            } else if (temp.start == current.end) {
                current.end = temp.end;
                ans.add(current);
                if (i != intervals.size() - 1) {
                    current = intervals.get(i + 1);
                }
            } else {
                ans.add(current);
                if (i != intervals.size() - 1) {
                    current = intervals.get(i + 1);
                }
            }
        }

        return ans;

    }

    public ArrayList<Integer> wave(ArrayList<Integer> a) {
//    https://www.interviewbit.com/problems/wave-array/
        Collections.sort(a);
        int n = a.size();
        int p, q;
        for (int i = 0; i < n / 2; i++) {
            p = a.get(2 * i);
            q = a.get(2 * i + 1);
            a.set(2 * i, q);
            a.set(2 * i + 1, p);
        }
        return a;


    }

    //    https://www.interviewbit.com/problems/largest-number/
    public String largestNumber(final List<Integer> A) {
        ArrayList<String> helper = new ArrayList<>();

        for (int i = 0; i < A.size(); i++) {
            helper.add("" + A.get(i));
        }
        Collections.sort(A);
        Collections.reverse(A);
        StringBuilder ans = new StringBuilder();

        for (int i = 0; i < A.size(); i++) {
            ans.append(helper.get(i));
        }
        return ans.toString();
        /*for (int i = 0; i < A.size(); i++) {
            ans.append(A.get(i) + "");
        }
        char[] a = ans.toString().toCharArray();
        java.util.Arrays.sort(a);
        ans = new StringBuilder(new String(a));
        ans.reverse();
        return ans.toString();*/
    }


}

class Interval {
    int start;
    int end;

    Interval() {
        start = 0;
        end = 0;
    }

    Interval(int s, int e) {
        start = s;
        end = e;
    }
}
