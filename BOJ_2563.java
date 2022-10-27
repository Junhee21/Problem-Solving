import java.util.ArrayList;
import java.util.Scanner;

public class BOJ_2563 {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    ArrayList<ArrayList<Boolean>> whitePaper = new ArrayList<>();
    for (int i = 0; i < 100; i++) {
      whitePaper.add(new ArrayList<Boolean>());
      for (int j = 0; j < 100; j++) {
        whitePaper.get(i).add(true);
      }
    }
    int n = scanner.nextInt();
    for (int i = 0; i < n; i++) {
      int a = scanner.nextInt();
      int b = scanner.nextInt();
      for (int j = b; j < b + 10; j++) {
        for (int k = a; k < a + 10; k++) {
          whitePaper.get(j).set(k, false);
        }
      }
    }
    int sum = 0;
    for (int i = 0; i < 100; i++) {
      for (int j = 0; j < 100; j++) {
        if (!whitePaper.get(i).get(j)) sum++;
      }
    }
    System.out.println(sum);
    scanner.close();
  }
}
