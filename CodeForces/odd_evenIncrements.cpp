#include <bits/stdc++.h>
using namespace std;

int main (){
	
	int t; cin>>t;
	while (t--){
		
		int n; cin>>n;
		
		vector<int> numeros(n);
		
		for(int &x: numeros){
			cin>>x;
		}
		
		//Pares 0
		//Impares 1
		for(int i = 0; i < n; i++){
			numeros[i] = numeros[i] % 2;			
		}
		
		bool sePuede = true;
		
		for(int i = 2; i < n; i+=2){
			if(numeros[i] != numeros[i-2]){
				sePuede = false;		
			}
		}
		
		for(int i = 3; i < n; i+=2){
			if(numeros[i] != numeros[i-2]){
				sePuede = false;
			}
		}
		
		cout << ( (sePuede == true) ? "YES\n" : "NO\n" );

	}
	
	
	
	return 0;
}