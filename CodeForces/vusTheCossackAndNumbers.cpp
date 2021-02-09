#include <bits/stdc++.h>
using namespace std;

bool isInt(double x){
    double aux = x - (long long)x;
    if(aux == 0)return true;
    
    return false;
}

int main (){
    
    int n; cin>>n;
    vector<double> nums(n);
    long long sum = 0;
    
    for(double & x: nums){
        cin>>x;
        long long aux = (long long)x;
        sum += aux;
    }
    
    //cout << "SUma = " << sum << endl;
    
    if(sum == 0.0){ //Caso en el que sea cero desde el inicio
        for(double x: nums){
            cout << (long long)x << "\n";
            
        }
    } else {
        
        if(sum > 0.0){ //Caso positivo
            
            for(double & x: nums){
                if(x < 0 && !isInt(x)){
                    x = x-1;
                    sum--;
                    if(sum == 0)break;
                }
            }
            
        }else { //Caso negativo
            
            for(double & x: nums){
                if(x > 0 && !isInt(x)){
                    x = x+1;
                    sum++;
                    if(sum == 0)break;
                }
            }
        }
        
        for(double x: nums){
            cout << (long long)x << "\n";
        }
    }
    
    
    
    
    
    return 0;
}
