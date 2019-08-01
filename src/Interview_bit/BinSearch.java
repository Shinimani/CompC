package Interview_bit;

public class BinSearch {


    public int pow(int x, int n, int d) {

        long rem = 1;
        int check = 0;

        // simple cases
        if (x == 0) {
            return 0;
        }
        if (n == 0) {
            return 1;
        }

        // make x positive, check if power is odd
        if (x < 0) {
            x = Math.abs(x);
            if (n % 2 != 0) {
                check = 1;
            }
        }

        long temp = x % d;

        while (n != 0) {
            if (n % 2 != 0) {
                rem = (rem * temp) % d;
            }

            temp = temp * temp;
            temp = temp % d;

            n = n / 2;
            if (rem > d) {
                rem = rem % d;
            }
        }

        // if power is odd and x < 0, return d-rem
        if (check == 1) {
            return d - (int) rem;
        }

        return (int) rem;
    }
}