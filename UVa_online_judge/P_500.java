import java.util.Scanner;
import java.math.BigDecimal;
import java.math.BigInteger;
//import java.math.sqrt;

public class P_500
{
    public static BigInteger factorial (BigInteger x){
    
        int n = x.intValue();
        BigInteger res = new BigInteger("1");
        for(int i = 1; i <= n; i++){
            BigInteger acc = BigInteger.valueOf(i);
            res = res.multiply(acc);
        }
       return res;
    }

    public static void main(String[] args)
    {
        Scanner cin = new Scanner(System.in);
       
        BigInteger x;
        
        while(cin.hasNext()){
          x = cin.nextBigInteger();
          System.out.println(x + "!");
          System.out.println(factorial(x));
        }
        
    }
}