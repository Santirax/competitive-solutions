import java.math.*;
import java.util.*;

public class highPrecisionNumber{
  public static void main(String arg[]){
   Scanner cin = new Scanner(System.in);
   BigDecimal res = BigDecimal.ZERO;
   BigDecimal cero = BigDecimal.ZERO;
   int N;
   N = cin.nextInt();
   for(int i = 0; i < N; i++){
     res = cero;
     BigDecimal x;
     while(true){
       x = cin.nextBigDecimal();
       if(x.equals(cero))break;
       res = res.add(x);
     }
     if( res.equals(cero) )
       System.out.println("0");
            else {
              //  ans = ans.stripTrailingZeros();
                System.out.println( res.stripTrailingZeros().toPlainString() );
            }
   }
  
  }
}

/*public class Main {

 static BigDecimal get(long n){return BigDecimal.valueOf(n);}
    static BigDecimal mul(BigDecimal x , BigDecimal y){ return x.multiply(y);}
    static BigDecimal sub(BigDecimal x , BigDecimal y){ return x.subtract(y);}
    static BigDecimal add(BigDecimal x , BigDecimal y){ return x.add(y);}
    static BigDecimal div(BigDecimal x , BigDecimal y){ return x.divide(y);}
   // static BigDecimal mod(BigDecimal x , BigDecimal y){ return x.mod(y);}
    

    public static void main(String args[])
    {
        Scanner ob = new Scanner(System.in);
        int test = ob.nextInt();
        while(test-->0){
            BigDecimal ans = get(0);
            while(true){
                BigDecimal x = ob.nextBigDecimal();
                if( x.equals( get(0) ))break;
                ans = add(ans,x);
            }
            
            if( ans.compareTo( get(0) ) == 0 ) System.out.println("0");
            else {
              //  ans = ans.stripTrailingZeros();
                System.out.println( ans.stripTrailingZeros().toPlainString() );
            }
}
    }
}*/
