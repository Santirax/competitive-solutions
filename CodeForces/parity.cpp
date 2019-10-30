#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main (){
    
    ll b, k;
    cin>>b>>k;
    vector<ll>coef(k+1, 0);
    for(int i = 0; i < k; i++)
        cin>>coef[i];
    
    // ( a1*b^k1 + a2*b^k-2 + ... + ak-1*b + ak ) % 2 -> (x%2 + y%2 + z%2)%2, (a*b)%2 => (a%2*b%2)%2
    ll base = b%2;
    ll sum = 0;
    for(int i = 0; i < k-1; i++){
        sum += ((coef[i]%2)*base)%2;
    }
    sum += coef[k-1]%2;
    
    if(sum%2 == 1) cout<<"odd\n"; else cout<<"even\n";
    
    
    return 0;
}



/*#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define ll long long


int main() {
    ios_base :: sync_with_stdio(false);
    ll b, k;
    cin >> b >> k;
    //vector <ll> arr(k);
    ll x;
    ll sum = 0;
    b = b%2;
    for(int i = 0; i < k-1; i++){
        cin >> x;
        x = x%2;
        sum += x*b;
    }
    cin >> x;
    sum += x%2;
    if (sum%2)
        cout << "odd";
    else
        cout << "even";

}*/
