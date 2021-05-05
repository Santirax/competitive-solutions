import java.math.BigInteger;
import java.util.Scanner;
public class veryEasy {
  public static void main(String[] args) {
    Scanner cin = new Scanner(System.in);
    while(cin.hasNext()){
      int N;
      BigInteger A;
      N = cin.nextInt();
      A = cin.nextBigInteger();
      BigInteger res = BigInteger.ZERO;
      BigInteger aux = BigInteger.ZERO;
      
      for(int x = 1; x <= N; x++){
        
        BigInteger i = BigInteger.valueOf(x);
        res = res.add((A.pow(x).multiply(i)));
        //BigInteger i = BigInteger.valueOf(x);
        //BigInteger ai = A.pow(x);
        //res = res.add(ai.multiply(x));
      }

      
      System.out.println(res);
    }

  }
}
