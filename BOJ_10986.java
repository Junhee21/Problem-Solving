import java.io.IOException;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class BOJ_10986 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringTokenizer firstSt = new StringTokenizer(br.readLine());
    int n = Integer.parseInt(firstSt.nextToken());
    int m = Integer.parseInt(firstSt.nextToken());
    int[] arr = new int[n + 1];
    long[] arrRemainder = new long[m];
    arrRemainder[0] = 1;

    StringTokenizer secondSt = new StringTokenizer(br.readLine());
    for (int i = 0; i < n; i++) {
      int reaminder =  (arr[i] + Integer.parseInt(secondSt.nextToken())) % m;
      arr[i + 1] = reaminder;
      arrRemainder[reaminder]++;
    }
    long answer = 0;
    for (int i = 0; i < m; i++) {
      if (arrRemainder[i] < 2) continue;
      answer += (arrRemainder[i] * (arrRemainder[i] - 1) / 2);
    }
    bw.write(String.valueOf(answer) + '\n');
    bw.flush();
    bw.close();
    br.close();
  }
}
