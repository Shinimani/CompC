package GFG_practice;


//https://practice.geeksforgeeks.org/problems/reverse-an-array/0


import java.util.Scanner;

public class reverse_arrray {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int T = s.nextInt();
        for (int i = 0; i < T; i++) {
            int N = s.nextInt();
            int[] arr = new int[N];
            for (int j = 0; j <N; j++) {
                arr[j] = s.nextInt();
            }

            String ans = "";
            for (int j = N-1; j >=0 ; j--) {
//                System.out.print(arr[j] + " ");
                ans = ans + arr[j] + " ";
            }
            ans = ans.substring(0,ans.length()-1);
            System.out.println(ans);
        }
    }


}
