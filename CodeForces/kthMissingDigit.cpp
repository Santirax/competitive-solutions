#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//Suma de digitos de un numero
int digitSum(string number) {
  ll sum {};
  for (char digit : number) sum += (digit - '0');
  if (sum < 10) return sum;
  return digitSum(to_string(sum));

}

int main (){

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  ll a, b, p;
  cin>>a>>b>>p;

  string A, B, P;
  cin>>A>>B>>P;

  int digitSumResult = digitSum(to_string(digitSum(A) * digitSum(B)));

  int index = -1;
  for(int i = 0; i < P.size(); i++){
    if(P[i] == '*'){
      index = i; break;
    }
  }

  for (char i = '1'; i <= '9'; ++i) {
    P[index] = i;
    if (digitSum(P) == digitSumResult) {
      cout << i << endl;
      break;
    }
  }

  return 0;
}
