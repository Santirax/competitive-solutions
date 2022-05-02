#include <bits/stdc++.h>
using namespace std;

int main (){
	
	int t; cin>>t;
	while(t--){
		
		int division; cin>>division;
		
		if(division <= 1399){
			cout << "Division 4\n";
		}else if(division >= 1400 && division <= 1599){
			cout << "Division 3\n";
		}else if(division >= 1600 && division <= 1899){
			cout << "Division 2\n";
		}else {
			cout << "Division 1\n";
		}
		
	}
	
	
	
	return 0;
}
