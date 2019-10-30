#include <bits/stdc++.h>
using namespace std;

int n;
vector<int>rot;

int lock(int i, int val){
 //cout<<i<<" "<<val<<endl;
 if( (val == 0 && i == n) || (val%360 == 0 && i == n))return 1;
 if(i >= n)return 0;
 return max(lock(i+1, val+rot[i]), lock(i+1, val-rot[i]));
}


int main(){

  int x;
  cin>>n;
  for(int i = 0; i < n; i++){
    cin>>x;
    rot.push_back(x);
  }

 if(lock(0, 0) >= 1)cout<<"YES\n"; else cout<<"NO\n"; 

}
