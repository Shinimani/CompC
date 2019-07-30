package Interview_bit;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

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




}