package GFG_practice;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

public class parenthesis {
//    https://practice.geeksforgeeks.org/problems/parenthesis-checker/0

    public static void main(String[] args) throws Exception {
        BufferedReader b = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(b.readLine());
//        FastScanner f = new FastScanner();
//        int T = f.nextInt();
        while (T-- > 0) {
//            char[] a = f.nextCharArray(N);
//            int N = f.nextInt();

            Stack<Character> stk = new Stack<Character>();
//            Stack<char> second = new Stack<char>();//{
//            Stack<char> third = new Stack<char>();//(

//            for (int i = 0; i < T; i++) {

//            }
            String s = b.readLine();
//            int which;
            boolean fl = true;
            for (int i = 0; i < s.length(); i++) {
                char a = s.charAt(i);
                if (a=='[' || a=='{' || a=='(')
                {
                    stk.push(a);
//                    which = 1;
                }
                else
                {
                    if (stk.empty())
                    {
                        fl = false;
                        break;
                    } else if (a==']')
                    {
                        if (stk.peek()=='[')
                        {
                            stk.pop();
                        } else
                        {
                            fl = false;
                            break;
                        }
                    } else if (a=='}')
                    {
                        if (stk.peek()=='{')
                        {
                            stk.pop();
                        } else
                        {
                            fl = false;
                            break;
                        }
                    }else if (a==')')
                    {
                        if (stk.peek()=='(')
                        {
                            stk.pop();
                        } else
                        {
                            fl = false;
                            break;
                        }
                    }
                }
            }
            if (fl && stk.empty())
                System.out.println("balanced");
            else System.out.println("not balanced");



        }
    }


}
