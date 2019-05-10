import java.util.ArrayList;
import java.util.Scanner;

public class B1_Cat_Party_Easy_Edition_forces {

    static boolean alleq(int[] arr)
    {
        boolean ans = true;
        boolean f = false;
        int k = 0;
        int c = 0;
        while (!f && k<arr.length) {
            if (arr[k]!=0) {
                c = arr[k];
                f = true;
            } else k++;
        }
        if (!f) return true;
        for (int i = 0;i<arr.length;i++)
        {
            if(arr[i] !=0) {
                if (c != arr[i]) {
                    ans = false;
                    break;
                }
            }
        }
        return ans;
    }
    static boolean check2(int[] arr)
    {
        boolean ans = false;
        for(int i = 0;i<arr.length;i++)
        {
//            int temp = arr[i];
            arr[i] = arr[i]- 1;
            if (alleq(arr))
            {
                ans = true;
                arr[i] = arr[i] + 1;
                break;
            }
            else
            {
                arr[i] = arr[i] +1;
            }
        }
        return ans;

    }


    /*
    static int hashFunction(int x)
    {
        return (x % 1019);
    }

     */

    /*
    static void store(int[] arr, int x)
    {
        int l = hashFunction(x);
        if (arr[l] == 0)
        {
            arr[l] = x;
        }
        else
        {
            while (arr[l] == 0)
            {
                l = l + 1019;
            }
            arr[l] = x;
        }
    }


    static int getLocation(int[] arr, int x)
    {
        int k = arr.length;
        int l = x % k;
        while (arr[l] !=0)
        {
            l = ((l + (k/2)) % k);
        }
        return l;
    }

*/

    public static void main(String[] args) {
        //this was for easy version
        /*
        Scanner s = new Scanner(System.in);
        int T = s.nextInt();
        int num = 0;
        int[] arr = new int[T];
        int[] col = new int[11];
        for (int k = 0; k < T; k++) {
            arr[k] = s.nextInt();
            (col[arr[k]])++;
            if (check2(col)) num = k;

        }
        System.out.println(num + 1);

         */


        //This is for tough version
        Scanner s = new Scanner(System.in);
        int T = s.nextInt();
        int num = 0;
        ArrayList pos = new ArrayList();//this will store the positions of the numbers, with the index being same in both the freq and pos tables
        int[] freq = new int[T];//this will store frequencies of the number at locations
        for (int k = 0;k<T;k++)
        {
            int a = s.nextInt();
            int l = pos.indexOf(a);
            boolean f = false;
            if (l == -1)
            {
                f = true;
                pos.add(a);
                l = pos.size() - 1;
            }
            (freq[l])++;
            if (f && num == (k-1)) num = k;
            else if (check2(freq)) num = k;
        }
        /*
        for (int element:freq)
        {
            System.out.println(element + " ");
        }
         */

        System.out.println(num + 1);
    }
}
