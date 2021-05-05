#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

ll sieve_size = 1e6; // ll is defined as: typedef long long ll;

bitset<10000010> bs; // 10^7 should be enough for most cases

vi primes; // compact list of primes in form of vector<int>

/*Criba de Eratostenes*/
void sieve() { // create list of primes in [0..upperbound]
   sieve_size++; // add 1 to include upperbound
   bs.set(); // set all bits to 1
   bs[0] = bs[1] = 0; // except index 0 and 1
   for (ll i = 2; i <= sieve_size; i++) if (bs[i]) {
     // cross out multiples of i starting from i * i!
      for (ll j = i * i; j <= sieve_size; j += i) bs[j] = 0;
       primes.push_back((int)i); // add this prime to the list of primes
   } 
}

/*Sacar los factores de un numero*/
vi primeFactors(ll N) { // remember: vi is vector<int>, ll is long long
 vi factors;
 ll PF_idx = 0, PF = primes[PF_idx]; // primes has been populated by sieve
 while (PF * PF <= N) { // stop at sqrt(N); N can get smaller
   while (N % PF == 0) { N /= PF; factors.push_back(PF); } // remove PF
   PF = primes[++PF_idx]; // only consider primes!
 }
 
 if (N != 1) factors.push_back(N); // special case if N is a prime
 return factors; // if N does not fit in 32-bit integer and is a prime
}

/*Funcion que te dice cuantos coprimos existen antes de N*/
ll EulerPhi(ll N, vector<int>primes) {
 ll PF_idx = 0, PF = primes[PF_idx], ans = N; // start from ans = N
 while (PF * PF <= N) {
   if (N % PF == 0) ans -= ans / PF; // only count unique factor
   while (N % PF == 0) N /= PF;
   PF = primes[++PF_idx];
 }
 
 if (N != 1) ans -= ans / N; // last factor
 return ans;
}

int main (){
    int N;
    sieve();
    while(cin>>N && N != 0){
        if(N == 1)cout<<1<<endl;
        else{
        ll res = EulerPhi(N, primeFactors(N));
        cout<<res<<endl;
        }
    }
 
 
 return 0;
}