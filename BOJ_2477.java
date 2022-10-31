import java.util.Scanner;
import java.util.ArrayList;

public class BOJ_2477 {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    ArrayList<Side> arr = new ArrayList<>();
    int n = scanner.nextInt();
    int maxHeight = 0;
    int maxWidth = 0;
    int dirArr[] = {4, 2, 3, 1, 4};
    for (int i = 0; i < 6; i++) {
      int dir = scanner.nextInt();
      int len = scanner.nextInt();
      arr.add(new Side(dir, len));
      if (dir == 3 || dir == 4) {
        maxHeight = Math.max(maxHeight, len);
      } else {
        maxWidth = Math.max(maxWidth, len);
      }
    }
    Side prevSide = arr.get(0);
    int curNum = 1;
    while (true) {
      Side curSide = arr.get(curNum);
      int targetDir = 0;
      for (int i = 0; i < 4; i++) {
        if (prevSide.dir == dirArr[i]) {
          targetDir = i;
          break;
        }
      }
      if (curSide.dir != dirArr[targetDir + 1]) {
        System.out.println((maxHeight * maxWidth - curSide.len * prevSide.len) * n);
        break;
      }
      prevSide = curSide;
      curNum = (curNum + 1) % 6;
    }
    scanner.close();
  }
}

class Side {
  int dir;
  int len;
  Side(int dir, int len) {
    this.dir = dir;
    this.len = len;
  }
}