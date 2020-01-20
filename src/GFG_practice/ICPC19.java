package GFG_practice;

public class ICPC19 {

    public static boolean intersect(int[] a, int[] b) {
//        boolean ans = true;

        int l1 = a[0];
        int r1 = a[1];
        int l2 = b[0];
        int r2 = b[1];

        return (l1 <= l2 && r1 >= l2) || (l2 <= l1 && r2 >= l1);
    }

    public static void main(String[] args) throws Exception {
        FastScanner f = new FastScanner();
        int T = f.nextInt();
        while (T-- > 0) {
            int n = f.nextInt();
            int[][] locations = new int[n][3];
            for (int i = 0; i < n; i++) {
                locations[i][0] = f.nextInt();
                locations[i][1] = f.nextInt();
                locations[i][2] = f.nextInt();
            }

            if (helper(locations)) System.out.println("YES");
            else System.out.println("NO");


        }
    }

    public static boolean helper(int[][] locations) {

        for (int i = 0; i < n; i++) {
            int[] first = locations[i];
            for (int j = i + 1; j < n; j++) {
                int[] second = locations[j];
                if (intersect(first, second)) {
                    for (int k = j + 1; k < n; k++) {
                        int[] third = locations[k];
                        if (intersect(second, third) && intersect(first, third)) {
                            if (first[2] == second[2] && second[2] == third[2]) {
                                return false;
                            }
                        }

                    }
                }


            }
        }
        return true;

    }


}

