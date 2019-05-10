import java.util.Scanner;

public class Eating_Soup_forces {

    public static void main(String[] args)
    {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int m = s.nextInt();

        if (m> (n/2)) {
            System.out.println(Math.max(n-m, 0));
        }
        else System.out.println(Math.max(m,1));
        }
    }

