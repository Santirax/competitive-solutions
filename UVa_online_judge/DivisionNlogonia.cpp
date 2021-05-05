#include <iostream>
using namespace std;
int main ()
{
	
	int k=1, m, n, x, y, i;
	
  while(cin>>k && k!=0)
  {
	
	cin>>m>>n;
	
	for (i=0; i<k; i++)
	{
		cin>>x>>y;
		if (x>m) //x mayor
		{
			if(y > n) //y mayor
			{
				cout<<"NE\n";
				
			} else if (y < n) // y menor
			  {
			  	cout<<"SE\n";
			  	
			  } else { //Igual a cero
			  	
			  	cout<<"divisa\n";
			  	
			  }
			
		} else if(x<m) //x menor
		   {
		   	 if(y > n)
			 {
				
				cout<<"NO\n"; 
				
			 } else if (y < n)
			   {
			   	
			  	 cout<<"SO\n";
			  	
			   } else {
			  	
			  	 cout<<"divisa\n";
			   
		         }
		   	  
		   } else //x cero
		     { 
		     
			    cout<<"divisa\n";
			 
			 }
		
	 }
	
   }	
	
	return 0;
}
