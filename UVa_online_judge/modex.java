import java.util.Scanner;
import java.math.BigDecimal;
import java.math.BigInteger;
//import java.math.sqrt;

public class modex
{
    /*public static boolean isPrime (int p){
    
        for(int i = 2; i <= Math.sqrt(p); i++){
            if(p % i == 0)return false;
        }
       return true;
    }*/

    public static void main(String[] args)
    {
        Scanner cin = new Scanner(System.in);
        
        int N = cin.nextInt();
        while (N != 0)
        {
            N--;
            //BigDecimal num = cin.nextBigDecimal();
            BigInteger x = cin.nextBigInteger();
            BigInteger y = cin.nextBigInteger();
            BigInteger n = cin.nextBigInteger();
            
            BigInteger z = x.modPow(y, n);
            
            System.out.println(z);
            
        }
    }
}