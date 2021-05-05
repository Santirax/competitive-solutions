#include <iostream>
using namespace std;
int main ()
{


int N, P;
int con = 0;
string req[10000];
string req_marca_s[10000];
string marca, marcaBuena = "algo";
long double precio, marca_req_f, precioBueno = 1000000, dif = 100000, dif_cont;

while(cin>>N && cin >>P && N != 0 && P != 0)
{
 con++;
 if(con != 1)
 cout<<"\n";

 cin.ignore();
 precioBueno = 1000000, dif = 100000;
 for(int x = 0; x<N; x++)
 {
  //cin.ignore();
  getline(cin, req[x]);
  //cout<<req[x]<<endl;
 }

 for (int x = 0; x<P; x++)
 {
   getline(cin, marca);
   cin>>precio;
   cin>>marca_req_f;
    
   //cout<<marca<<endl;
   //cout<<precio<<endl;
   //cout<<marca_req_f;
   
   cin.ignore();
   for(int y = 0; y < marca_req_f; y++)
   {
    getline(cin, req_marca_s[y]);
   } 
   
     dif_cont = N-marca_req_f;
    if(dif_cont < dif ) 
    { 
       marcaBuena = marca;
       precioBueno = precio;
       dif = dif_cont;
       //cout<<marcaBuena<<endl;
       //cout<<precioBueno<<endl;
       //cout<<dif<<endl;
    }
      if(precio < precioBueno && dif_cont== dif)
      {
        marcaBuena = marca;
        precioBueno = precio;
        dif = dif_cont;
        //cout<<marcaBuena<<endl;
        //cout<<precioBueno<<endl;
        //cout<<dif<<endl; 
       }
    

 }

//cout<<N<<" y "<<P<<endl;
cout<<"RFP #"<<con<<"\n";
cout<<marcaBuena<<endl;
//con++;

}

return 0;
}
