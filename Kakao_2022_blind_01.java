import java.util.ArrayList;

public class Kakao_2022_blind_01 {
  public int solution(int n, int k) {
    int answer = 0;

    KNum knum = new KNum(n, k);
    ArrayList<Integer> knumArr = knum.getArr();
    PrimeNumber pn = new PrimeNumber();

    long target = 0;
    for (int i = knumArr.size() - 1; i >= 0; i--) {
      int nowNum = knumArr.get(i);
      if (nowNum == 0 && target != 0) {
        if (pn.checkPrime(target)) {
          answer++;
        }
        target = 0;
      } else {
        target *= 10;
        target += nowNum;
      }
    }

    if (target != 0) {
      if (pn.checkPrime(target)) {
        answer++;
      }
    }

    return answer;
  }
}

class PrimeNumber {
  private ArrayList<Integer> primeArr = new ArrayList<>();
  private ArrayList<Boolean> isPrime = new ArrayList<>();

  public PrimeNumber() {
    primeArr.add(2);
    isPrime.add(false);
    isPrime.add(false);
    isPrime.add(true);
  }

  public boolean checkPrime(long num) {
//    System.out.println(num);
    if (isPrime.size() > num) return isPrime.get((int)num);

    int sqrt = (int)Math.sqrt(num) + 1;

    int originNum = isPrime.size();
    for (int i = originNum; i <= sqrt; i++) {
      isPrime.add(true);
    }

    for (int i = 0; i < primeArr.size(); i++) {
      int nowPrime = primeArr.get(i);

      for (int j = nowPrime * 2; j <= sqrt; j+=nowPrime) {
        isPrime.set(j, false);
      }
    }

    for (int i = originNum; i <= sqrt; i++) {
      if (isPrime.get(i)) {
        primeArr.add(i);

        for (int j = i * 2; j <= sqrt; j+=i) {
          isPrime.set(j, false);
        }
      }
    }

    for (int i = 0; i < primeArr.size(); i++) {
      if (num % primeArr.get(i) == 0) return false;
    }


    return true;
  }
}

class KNum {
  private ArrayList<Integer> arr = new ArrayList<>();

  public KNum(int n, int k) {
    while (n != 0) {
      arr.add(n % k);
      n /= k;
    }
  }

  public ArrayList<Integer> getArr() {
    return arr;
  }
}


