#include <bits/stdc++.h>
using namespace std;
int main (){

  int n;
  cin>>n;
  vector<int>buck(1e5+1, 1);

  if(n <= 3){
    cout<<"NO\n";
  }else{
    cout<<"YES\n";
    if(n == 4){
      cout<<"4 * 3 = 12\n";
      cout<<"12 * 2 = 24\n";
      cout<<"24 * 1 = 24\n";
    }else if(n == 5){
      cout<<"5 * 4 = 20\n";
      cout<<"2 - 1 = 1\n";
      cout<<"3 + 1 = 4\n";
      cout<<"20 + 4 = 24\n";
    }else{
      cout<<"6 * 4 = 24\n";
      if(n % 2 == 0){
        for(int i = n; i >= 7; i-=2){
          cout<<i<<" - "<<i-1<<" = 1\n";
        }
        cout<<"5 - 3 = 2\n";
        cout<<"2 - 2 = 0\n";
        for(int i = 0; i < (n-6)/2 + 1; i++)
          cout<<"24 * 1 = 24\n";
        cout<<"24 + 0 = 24\n";

      }else{
        for(int i = n; i >= 8; i-=2)
          cout<<i<<" - "<<i-1<<" = 1\n";
        cout<<"7 - 5 = 2\n";
        cout<<"3 - 2 = 1\n";
        cout<<"2 - 1 = 1\n";

        for(int i = 0; i < (n-7)/2 + 2; i++)
          cout<<"24 * 1 = 24\n";
      }
     }
  }

  return 0;
}
