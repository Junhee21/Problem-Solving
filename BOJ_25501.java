import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class BOJ_25501 {
  void solve() throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int num = Integer.parseInt(br.readLine());
    for (int i = 0; i < num; i += 1) {
      String str = br.readLine();
      Palindrom target = new Palindrom(str);
      if (target.isPalindrom(0, str.length() - 1)) {
        System.out.println(1 + " " + target.numRecurrence);
      } else {
        System.out.println(0 + " " + target.numRecurrence);
      }
    }
  }

  public static void main(String[] args) throws IOException {
    new BOJ_25501().solve();
  }
}

class Palindrom {
  String palindrom;
  int numRecurrence = 0;

  Palindrom(String str) {
    palindrom = str;
  }

  boolean isPalindrom(int front, int rear) {
    numRecurrence += 1;
    if (front >= rear) return true;
    if (palindrom.charAt(front) != palindrom.charAt(rear)) return false;
    return isPalindrom(front + 1, rear - 1);
  }
}