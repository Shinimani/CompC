import java.util.ArrayList;
import java.util.Scanner;

public class cf_1165_C_Good_String {

//    https://codeforces.com/problemset/problem/1165/C

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        String st = s.next();
        StringBuilder stb = new StringBuilder(st);
        boolean f = true;
        int k = -1;
        int count = 0;
//        while(f && stb.length() !=0)
        {
//            k = helper(stb);
//            if(k!= -1)
//            {
//                stb.deleteCharAt(k);
//                count++;
//            } else
//                f = false;

            helper(stb,count);

            if (stb.length()%2 !=0)
            {
                stb.deleteCharAt(stb.length()-1);
                count++;
            }

        }

        System.out.println(count);
        System.out.println(stb);


    }

    static void helper(StringBuilder str, int count)
    {
        ArrayList<Integer> ans = new ArrayList<Integer>();
//        int ans[] = new ;
//        ans[0] = 0;
//        ans[1] = 0;
//        int k = 0;
//
        for (int i = 0; i < str.length() - 1; i=i+2) {
            if (str.length()==0)
                break;
            if (str.charAt(i) == str.charAt(i+1))
            {
                str.deleteCharAt(i+1);
                count++;
//                System.out.println(str.charAt(i));
//                System.out.println(str);
//                System.out.println(i);
//                ans.add(i+1);
                i=i-2;
//                ans[0] = 1;
//                ans[1] = i+1;
//                break;
            }
        }
        System.out.println(str);

//        return ans;


    }

}

