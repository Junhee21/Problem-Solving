import java.util.ArrayList;

class Kakao_2021_blind_03 {
  public int solution(int n, int s, int a, int b, int[][] fares) {
    Edges edges = new Edges(n, s, a, b, fares);
    edges.initShortPath(n);

    return edges.rideTaxi(n);
  }
}

class Edges {
  int INF = 98765432;
  int s;
  int a;
  int b;
  int[][] shortestPath = new int[201][201];

  Edges (int n, int s, int a, int b, int[][] fares) {
    this.s = s;
    this.a = a;
    this.b = b;
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= n; j++) {
        shortestPath[i][j] = INF;
        if (j == i) {
          shortestPath[i][j] = 0;
        }
      }
    }
    for (int i = 0; i < fares.length; i++) {
      shortestPath[fares[i][0]][fares[i][1]] = fares[i][2];
      shortestPath[fares[i][1]][fares[i][0]] = fares[i][2];
    }
  }

  void initShortPath(int n) {
    for (int i = 0; i <= n; i ++) {
      for (int j = 0; j <= n; j++) {
        for (int k = 0; k <= n; k++) {
          shortestPath[j][k] = Math.min(shortestPath[j][k], shortestPath[j][i] + shortestPath[i][k]);
        }
      }
    }
  }

  int rideTaxi(int n) {
    int minFee = INF;

    for (int i = 0; i<=n; i++) {
      int now = shortestPath[s][i] + shortestPath[i][a] + shortestPath[i][b];
      minFee = Math.min(now, minFee);
    }

    return minFee;
  }
}