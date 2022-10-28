import java.util.ArrayList;
import java.util.Scanner;
import java.util.Collections;

public class BOJ_2587 {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    ArrayList<Integer> arr = new ArrayList<>();
    int sum = 0;
    for (int i = 0; i < 5; i++) {
      int num = scanner.nextInt();
      arr.add(num);
      sum += num;
    }
    Collections.sort(arr);
    System.out.println(sum / 5);
    System.out.println(arr.get(2));
    scanner.close();
  }
}
