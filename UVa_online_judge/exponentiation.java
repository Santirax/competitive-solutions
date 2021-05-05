/*import java.io.*;
import java.util.*;
import java.math.*;
public class exp{
   public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		//out = new PrintWriter(new BufferedOutputStream(System.out));
		while(sc.hasNext()){
		  BigDecimal N =  sc.nextBigDecimal();
		  int n = sc.nextInt();
		  N = N.pow(n);
		  String s = N.stripTrailingZeros().toPlainString();
		  if(s.charAt(0) == '0'){
		    s = s.substring(1);
		  }
		  System.out.println(s);
		}
		//out.close();
	}

}*/

import java.util.Scanner;
import java.math.BigDecimal;

public class Main
{

    public static void main(String[] args)
    {
        Scanner cin = new Scanner(System.in);

        while (cin.hasNext())
        {
            BigDecimal num = cin.nextBigDecimal();
            int n = cin.nextInt();
            num = num.pow(n);

            String s = num.toPlainString();
            if (s.charAt(0) == '0')
                s = s.substring(1);

            int end = s.length();
            while (s.charAt(end - 1) == '0')
                end--;
            if (s.charAt(end - 1) == '.')
                end--;
            s = s.substring(0, end);
            System.out.println(s);
        }
    }
}