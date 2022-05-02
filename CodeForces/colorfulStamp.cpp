#include <bits/stdc++.h>
using namespace std;


bool esValido (string s){
	
	if(s.size() == 0){
		return true;
	} else if(s.size() == 1){
		return false;
	} else {
		
		int red = 0;
		int blue = 0;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == 'R')red++;
			if(s[i] == 'B')blue++;
		}
		
		if(blue == 0 || red == 0)return false;
		
	}
	
	return true;
}


int main (){
	
	int t; cin>>t;
	
	while(t--){
		
		int n; cin>>n;
		
		string s; cin>>s;
		
		
		string aux = "";
		
		bool sePuede = true;
		
		for(int i = 0; i < n; i++){
			
			if(s[i] == 'W'){
				
				if(!esValido(aux)){ 
					sePuede = false;
					break;
				} 
				aux = "";
				
			} else {
				
				aux += s[i];
				
			}
			
		}
		
		if(!esValido(aux)){ 
			sePuede = false;
		} 
		
		cout << ((sePuede == true) ? "YES\n" : "NO\n");
		
	}
	
	
	
	return 0;
}