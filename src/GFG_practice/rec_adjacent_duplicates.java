package GFG_practice;

public class rec_adjacent_duplicates {
//    https://practice.geeksforgeeks.org/problems/recursively-remove-all-adjacent-duplicates/0

    public static void main(String[] args) throws Exception {
        FastScanner f = new FastScanner();
        int T = f.nextInt();
        while (T-- > 0) {
            StringBuilder a = new StringBuilder(f.nextLine());
//            return ()
//            while (!new String(a).equals(new String(helperbig(a))))
//                a = helperbig(a);
            a = helpe(a,1,true);

            System.out.println(new String(a));
//            int[] a = f.nextIntArray(N);
//            while(f.hasNext())
//            {

//            }



        }
    }

    static StringBuilder helpe(StringBuilder w, int a, boolean f) {
        if (w.length() == 0)
            return w;
        else {
            if (a == w.length()) {
                if (f)
                    return w;
                else {
                    w.deleteCharAt(a - 1);
                    return w;
                }
            } else if (a==0)
            return helpe(w,a+1,f);
            else {
                if (w.charAt(a - 1) == w.charAt(a)) {
                    w.deleteCharAt(a - 1);
                    return helpe(w, a, false);
                } else {
                    if (f)
                        return helpe(w, a + 1, true);
                    else {
                        w.deleteCharAt(a - 1);
                        return helpe(w, a - 1, true);
                    }
                }
            }
        }
    }

    static StringBuilder helperbig(StringBuilder a)
    {
        if (a.length()==0)
            return a;
        else
        {
            char b = a.charAt(0);
            a.deleteCharAt(0);
            return helper(b,a,true);

        }

    }

    static StringBuilder helper(char a, StringBuilder x, boolean f){
//        if (x.charAt(0)==a)
        if (x.length()==0)
        {
            if (f)
                return (new StringBuilder().append(a));
            else return (new StringBuilder());
        }
        else if (x.charAt(0)==a)
        {
            x.deleteCharAt(0);
            return helper(a,x,false);
        } else if (f)
        {
            char b = x.charAt(0);
            x.deleteCharAt(0);
            StringBuilder l = new StringBuilder();
            l.append(a);
//            return(new )
            return (l.append(helper(b,x,true)));
        } else
        {
            char b = x.charAt(0);
            x.deleteCharAt(0);
            return (helper(b,x,true));
        }
    }


}

