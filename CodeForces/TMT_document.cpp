#include <iostream>
#include <stack>
using namespace std;
int main (){

  int t; cin>>t;
  while(t--){

    int n; cin>>n;
    string s; cin>>s;

    int TM{}; bool isPos{true};
    stack<char>countT;

    int maxSize = (n/3);

    for(int i = 0; i < s.size(); i++){
      if(s[i] == 'T'){
        countT.push('T');
        if(countT.size() > maxSize){
          isPos = false; break;
        }
      } else {
        if(countT.empty()){
          isPos = false;
          break;
        } else {
          countT.pop();
          TM++;
        }
      }
    }

    if(isPos){
      if(TM == countT.size()){
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    } else {
      cout << "NO\n";
    }
  }



  return 0;
}
