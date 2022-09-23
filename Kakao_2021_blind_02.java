import java.util.ArrayList;
import java.util.Arrays;

class Kakao_2021_blind_02 {
  public String[] solution(String[] orders, int[] course) {
    Bitmask bm = new Bitmask();

    for (int i = 0; i < orders.length; i ++) {
      bm.str = orders[i];
      bm.search(0, 0);
    }

    for (int i = 0; i < course.length; i ++) {
      bm.len = course[i];
      bm.select();
    }

    String[] answer = new String[bm.answer.size()];
    for (int i = 0; i < bm.answer.size(); i++) {
      answer[i] = bm.answer.get(i);
      System.out.println(answer[i]);
    }
    System.out.println("-----------------");

    Arrays.sort(answer);

    return answer;
  }
}

class Bitmask {
  int[] bitMask = new int[(int)Math.pow(2, 27)];
  String str;
  int len;
  ArrayList<Integer> bitArr = new ArrayList<>();
  ArrayList<String> answer = new ArrayList<>();

  void search(int nowBit, int index) {
    // str = "ABCDE"
    if (index == str.length()) return;

    int nowChar = str.charAt(index) - 'A';
    int newBit = nowBit | (int)Math.pow(2, nowChar);
    bitMask[newBit]++;

    search(newBit, index + 1);
    search(nowBit, index + 1);
  }

  void select () {
    bitArr = new ArrayList<>();
    makeBit(0, 0, 0);
    ArrayList<Integer> isAnswr = new ArrayList<>();
    int maxNum = 0;
    for (int item : bitArr) {
      if (bitMask[item] > maxNum) {
        isAnswr = new ArrayList<>();
        maxNum = bitMask[item];
        isAnswr.add((item));
      } else if (bitMask[item] == maxNum) {
        isAnswr.add((item));
      }
    }
    if (maxNum <= 1) return;

    for (int i = 0 ; i<isAnswr.size(); i++) {
      String temp = "";
      for (int j = 0; j < 26; j++) {
        if ((isAnswr.get(i) & (int)Math.pow(2, j)) != 0) {
          char a = (char)((char)j + 'A');
          temp = temp.substring(0) +a;
        }
      }
      answer.add(temp);
    }
  }

  void makeBit(int nowNum, int index, int num) {
    if (num == len) {
      bitArr.add(nowNum);
      return;
    }
    if (index == 26) return;
    makeBit(nowNum + (int)Math.pow(2, index), index + 1, num + 1);
    makeBit(nowNum, index + 1, num);
  }
}