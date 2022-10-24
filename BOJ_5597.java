import java.util.ArrayList;
import java.util.Scanner;

public class BOJ_5597 {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    ArrayList<Boolean> arr = new ArrayList<>();
    for (int i = 0; i < 31; i++) {
      arr.add(false);
    }
    for (int i = 0; i < 28; i++) {
      int whoDone = scanner.nextInt();
      arr.set(whoDone, true);
    }
    for (int i = 1; i <= 30; i++) {
      if (!arr.get(i)) System.out.println(i);
    }
    scanner.close();
  }
}
