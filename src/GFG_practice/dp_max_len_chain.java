package GFG_practice;

import java.util.Arrays;
import java.util.Comparator;

public class dp_max_len_chain {

    static int maxChainLength(Pair[] arr, int n)
    {
        CompareToBeUsed c = new CompareToBeUsed();
        Arrays.sort(arr,c);
        int ans = 1;
        Pair a = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i].x > a.y)
            {
                ans++;
                a=arr[i];
            }
        }
        return ans;

    }

    public static void main(String[] args) {
        Pair[] a = new Pair[8];
        a[0] = new Pair(125,896);
        a[1] = new Pair(546,583);
        a[2] = new Pair(368,815);
        a[3] = new Pair(365,435);
        a[4] = new Pair(88,751);
        a[5] = new Pair(44,809);
        a[6] = new Pair(179,277);
        a[7] = new Pair(585,789);
        Arrays.sort(a,new CompareToBeUsed());
        for (int i = 0; i < 8; i++) {
            System.out.println(a[i].x + " " + a[i].y);
        }
        System.out.println(maxChainLength(a,8));

    }

}

class CompareToBeUsed implements Comparator<Pair>
{
    public int compare(Pair a, Pair b)
    {
        return a.y - b.y;
    }
}

class Pair
{
    int x;
    int y;
    public Pair(int a, int b)
    {
        x=a;
        y=b;
    }
}