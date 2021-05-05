#include <bits/stdc++.h>
using namespace std;

int main (){
    
    int n;
    cin>>n;
    string s1, s2;
    int a, b;
    
    vector<vector<int>> cajas(n);
    
    for(int i = 0; i < n; i++){
        cajas[i].push_back(i);
    }
    
    /*for(int i = 0; i < n; i++){
        cout << i <<":\n";
        for(int j = 0; j < cajas[i].size(); j++){
            cout << cajas[i][j] << " ";
        }
        cout << endl;
    }*/
    
    
    
    while(cin>>s1 && s1 != "quit"){
        cin>>a;
        cin>>s2;
        cin>>b;
        if(a == b)continue;
        
        //cout<<s1<<" "<<a<<" "<<s2<<" "<<b<<endl;
        int posA, posB;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < cajas[i].size(); j++){
                if(cajas[i][j] == a){
                    posA = i;
                } else
                if(cajas[i][j] == b){
                    posB = i;
                }
            }
        }
        
        //cout << "Pos -> "<<posA << " " << posB << endl;
        
        if(posA == posB)continue;
        
        if(s1 == "move"){
            
            if(s2 == "onto"){
                vector<int>aux;
                for(int i = cajas[posA].size()-1; cajas[posA][i] != a; i--){
                    aux.push_back(cajas[posA][i]);
                    cajas[posA].pop_back();
                }
                cajas[posA].pop_back();
                for(int x: aux){
                    cajas[x].push_back(x);
                }
                vector<int> aux2;
                for(int i = cajas[posB].size()-1; cajas[posB][i] != b; i--){
                    aux2.push_back(cajas[posB][i]);
                    cajas[posB].pop_back();
                }
                for(int x: aux2){
                    cajas[x].push_back(x);
                }
                
                cajas[posB].push_back(a);
                
            } else { //over
                vector<int>aux;
                for(int i = cajas[posA].size()-1; cajas[posA][i] != a; i--){
                    aux.push_back(cajas[posA][i]);
                    cajas[posA].pop_back();
                }
                //aux.push_back(a);
                cajas[posA].pop_back();
                
                for(int x: aux){
                    cajas[x].push_back(x);
                }
                cajas[posB].push_back(a);
                
            }
            
        }else{ //Pile
            
            if(s2 == "onto"){
              
                vector<int>aux;
                for(int i = cajas[posA].size()-1; cajas[posA][i] != a; i--){
                    aux.push_back(cajas[posA][i]);
                    cajas[posA].pop_back();
                }
                aux.push_back(a);
                cajas[posA].pop_back();
                
                vector<int> aux2;
                for(int i = cajas[posB].size()-1; cajas[posB][i] != b; i--){
                    aux2.push_back(cajas[posB][i]);
                    cajas[posB].pop_back();
                }
                for(int x: aux2){
                    cajas[x].push_back(x);
                }
                
                for(int i = aux.size()-1; i >= 0; i--){
                    cajas[posB].push_back(aux[i]);
                }
                
                
            } else { //over
                
                vector<int>aux;
                for(int i = cajas[posA].size()-1; cajas[posA][i] != a; i--){
                    aux.push_back(cajas[posA][i]);
                    cajas[posA].pop_back();
                }
                aux.push_back(a);
                cajas[posA].pop_back();
                
                //cout << "La lista de aux:\n";
                /*for(int x: aux)cout << x << " ";
                cout << endl;*/
                
                for(int i = aux.size()-1; i >= 0; i--){
                    cajas[posB].push_back(aux[i]);
                }
            }
        }
        
    }
    
    for(int i = 0; i < cajas.size(); i++){
        cout<<i<<":";
        if(cajas[i].size() >= 1)cout << " ";
        for(int j = 0; j < cajas[i].size(); j++){
            if(j == cajas[i].size()-1){
                cout << cajas[i][j];
            } else {
                cout << cajas[i][j] << " ";
            }
        }
        cout << endl;
    }
    //cout << "\n";
    
    
    return 0;
}
