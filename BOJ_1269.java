import java.util.HashSet;
import java.util.Scanner;

public class BOJ_1269 {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int aNum = scanner.nextInt();
    int bNum = scanner.nextInt();
    int aAndBNum = 0;
    int bMinusANum = 0;
    HashSet<Integer> aSet = new HashSet<>();    
    for (int i = 0; i < aNum; i++) {
      aSet.add(scanner.nextInt());
    }
    for (int i = 0; i < bNum; i++) {
      int n = scanner.nextInt();
      if (aSet.contains(n)) {
        aAndBNum++;
      } else {
        bMinusANum++;
      }
    }
    System.out.println(aSet.size() - aAndBNum + bMinusANum);
    scanner.close();
  }
}