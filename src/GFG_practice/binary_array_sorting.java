package GFG_practice;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class binary_array_sorting {
    public static void main(String[] args) throws Exception{
        InputStreamReader ir = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(ir);
        int T = Integer.parseInt(br.readLine());
        while(T-->0)
        {
            int N = Integer.parseInt(br.readLine());
            char[] inp = br.readLine().replaceAll("\\W", "").toCharArray();
            int c = 0;
            int f = 0;
            while(f<N)
            {
                if (inp[f++]=='0')
                    c++;
            }
            int on = N-c;
            while (c-->0)
            {
                System.out.print("0 ");
            }
            while(on-->0)
            {
                System.out.print("1 ");
            }
            if (on == 1)
                System.out.print("1");


        }


    }
}
