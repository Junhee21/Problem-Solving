import java.util.Scanner;

public class BOJ_24416 {
  public static void main(String[] args) {
    Scanner scanner =  new Scanner(System.in);
    int num = scanner.nextInt();
    recursionFibo(num);
    dpFibo(num);
    System.out.println(recursionNum + " " + dpNum);
    scanner.close();
  }

  static int recursionNum = 0;
  static int dpNum = 0;

  static void recursionFibo(int n) {
    if (n == 1 || n == 2) {
      recursionNum++;
      return;
    }
    recursionFibo(n - 1);
    recursionFibo(n - 2); 
  }

  static void dpFibo(int n) {
    int prev = 1;
    int current = 1;
    for (int i = 3; i <= n; i++) {
      dpNum++;
      int temp = current + prev;
      prev = current;
      current = temp;
    }
  }
}
