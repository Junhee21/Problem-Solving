import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Arrays;

public class BOJ_24060 {
  public static void main (String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer temp = new StringTokenizer(br.readLine());
    int len = Integer.parseInt(temp.nextToken());
    int k = Integer.parseInt(temp.nextToken());
    temp = new StringTokenizer(br.readLine());
    int[] arr = new int[len];
    for (int i = 0; i < len; i ++) {
      arr[i] = Integer.parseInt(temp.nextToken());
    }

    new MergeSort(k, arr).solve();
  }
}

class MergeSort {
  int k;
  int[] arr;
  int answer = -1;
  MergeSort(int k, int[] arr) {
    this.k = k;
    this.arr = arr;
  }

  void merge(int front, int rear) {
    if (answer != -1) return;
    k -= (rear - front + 1);
    if (k <= 0) {
      int temp[] = new int[rear - front + 1];
      for (int i = front; i <= rear; i++) {
        temp[i - front] = arr[i];
      }
      Arrays.sort(temp);
      answer = temp[rear - front + k];
    }
  }

  void mergeSort(int front, int rear) {
    if (answer != -1) return;
    if (front >= rear) return;
    int mid = (front + rear) / 2;
    mergeSort(front, mid);
    mergeSort(mid + 1, rear);
    merge(front, rear);
  }

  void solve() {
    mergeSort(0, arr.length - 1);
    System.out.println(answer);
  }
}
