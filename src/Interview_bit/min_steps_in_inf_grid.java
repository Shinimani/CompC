package Interview_bit;

import java.util.ArrayList;

public class min_steps_in_inf_grid {

    public int coverPoints(ArrayList<Integer> A, ArrayList<Integer> B) {
        int n = A.size();
        int ans = 0;
        for (int i = 1; i < n; i++) {
//            int ax = A.get(i-1);
//            int ay = B.get(i-1);

            int delx = Math.abs(A.get(i) - A.get(i - 1));
            int dely = Math.abs(B.get(i) - B.get(i - 1));
            ans += Math.max(delx, dely);


        }

        return ans;

    }

//    https://www.interviewbit.com/problems/min-steps-in-infinite-grid/
}
