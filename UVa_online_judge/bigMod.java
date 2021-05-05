import java.math.BigInteger;
import java.util.Scanner;

public class bigMod {
	public static void main(String[] args) {
    Scanner cin = new Scanner(System.in);
    BigInteger B, P, M, res;
    while(cin.hasNext()){
      B = cin.nextBigInteger();
      P = cin.nextBigInteger();
      M = cin.nextBigInteger();
			res = B.modPow(P, M);

			System.out.println(res);

    }
	}
}
