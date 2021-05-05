#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

vector<lli>primos;

/*Funcion para suma los divisores de un numero*/
lli sumDiv(lli N){
    lli PF_idx = 0, PF = primos[PF_idx], ans = 1;
    while(PF*PF <= N){
        lli power = 0;
        while(N % PF == 0){N/=PF; power++;}
        ans *= ((lli)pow((double)PF, power + 1.0) -1 )/(PF - 1);
        PF = primos[++PF_idx];
    }
    if(N != 1) ans *= ((lli)pow((double)N, 2.0) -1 )/(N - 1);    
    
    return ans;
}


void Erastotenes(){
    
    vector<lli>criba (1e5, 1);
    criba[0] = criba[1] = 0;
    for(int i = 0; i <= 1000; i++){
        if(criba[i]){
            for(int j = i*i; j <= 1000; j+=i){
                criba[j] = 0;
            }
            primos.push_back(i);
        }
    }
    
}

int main (){
    Erastotenes();
    
    /*Mapa del numero y la suma de sus divisores*/
    map<int , int> sumaDivs;
    //cout<<primos.size()<<endl;
    int sum = 0;
    for(int i = 1; i <= 1000; i++){
        sum = sumDiv(i);
        /*Mapa de llave tiene las suma de los divisores de un numero i, y de valor el numero i*/
        sumaDivs[sum] = i; 
        //cout<<sum<<endl;
    }
    //int suma = 0;
    /*for(int i = 0; i < primos.size(); i++){
        suma += primos[i];
    }*/
    //cout<<suma<<endl;
    int N;
    int cont = 1;
    while(cin>>N && N != 0){
        cout<<"Case "<<cont<<": ";
        if (sumaDivs[N] == 0)
             cout<<-1<<"\n";
        else
            cout<<sumaDivs[N]<<endl;
        cont++;
        
    }
    

 return 0;
}
