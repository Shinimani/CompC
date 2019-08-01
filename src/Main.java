import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
//        String T = s.next();
//        String y = s.next();
//        boolean a = T>y;
        int[][] a = new int[3][4];
        System.out.println(a.length);
        System.out.println(a[0].length);

        String[] b = new String[3];
        b[0] = "12";
        b[1] = "8";
        b[2] = "89";
        Arrays.sort(b);

        for (String i : b
        ) {
            System.out.println(i);
        }

        System.out.println(2 >> 4);
        System.out.println();
        System.out.println("5".compareTo("60"));


//        System.out.println();
//        for (int i = 0; i < T; i++) {
//            int N = s.nextInt();
//            int[] a1 = new int[N];
//            for (int j = 0; j < N; j++) {
//                a1[j] = s.nextInt();
//            }
//
//            int[] a2 = new int[N];
//            for (int j = 0; j < N; j++) {
//                a2[j] = s.nextInt();
//            }
//            Arrays.sort(a1);
//            Arrays.sort(a2);
//
//            boolean ans = false;
//            for (int j = 0; j < N; j++) {
//                if (a2[j] < a1[j]) {
//                    ans = true;
//                    break;
//                }
//            }
//            if (ans) {
//                System.out.println("LOSE");
//            } else System.out.println("WIN");
//
//
//


//        System.out.println("Hello World!");
    }
}
