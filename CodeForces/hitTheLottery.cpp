

#include <bits/stdc++.h>
using namespace std;

int main (){
    long long n; cin>>n;
    
    long long res = floor((double)n/100.0);
    long long resto1 = n%100;
    
    res += resto1/20;
    resto1 = resto1%20;
    
    res += resto1/10;
    resto1 = resto1%10;
    
    res += resto1/5;
    resto1 = resto1%5;
    
    res += resto1/1;
    resto1 = resto1%1;
    
    cout << res << endl;
}
