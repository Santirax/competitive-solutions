#include <bits/stdc++.h>
using namespace std;

int cont = 1;

void dfs(int ini, vector<vector<int>> &lista, vector<bool> &vis){
	
	vis[ini] = true;
	for(int i = 0; i < lista[ini].size(); i++){
		
		int nodo = lista[ini][i];
		
		if(!vis[nodo]){
			cont++;
			dfs(nodo, lista, vis);
		}
		
	}

}

int main (){
	
	int n, m;
	
	while(cin>>n>>m && n != 0 && m != 0){
		
		vector<vector<int>> lista(n);
		vector<bool> vis(n, false);
		
		for(int i = 0; i < m; i++){
			
			int u, v, p; cin>>u>>v>>p;
			
			lista[u-1].push_back(v-1);			
			if(p == 2){
				lista[v-1].push_back(u-1);
			}
			
		}
		
		bool seCumple = true;
		
		for(int i = 0; i < n; i++){
			cont = 1;
			
			vis.assign(n, false);
			dfs(i, lista, vis);
			
			if(cont != n){
				seCumple = false; break;
			}
			
		}
		
		if(seCumple) cout << 1 << endl; else cout << 0 << endl;
		
	}
	
	
	return 0;
}