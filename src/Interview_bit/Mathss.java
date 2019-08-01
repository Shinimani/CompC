package Interview_bit;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Mathss {


    // Returns arraylist of all prime numbers smaller than n
    static ArrayList<Integer> SieveOfSundaram(int n) {

        // In general Sieve of Sundaram, produces
        // primes smaller than (2*x + 2) for a number
        // given number x. Since we want primes
        // smaller than n, we reduce n to half
        int nNew = (n - 2) / 2;

        // This array is used to separate numbers of the
        // form i+j+2ij from others where 1 <= i <= j
        boolean[] marked = new boolean[nNew + 1];

        // Initalize all elements as not marked
        Arrays.fill(marked, false);

        // Main logic of Sundaram. Mark all numbers of the
        // form i + j + 2ij as true where 1 <= i <= j
        for (int i = 1; i <= nNew; i++)
            for (int j = i; (i + j + 2 * i * j) <= nNew; j++)
                marked[i + j + 2 * i * j] = true;


        // Since 2 is a prime number
        ArrayList<Integer> ans = new ArrayList<>();
        if (n > 2)
            ans.add(2);

        // Print other primes. Remaining primes are of
        // the form 2*i + 1 such that marked[i] is false.
        for (int i = 1; i <= nNew; i++)
            if (!marked[i])
                ans.add(2 * i + 1);
        return ans;
    }

    //https://www.interviewbit.com/problems/prime-sum/
    public ArrayList<Integer> primesum(int A) {
/*
        ArrayList<Integer> primes = SieveOfSundaram(A);
        for (int i = 0; i < primes.size(); i++) {
            int k = (Collections.binarySearch(primes,A-primes.get(i)));
            if (k>=0)
            {
                ArrayList<Integer> ans = new ArrayList<>();
                ans.add(primes.get(i));
                ans.add(primes.get(k));
                return ans;
            }
        }*/

        boolean[] primes = new boolean[A + 1];
        primes[0] = false;
        primes[1] = false;
        for (int i = 2; i <= A; i++) {
            primes[i] = true;
        }

        for (int i = 2; i <= Math.sqrt(A); i++) {
            for (int j = i; j * i <= A; j++) {
                primes[j * i] = false;
            }
        }

        for (int i = 2; i < A / 2; i++) {
            if (primes[i] && primes[A - i]) {
                ArrayList<Integer> ans = new ArrayList<>();
                ans.add(i);
                ans.add(A - i);
                return ans;
            }
        }

        return null;

    }

    //https://www.interviewbit.com/problems/sum-of-pairwise-hamming-distance/
    //
    public int hammingDistance(final List<Integer> A) {
        int n = A.size();
        int dist = 0;
        for (int i = 0; i < 31; i++) {
            int oneCount = 0;
            for (int j = 0; j < n; j++) {
                int num = A.get(j);
                oneCount += (num & 1 << i) != 0 ? 1 : 0;
            }
            int zeroCount = n - oneCount;
            dist += (2L * oneCount * zeroCount) % 1000000007;
            dist = dist % 1000000007;
        }
        return dist;
    }

    public StringBuilder helperForHamming(int n) {
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < n; i++) {
            ans.append('0');
        }
        return ans;
    }

    //    https://www.interviewbit.com/problems/fizzbuzz/
    public ArrayList<String> fizzBuzz(int A) {
        ArrayList<String> ans = new ArrayList<>();
        for (int i = 1; i < A + 1; i++) {
            if (i % 3 == 0 && i % 5 == 0)
                ans.add("FizzBuzz");
            else if (i % 3 == 0)
                ans.add("Fizz");
            else if (i % 5 == 0)
                ans.add("Buzz");
            else ans.add("" + i);
        }
        return ans;
    }

    //    https://www.interviewbit.com/problems/power-of-two-integers/
    public int isPower(int A) {
        if (A == 1)
            return 1;
        if (A < 3)
            return 0;
        if (A == 536870912)
            return 1;
        for (double i = 2; i <= (Math.sqrt(A) + 1); i++) {
            double x = Math.log(A) / Math.log(i);
            int ix = (int) x;
            double del = x - ix;
            if (del == 0)
                return 1;
        }
        return 0;
    }

    //    https://www.interviewbit.com/problems/numbers-of-length-n-and-value-less-than-k/
    public int solve(ArrayList<Integer> A, int B, int C) {
        int cSize = (int) Math.log10(C) + 1;
        int n = A.size();
        if (cSize < B || n == 0) return 0;
        boolean hasZero = A.get(0) == 0;
        if (cSize > B) return (B > 1 && hasZero ? n - 1 : n) * (int) Math.pow(n, B - 1);
        // B == cSize
        int pow10 = (int) Math.pow(10, B - 1), count = 0;
        for (int i = B; i > 0; i--) {
            int target = C / pow10, j;
            C %= pow10;
            pow10 /= 10;
            for (j = 0; j < n; j++) {
                if (A.get(j) >= target) break;
            }
            count += (B > 1 && i == B && hasZero ? j - 1 : j) * (int) Math.pow(n, i - 1);
            if (j == n || A.get(j) > target) break;
        }
        return count;
    }


    //    https://www.interviewbit.com/problems/rearrange-array/
    public void arrange(ArrayList<Integer> A) {
        int n = A.size();
        for (int i = 0; i < n; i++) A.set(i, A.get(i) + (A.get(A.get(i)) % n) * n);
        for (int i = 0; i < n; i++) A.set(i, A.get(i) / n);

        /*   for(int j=0;j<A.size();j++)
        {
            if(A.get(j)>0)
            {
                int temp = j;
                int val = -A.get(temp);
                while(A.get(j)!=temp)
                {
                    int t = A.get(j);
                    A.set(j,-A.get(t));
                    j = t;
                }
                A.set(j,val);
                j = temp;
            }
        }
        for(int i=0;i<A.size();i++)
            A.set(i,-A.get(i));
    */
    }

//    https://www.interviewbit.com/problems/grid-unique-paths/

    public int uniquePaths(int A, int B) {
        if (A == 1 || B == 1) return 1;
        else return uniquePaths(A - 1, B) + uniquePaths(A, B - 1);

    }
}


    /*
    int nlesskhelper (ArrayList<Integer> a, int lengthh, int[] c)
    {
        int ans = 0;

        return ans;

    }*/




