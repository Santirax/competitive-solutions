#include <bits/stdc++.h>
using namespace std;
int acarreo(int sum){
 if (sum < 10)
   return 0;
 else if(sum >= 10 && sum < 20)
   return 1;
 else if(sum >= 20 && sum < 30)
   return 2;
 else if(sum >= 30 && sum < 40)
   return 3;
 else if(sum >= 40 && sum < 50)
   return 4;
 else if(sum >= 50 && sum < 60)
   return 5;
 else if(sum >= 60 && sum < 70)
   return 6;

 return 0;
}
int main (){

  string n1, n2;
  int cont = 0;
  while(cin>>n1>>n2){
   cont++;
   //cout<<cont<<" .-  "<<n1<<" "<<n2<<endl;
   if(n1 == "0" && n2 == "0")break;
   int carryAux = 0;
   int carryRes = 0;
   int sum = 0;
   int i, j;
   for(i = n1.size()-1, j = n2.size()-1; i >= 0 && j >= 0; i--, j--){
      sum = (n1[i] - '0') + (n2[j] - '0') + carryAux;
      //cout<<sum<<" "<<n1[i]<<" "<<n2[j]<<endl;
      if(sum >= 10)carryRes++;
      carryAux = acarreo(sum);
      //sum = 0;
   }
   
   if(i > -1){
    for(; i >= 0; i--){
      sum = n1[i]-'0' + carryAux;
      if(sum >= 10)carryRes++;
      carryAux = acarreo(sum);
    }
   }
   if(j > -1){
    for(; j >= 0; j--){
     sum = n2[j]-'0' + carryAux;
     if(sum >= 10)carryRes++;
     carryAux = acarreo(sum);
    }
   }
   

   if(carryRes == 0)
     cout<<"No carry operation.\n";
      else if(carryRes == 1)
       cout<<carryRes<<" carry operation.\n";
         else
           cout<<carryRes<<" carry operations.\n";
  }


  return 0;
}
