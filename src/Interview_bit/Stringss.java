package Interview_bit;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

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
    public String countAndSay(int n) {
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

//    https://www.interviewbit.com/problems/roman-to-integer/

    public int romanToInt(String A) {
        StringBuilder s = new StringBuilder(A);

        for (int i = 0; i < A.length(); i++) {
            switch (s.charAt(i)) {
                case 'M':
                    s.setCharAt(i, '7');
                    break;
                case 'D':
                    s.setCharAt(i, '6');
                    break;
                case 'C':
                    s.setCharAt(i, '5');
                    break;
                case 'L':
                    s.setCharAt(i, '4');
                    break;
                case 'X':
                    s.setCharAt(i, '3');
                    break;
                case 'V':
                    s.setCharAt(i, '2');
                    break;
                case 'I':
                    s.setCharAt(i, '1');
                    break;
            }
        }

        int ans = 0;
        // int ans = 0;
//        char prev = s.charAt(0);
        for (int i = 0; i < A.length(); i++) {
            if (i == A.length() - 1)
                ans += helperRoman(s.charAt(i));
            else if (s.charAt(i) >= s.charAt(i + 1)) {
                ans += helperRoman(s.charAt(i));
//                prev = s.charAt(i);
            } else {
                ans += helperRoman(s.charAt(i + 1)) - helperRoman(s.charAt(i));
                i++;
            }
        }
        return ans;
    }

    public char helperRoman2(char c) {
        switch (c) {
            case '6':
                return '7';
            case '5':
                return '6';
            case '4':
                return '5';
            case '3':
                return '4';
            case '2':
                return '3';
            case '1':
                return '2';
        }
        return 0;
    }

    public int helperRoman(char c) {
        switch (c) {
            case '7':
                return 1000;
            case '6':
                return 500;
            case '5':
                return 100;
            case '4':
                return 50;
            case '3':
                return 10;
            case '2':
                return 5;
            case '1':
                return 1;
        }
        return 0;
    }

    //    https://www.interviewbit.com/problems/reverse-the-string/
    public String reverseWords(String a) {
        a = a.trim();
        String[] x = a.split(" ");

        String[] b = new String[x.length];
        int j = x.length;
        for (int i = 0; i < x.length; i++) {
            b[j - 1] = x[i];
            j = j - 1;
        }

        StringBuilder s = new StringBuilder();
        for (int i = 0; i < x.length; i++) {
            s.append(b[i] + " ");
        }
        s.deleteCharAt(s.length() - 1);
        return s.toString();

    }


//    babb
//    bbab

}
