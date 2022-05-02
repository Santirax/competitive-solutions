#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main (){
	
	int t; cin>>t;
	
	while(t--){
		
		int n; cin>>n;
		
		map<int, int> nums;
		
		bool triple = false;
		int ans = -1;
		
		//cout << "n = " << n << endl; 
		for(int i = 0; i < n; i++){
			int x; cin>>x;
			
			//cout << x << " "; 
			nums[x]++;
			
			if(nums[x] >= 3){
				triple = true;
				ans = x;
				//break;		
			}	
		}
		
		//cout << endl;
		
		if(triple)
			cout << ans << endl;
		else
			cout << "-1\n";
	}
	
	
	
	return 0;
}