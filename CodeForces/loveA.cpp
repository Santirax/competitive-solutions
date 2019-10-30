#include <bits/stdc++.h>
using namespace std;
int main (){
 string s;
 cin>>s;
 int contA = 0;
 for(int i = 0; i < s.size(); i++){
   if(s[i] == 'a')contA++;
 }

 int other = s.size()-contA;
 if(contA > other)cout<<s.size()<<"\n";
 else{
   while(other > contA)--other;
   other--;

   //cout<<"Other = "<<other<<"\n";
   //cout<<"ContA = "<<contA<<"\n";
   cout<<other+contA<<"\n";

 }
//int cont = 0;
 return 0;
}
