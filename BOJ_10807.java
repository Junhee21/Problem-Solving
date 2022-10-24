import java.util.ArrayList;
import java.util.Scanner;

public class BOJ_10807 {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    ArrayList<Integer> arr = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      arr.add(scanner.nextInt());
    }
    int target = scanner.nextInt();
    int answer = 0;
    for (Integer item : arr) {
      if (item == target) answer++;
    }
    System.out.println(answer);
    scanner.close();
  }
}
