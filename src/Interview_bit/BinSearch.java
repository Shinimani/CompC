package Interview_bit;

public class BinSearch {

    public int pow(int x, int n, int d) {
        int two = (int) (Math.log10(n) / Math.log10(2));
        int rem = n - (int) Math.pow(2, two);
        int ans = x % d;
        for (int i = 0; i < two; i++) {
            ans = (int) Math.pow(ans, 2) % d;
        }
        x = (int) Math.pow(x % d, rem) % d;
        ans = (ans * x) % d;

        return (ans + d) % d;

    }
}
