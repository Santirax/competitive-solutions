#include <bits/stdc++.h>
using namespace std;

int numDiv(int x){
    
    int exp = 0;
    int div = 1;
    for(int i = 2; i <= sqrt(x); i++){
        
        while(x % i == 0){
            x/=i;
            exp++;
        }
        
        div *= (exp+1);
        exp = 0;
    }
    
    if(x > 1){
        div *= 2;
    }
    
    return div;
    
}

int main (){

    int N;
    vector<int>criba(3e6, 1);
    //bitset<1000000>criba;
    //criba.set();
    //vector<int>primos;
    criba[0] = criba[1] = 0;
    int size = 100;
    for(int i = 2; i <= size; i++){
        if(criba[i]){
            for(int j = i*i; j <= size; j+=i){
                criba[j] = 0;
            }
        }
            
    }
    
    /*for(int i = 0; i < size; i++)
        cout<<criba[i]<<" ";*/
    
    //cout<<endl;
    
    
    cin>>N;
    while(N--){
        
        int ini, fin;
        cin>>ini>>fin;
        vector<int>divPrimo;
        
        for(int i = ini; i <= fin; i++){
            int div = numDiv(i);
            //cout<<"el num div de" <<i<<" es: "<<div<<endl;
            if(criba[div] == 1){
                divPrimo.push_back(i);
            }
        }
        
        if(divPrimo.size() == 0){
            cout<<-1; 
        }else{
            
          for(int i = 0; i < divPrimo.size(); i++){
              cout<<divPrimo[i];
              if(i != (divPrimo.size()-1))cout<<" ";
          }
            
        }
        
        cout<<endl;
        
    }   

    
    return 0;
}