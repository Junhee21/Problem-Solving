import java.util.ArrayList;
import java.util.Scanner;

public class BOJ_2738 {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    int m = scanner.nextInt();
    ArrayList<ArrayList<Integer>> matrixA = new ArrayList<>();
    ArrayList<ArrayList<Integer>> matrixB = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      matrixA.add(new ArrayList<Integer>());
      for (int j = 0; j < m; j++) {
        matrixA.get(i).add(scanner.nextInt());
      }
    }
    for (int i = 0; i < n; i++) {
      matrixB.add(new ArrayList<Integer>());
      for (int j = 0; j < m; j++) {
        matrixB.get(i).add(scanner.nextInt());
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        System.out.print(matrixA.get(i).get(j) + matrixB.get(i).get(j) + " ");
      }
      System.out.println();
    }
    scanner.close();
  }
}
