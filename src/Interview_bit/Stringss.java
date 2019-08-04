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

    //    https://www.interviewbit.com/problems/count-and-say/
    public String countAndSay(int A) {
        if (n == 1) return "1";
        else if (n == 2) return "11";
        else {
            String x = "11";
            while (n-- > 2) {
                x = countAndSayhelper(x);
            }
            return x;
        }


    }

    public String countAndSayhelper(String x) {
        char temp = x.charAt(0);
        int cou = 1;
        StringBuilder s = new StringBuilder();
        for (int i = 1; i < x.length(); i++) {
            if (x.charAt(i) == temp)
                cou++;
            else {
                s.append("" + cou + temp);
                temp = x.charAt(i);
                cou = 1;
            }
            if (i == x.length() - 1) {
                s.append("" + cou + temp);
            }
        }
        return s.toString();
    }

    //    https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/
    void computeLPS(String s, int[] lps) {
        int m = s.length();
        int len = 0;
        lps[0] = 0;
        int i = 1;
        while (i < m) {
            if (s.charAt(i) == s.charAt(len)) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    public int solveMinPalindrome(String a) {
        StringBuilder s = new StringBuilder(a);
        s = s.reverse();
        String str = a + "$" + s.toString();
        int[] lps = new int[str.length()];
        computeLPS(str, lps);
        return (a.length() - lps[str.length() - 1]);
    }

//    babb
//    bbab

}
