import java.io.IOException;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class BOJ_16139 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    String string = br.readLine();
    int[][] arraySum = new int[string.length() + 1][26];
    for (int i = 0; i < 26; i++) {
      arraySum[0][i] = 0;
    }
    for (int i = 0 ; i < string.length(); i++) {
      for (int j = 0; j < 26; j++) {
        arraySum[i + 1][j] = arraySum[i][j];
      }
      arraySum[i + 1][string.charAt(i) - 'a']++;
    }

    int numQuestion = Integer.parseInt(br.readLine());
    for (int i = 0; i < numQuestion; i++) {
      StringTokenizer st = new StringTokenizer(br.readLine());
      char target = st.nextToken().charAt(0);
      int start = Integer.parseInt(st.nextToken());
      int end = Integer.parseInt(st.nextToken());
      bw.write(String.valueOf(arraySum[end + 1][target - 'a'] - arraySum[start][target - 'a']) + '\n');
    }
    bw.flush();
    bw.close();
    br.close();
  }
}
