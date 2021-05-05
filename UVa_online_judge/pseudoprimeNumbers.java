import java.util.Scanner;
import java.math.BigDecimal;
import java.math.BigInteger;
//import java.math.sqrt;

public class pseudoprimeNumbers
{
    public static boolean isPrime (int p){
    
        for(int i = 2; i <= Math.sqrt(p); i++){
            if(p % i == 0)return false;
        }
       return true;
    }

    public static void main(String[] args)
    {
        Scanner cin = new Scanner(System.in);

        while (true)
        {
        
            //BigDecimal num = cin.nextBigDecimal();
            BigInteger p = cin.nextBigInteger();
            BigInteger a = cin.nextBigInteger();
            
            int pInt = p.intValue();
            //int n = cin.nextInt();
            //num = num.pow(n);
            if(p.equals(BigInteger.ZERO) && a.equals(BigInteger.ZERO))break;
            
            //System.out.println("Es primo: " + isPrime(pInt) + "El res de la f(p) = " + a.modPow(p, p));
            
            if(isPrime(pInt) == false && a.modPow(p, p).equals(a))
              System.out.println("yes");
               else
                System.out.println("no");
            
        }
    }
}