package Interview_bit;

import java.util.ArrayList;

public class Stringss {

    //    https://www.interviewbit.com/problems/longest-common-prefix/
    public String longestCommonPrefix(ArrayList<String> A) {
        String x = A.get(0);
        String temp = "";
        int j = 0;
        for (int i = 1; i < A.size(); i++) {
            temp = A.get(i);
            j = 0;
            while (j < x.length() && j < temp.length()) {

                if (x.charAt(j) == temp.charAt(j))
                    j++;
                else {
//                    j--;
                    break;
                }
            }
            if (j == 0)
                return "";
            else x = x.substring(0, j);


        }

        return x;
    }
}
