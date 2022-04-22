#include <bits/stdc++.h>

using namespace std;

int main(){
	
	//ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int t; cin>>t;
	int cont = 1;
	
	cin.ignore();
	
	while(t--){
		
		//cin.ignore();
		//int acum = 0;
		//char s [100000];
		
		string s = "";
		
		char ch;
		do {
			
			ch = getchar();
			s += ch;
			//cout << ch << " ";
			
		} while(ch != '\n'); //Leer hasta el salto de linea
		
		//cout << s ;
		//cout << "\n";
		
		
		//while()	
		//string s;
		//cin>>s;
		
		//cout<<"Impresion s\n";
		//cout<<s<<endl;
		
		int puntero = 0;
		
		//vector<int>display(100, 0);
		vector<int>valores(100, 0);
		
		for(const char & c: s){
			
			if(c == '>'){
				
				if(puntero == 99){
					puntero = 0;
				} else {
					puntero++;	
				}
				
			} else if(c == '<'){
				
				if(puntero == 0){
					puntero = 99;
				} else {
					puntero--;					
				}
				
			} else if(c == '+'){
				
				if(valores[puntero] == 255){
					valores[puntero] = 0;
				} else {
					valores[puntero]++;					
				}
				
			} else if(c == '-'){
				
				if(valores[puntero] == 0){
					valores[puntero] = 255;
				} else {
					valores[puntero]--;	
				}
				
			} /* else if(c == '.'){
				
				display[puntero] = valores[puntero];
			
			}*/
			
		}
		
		cout << "Case " << cont << ": ";
		/*
		for(int i = 0; i < display.size(); i++){
			printf("%X ", display[i]);
		}
		
		cout << "\n";
		*/
		int n = (int)valores.size();
		
		for(int i = 0; i < n; i++){
			
			
			if(valores[i] < 10){
				printf("0%d", valores[i]);
			} else if(valores[i] >= 10 && valores[i] <= 15){
				printf("0%X", valores[i]);	
			}else {
				printf("%X", valores[i]);	
			}
			
			if(i != (n-1)){
				cout << " ";
			}
		}
		
		//printf("Valor es: %X\n", a);
		
		cout << "\n";
		cont++;
		
	} //Fin while
	
	
	return 0;
}