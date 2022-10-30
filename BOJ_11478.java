import java.util.HashSet;
import java.util.Scanner;

public class BOJ_11478 {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    String str = scanner.nextLine();
    HashSet<String> set = new HashSet<>();
    for (int i = 1; i <= str.length(); i++) {
      for (int j = 0; j <= str.length() - i; j++) {
        String nowStr = str.substring(j, j + i);
        set.add(nowStr);
      }
    }
    System.out.println(set.size());
    scanner.close();
  }
}