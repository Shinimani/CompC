package Codeforces;

//import GFG_practice.FastScanner;

import java.util.ArrayList;

public class cf_552_div3_B {

    public static void main(String[] args) throws Exception {
        FastScanner f = new FastScanner();
//        int T = f.nextInt();
//        while (T-- > 0) {
            int N = f.nextInt();
            ArrayList<Integer> uniq = new ArrayList<Integer>();
        for (int i = 0; i < N; i++) {
            int k = f.nextInt();
            if (!uniq.contains(k))
                uniq.add(k);
            if (uniq.size()>3)
                break;
        }
        if(uniq.size()==4)
        {
            System.out.println("-1");
        } else if (uniq.size()==3)
        {
            if (uniq.get(0)+uniq.get(1)==2*uniq.get(2))
                System.out.println(Math.abs(uniq.get(2)-uniq.get(0)));
            else if (uniq.get(0)+uniq.get(2)==2*uniq.get(1))
                System.out.println(Math.abs(uniq.get(1)-uniq.get(0)));
            else if (uniq.get(2)+uniq.get(1)==2*uniq.get(0))
                System.out.println(Math.abs(uniq.get(2)-uniq.get(0)));
            else System.out.println("-1");
        } else if (uniq.size()==2)
        {
            if ((uniq.get(0)+uniq.get(1))%2==0)
                System.out.println(Math.abs(uniq.get(0)-uniq.get(1))/2);
            else System.out.println(Math.abs(uniq.get(0)-uniq.get(1)));
        } else System.out.println("0");

    }
}
