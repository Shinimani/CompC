/* package codechef; // don't place package name! */
package Codeforces;
import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
    public static void main (String[] args) throws java.lang.Exception
    {
        Scanner s = new Scanner(System.in);
        int t=0;
        int n=0;
        int temp=0;
        int ans=0;
        t=s.nextInt();
        while(t-->0)
        {
            n=s.nextInt();
            int[] a = new int[n];
            int[] b = new int[n];
            ans=0;
            for(int i=0;i<n;i++)
            {
                a[i]=s.nextInt();
            }
            for(int i=0;i<n;i++)
            {
                b[i]=s.nextInt();
            }
            Arrays.sort(a);
            Arrays.sort(b);
            for(int i=0;i<n;i++)
            {
                temp = Math.min(a[i],b[i]);
                ans+=temp;
            }
            System.out.println(ans);


        }
        // your code goes here
    }
}
