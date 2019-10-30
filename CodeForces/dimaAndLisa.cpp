#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli MAX = sqrt(1e9)+30;
vector<lli>criba(MAX+30, 1);
vector<lli>primos;

bool isPrime(lli N){
    
    for(int i = 0; i < primos.size() && primos[i] < N ; i++){
        if(N % primos[i] == 0)return false;
    }
    
    return true;
}

int main (){
    criba[0] = criba[1] = 0;
    for(lli i = 0; i <= MAX; i++){
        if(criba[i]){
            for(lli j = i*i; j <= MAX; j+=i){criba[j] = 0;}
            primos.push_back(i);

        }    
        
    }
    
    /*for(auto x: primos){
        if(x >= 20)break;
        cout<<x<<" ";
    }*/
    
    lli N;
    cin>>N;
    //El numero dado es primo
    if(isPrime(N))cout<<1<<"\n"<<N<<"\n";
    else{
        //El numero dado se forma con 2 y otro primo
        if(isPrime(N-2))cout<<2<<"\n"<<N-2<<" "<<2<<endl;
        else{
            //Caso 3, tomar el primo mas grande y menor a N y dado la Conjetura de Goldbach
            //Se tiene que cualquier N se puede formar con la suma de dos primos
            cout<<"3\n";
            int i;
            for(i = N; i >= 2; i--){
                if(isPrime(i)){N-=i; break;}
            }
            
            for(int j = 2; j <= N; j++){
                if(isPrime(j) && isPrime(N-j)){cout<<i<<" "<<N-j<<" "<<j<<"\n"; break;}
            }
            
        }
    }
    
    return 0;
}
