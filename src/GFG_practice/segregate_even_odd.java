package GFG_practice;

import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.Collections;

public class segregate_even_odd {

//    https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-numbers/0/?ref=self

    public static void main(String[] args) {

        FastScanner f = new FastScanner();
        int T = f.nextInt();

        while(T-->0)
        {
            int N = f.nextInt();
            int[] inp = f.nextIntArray(N);
//            int[] even = new int[N];
//            int[] odd = new int[N];
            ArrayList<Integer> even = new ArrayList<Integer>();
            ArrayList<Integer> odd = new ArrayList<Integer>();
            int k=0,l=0;
            for (int i = 0; i < N; i++) {
                if (inp[i]%2==0)
                {
                    even.add(inp[i]);
                } else odd.add(inp[i]);
            }

            Collections.sort(even);
            Collections.sort(odd);

            StringBuffer ans = new StringBuffer();
//            ans.
            for (int i = 0; i < even.size(); i++) {
                ans.append(even.get(i)+" ");
            }

            for (int i = 0; i < odd.size(); i++) {
                ans.append(odd.get(i)+" ");
            }

            ans.deleteCharAt(ans.length()-1);
            System.out.println(ans);
        }

    }
}
class FastScanner {
    public int BS = 1<<16;
    public char NC = (char)0;
    byte[] buf = new byte[BS];
    int bId = 0, size = 0;
    char c = NC;
    double num = 1;
    BufferedInputStream in;

    public FastScanner() {
        in = new BufferedInputStream(System.in, BS);
    }

    public FastScanner(String s) {
        try {
            in = new BufferedInputStream(new FileInputStream(new File(s)), BS);
        }
        catch (Exception e) {
            in = new BufferedInputStream(System.in, BS);
        }
    }

    public char nextChar(){
        while(bId==size) {
            try {
                size = in.read(buf);
            }catch(Exception e) {
                return NC;
            }
            if(size==-1)return NC;
            bId=0;
        }
        return (char)buf[bId++];
    }

    public int nextInt() {
        return (int)nextLong();
    }

    public long nextLong() {
        num=1;
        boolean neg = false;
        if(c==NC)c=nextChar();
        for(;(c<'0' || c>'9'); c = nextChar()) {
            if(c=='-')neg=true;
        }
        long res = 0;
        for(; c>='0' && c <='9'; c=nextChar()) {
            res = (res<<3)+(res<<1)+c-'0';
            num*=10;
        }
        return neg?-res:res;
    }

    public double nextDouble() {
        double cur = nextLong();
        return c!='.' ? cur:cur+nextLong()/num;
    }

    public String next() {
        StringBuilder res = new StringBuilder();
        while(c<=32)c=nextChar();
        while(c>32) {
            res.append(c);
            c=nextChar();
        }
        return res.toString();
    }

    public String nextLine() {
        StringBuilder res = new StringBuilder();
        while(c<=32)c=nextChar();
        while(c!='\n') {
            res.append(c);
            c=nextChar();
        }
        return res.toString();
    }

    public boolean hasNext() {
        if(c>32)return true;
        while(true) {
            c=nextChar();
            if(c==NC)return false;
            else if(c>32)return true;
        }
    }

    public int[] nextIntArray(int n) {
        int[] res = new int[n];
        for(int i = 0; i < n; i++) res[i] = nextInt();
        return res;
    }

}
