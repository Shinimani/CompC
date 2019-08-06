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
        int k = 0;

        for (int i = 0; i < A.size(); i++) {
            helper.add("" + A.get(i));
            if (A.get(i) == 0) k++;
        }
        if (k == A.size())
            return "0";
        Collections.sort(helper, new compareforLargestnumber());
        Collections.reverse(helper);
        StringBuilder s = new StringBuilder();

        for (int i = 0; i < helper.size(); i++) {
            s.append(helper.get(i));
        }

        return s.toString();
    }


    public int titleToNumber(String A) {

        int ans = 0;
        for (int i = 0; i < A.length(); i++) {
            ans += (26 ^ (A.length() - 1 - i)) * ((int) A.charAt(i) - 'A' + 1);
        }
        return ans;
    }

    //    https://www.interviewbit.com/problems/palindrome-integer/
    public int isPalindrome(int a) {
        if (a < 0) return 0;
        String x = "" + a;
        int l = x.length();
        for (int i = 0; i < l; i++) {
            if (x.charAt(i) != x.charAt(l - 1 - i)) return 0;
        }

        return 1;
    }


    //    https://www.interviewbit.com/problems/reverse-integer/
    public int reverse(int A) {
        boolean neg = A < 0;
        A = Math.abs(A);
        if (A > Math.pow(2, 32)) return 0;
        StringBuilder s = new StringBuilder("" + A);
        s.reverse();
        if (s.compareTo(new StringBuilder("2147483647")) > 0) return 0;
        int x = Integer.parseInt(s.toString());
        if (neg)
            return -x;
        else return x;

    }

    public ArrayList<Integer> maxset(ArrayList<Integer> a) {
        ArrayList<Integer> ans = new ArrayList<Integer>();
        int maxsum = 0;
        ArrayList<Integer> temp = new ArrayList<Integer>();
        int sum = 0;

        for (int i = 0; i < a.size(); i++) {
            int t = a.get(i);
            if (t >= 0) {
                temp.add(t);
                sum += t;
                if (sum > maxsum) {
                    ans = shift(temp);
                    maxsum = sum;
                } else if (sum == maxsum) {
                    if (ans.size() < temp.size())
                        ans.clear();
                    ans = shift(temp);
                }
            } else temp.clear();
        }
        return ans;
    }

    public ArrayList<Integer> shift(ArrayList<Integer> a) {

        ArrayList<Integer> ans = new ArrayList<>();
        for (int i = 0; i < a.size(); i++) {
            ans.add(a.get(i));
        }
        return ans;
    }




}

class compareforLargestnumber implements Comparator<String> {
    public int compare(String x, String y) {
        String a1 = x + y;
        String a2 = y + x;

        return a1.compareTo(a2);
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
