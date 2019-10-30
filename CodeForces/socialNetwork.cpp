#include <bits/stdc++.h>
using namespace std;
int main (){

  int n, k;
  cin>>n>>k;

  vector<long long>ids(n);
  for (int i = 0; i < n; i++){
    cin>>ids[i];
  }

  set<long long>exist;
  deque<long long > screen;

  for(int i = 0; i < n; i++){

    if(exist.count(ids[i]) == 0){

      if(screen.size() == 0){

        screen.push_back(ids[i]);
        exist.insert(ids[i]);

      }else if(screen.size() == k){

        long long  aux = screen.back();
        exist.erase(aux);

        screen.pop_back();
        screen.push_front(ids[i]);
        exist.insert(ids[i]);

      }else{
        screen.push_front(ids[i]);
        exist.insert(ids[i]);
      }
    }
  }

  cout<<screen.size()<<endl;
  for(long long a: screen){
    cout<<a<<" ";
  }

  cout<<endl;


  return 0;
}
