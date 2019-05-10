import java.util.Scanner;

public class B1_Cat_Party_Easy_Edition_forces {
//    static boolean check(int[] arr)
//    {
//        boolean flag = false;
//        int count = 0;
//        boolean first = false;
//        for(int i = 0; i<arr.length;i++)
//        {
//            if (arr[i] != 0)
//            {
//                if (first)
//                {
//                    if (arr[i] != count) {
//                        flag = true;
//                        break;
//                    }
//
//                }else
//                {count = arr[i];
//                first = true;}
//            }
//
//        }
//        return flag;
//    }
/*
    static boolean check1(int[] arr) {
        boolean flag = false;//answer
        int c = 0;//the repititive number
        boolean first = false;//first non zero
        boolean f1 = false;//first diff
        int countt = 0;//count of total non zero
        int count1 = 0;//count of number of ones
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] != 0)
            {
                countt++;
                if (!first) {
                    c = arr[i];
                    first = true;
                    flag = true;
                } else if (arr[i] == 1)
                {
                    count1++;
                    if (!f1)
                    {
                        flag = true;
                        f1 = true;
                    }
                    else if (c == 1)
                    {
                        flag = true;
                    }
                    else flag = false;
                } else if ((arr[i] - c) == 1||(arr[i] - c) == -1)
                {
                    if (!f1) {
                        flag = true;
                        f1 = true;
                    }
                    else flag = false;
                } else flag = false;


            }

        }
       return flag;

    }
  */  static boolean alleq(int[] arr)
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

    public static void main(String[] args) {
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
      /*  for (int element: col) {
            System.out.println(element);
        }*/
        System.out.println(num + 1);
        /*int[] ar = new int[]{3,1,1,1,0,0,0,0};
        boolean a = check2(ar);
        System.out.println(a);*/
    }
}
