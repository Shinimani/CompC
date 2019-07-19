package Interview_bit;

import java.util.ArrayList;

public class max_abs_diff {

    public static void main(String[] args) {

    }

    int maxArr(ArrayList<Integer> a) {

        int max1 = Integer.MIN_VALUE;
        int max2 = Integer.MIN_VALUE;
        int min1 = Integer.MAX_VALUE;
        int min2 = Integer.MAX_VALUE;

        for (int i = 0; i < a.size(); i++) {
            max1 = Math.max(max1, a.get(i) + i);
            min1 = Math.min(min1, a.get(i) + i);
            max2 = Math.max(max2, a.get(i) - i);
            min2 = Math.min(min2, a.get(i) - i);
        }

        return Math.max(max1 - min1, max2 - min2);

    }
//    https://www.interviewbit.com/problems/maximum-absolute-difference/
}
