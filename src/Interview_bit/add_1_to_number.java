package Interview_bit;

import java.util.ArrayList;
import java.util.Collections;

//https://www.interviewbit.com/problems/add-one-to-number/
public class add_1_to_number {

    public ArrayList<Integer> plusOne(ArrayList<Integer> A) {

        Collections.reverse(A);
        int i = 0;
        while (i < A.size() && A.get(i) == 9) {
            A.set(i, 0);
            i++;
        }
        if (i == A.size()) {
            A.add(1);
        } else {
            A.set(i, A.get(i) + 1);
        }
        Collections.reverse(A);
        while (A.get(0) == 0)
            A.remove(0);

        return A;

    }
}
