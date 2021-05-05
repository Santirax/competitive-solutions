#include <iostream>
#include <cmath>
using namespace std;

int main (){

  int t; cin>>t;
  while (t--) {
    int x, y;
    cin>>x>>y;
    int x1 = floor(x/3);
    int y1 = floor(y/3);
    cout << (x1 * y1) << "\n";
  }

  return 0;

}
