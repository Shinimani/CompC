import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int T = s.nextInt();
        for (int i = 0; i < T; i++) {
            int N = s.nextInt();
            int[] a1 = new int[N];
            for (int j = 0; j < N; j++) {
                a1[j] = s.nextInt();
            }

            int[] a2 = new int[N];
            for (int j = 0; j < N; j++) {
                a2[j] = s.nextInt();
            }
            Arrays.sort(a1);
            Arrays.sort(a2);

            boolean ans = false;
            for (int j = 0; j < N; j++) {
                if (a2[j] < a1[j]) {
                    ans = true;
                    break;
                }
            }
            if (ans) {
                System.out.println("LOSE");
            } else System.out.println("WIN");




        }
//        System.out.println("Hello World!");
    }
}
