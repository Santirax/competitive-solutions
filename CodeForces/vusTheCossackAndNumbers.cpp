#include <bits/stdc++.h>
using namespace std;

bool esDoble(double n){
  if(n - (int)n != 0)return true;
  return false;
}

int main (){
 int n;
 cin>>n;
 vector<double>num(n);
 int sum = 0;
 //int pos = 0, neg = 0;
 for(int i = 0; i < n; i++){
  cin>>num[i];
  int temp = (int)num[i];
  sum += temp;
  //cout<<temp<<" y "<<sum<<"\n";
  //if(num[i] >= 0)pos++; else neg++;
 }
 //cout<<sum<<endl<<endl;

 vector<int>res(n);
 if(sum > 0){
   for(int i = 0; i < n; i++){
     if(num[i] < 0 && sum != 0 && esDoble(num[i])){
        res[i] = (int)num[i] - 1;
        sum--;
     }else{
       res[i] = (int)num[i];
     }
   }
 }else if(sum < 0){
   for(int i = 0; i < n; i++){
      if(num[i] > 0 && sum != 0 && esDoble(num[i])){
        res[i] = (int)num[i] + 1;
        sum++;
      }else{
        res[i] = num[i];
      }
   }
 }else{
   for(int i = 0; i < n; i++)res[i] = (int)(num[i]);
 }


 //cout<<sum<<endl;
 for(int x: res)cout<<x<<"\n";

 return 0;
}
