import java.util.Scanner;

public class BOJ_2566 {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n = 0, m = 0;
    int maxNum = -1;
    for (int i = 1; i <= 9; i++) {
      for (int j = 1; j <= 9; j++) {
        int num = scanner.nextInt();
        if (num > maxNum) {
          maxNum = num;
          n = i;
          m = j;
        }
      }
    }
    System.out.printf("%d\n%d %d\n", maxNum, n, m);
    scanner.close();
  }
}
