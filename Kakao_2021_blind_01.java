class Kakao_2021_blind_01 {
  public String solution(String new_id) {
    new_id = new_id.toLowerCase();
    String temp = "";
    for (int i = 0; i < new_id.length(); i++) {
      char ch = new_id.charAt(i);
      boolean b = false;
      if (ch >= '0' && ch <= '9') {
        b = true;
      } else if (ch >= 'a' && ch <= 'z'){
        b = true;
      } else if (ch == '_' || ch == '-' || ch == '.') {
        b = true;
      }
      if (b) {
        temp = temp.concat(new_id.substring(i, i + 1));
      }
    }
    temp = temp.replaceAll("[.]{2,}", ".");
    if (temp.length() != 0 && temp.charAt(0) == '.') {
      temp = temp.substring(1);
    }
    if (temp.length() != 0 && temp.charAt(temp.length() - 1) == '.') {
      temp = temp.substring(0, temp.length() - 1);
    }
    if (temp.equals("")) {
      temp = "a";
    }
    if (temp.length() >= 16) {
      temp = temp.substring(0, 15);
      if (temp.charAt(14) == '.') {
        temp = temp.substring(0, 14);
      }
    }
    if (temp.length() < 3) {
      String ls = temp.substring(temp.length() - 1);
      while (temp.length() < 3) {
        temp = temp.concat(ls);
      }
    }
    return temp;
  }

  public static void main(String[] args) {
    Kakao_2021_blind_01 a = new Kakao_2021_blind_01();
    String b = a.solution(	"=.=");
    System.out.println(b);
  }
}