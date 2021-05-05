/*
 Se resuelve haciendo una dfs sobre el arbol y contando el numero de
 componentes, y se van contando si son componentes de mas de un nodo o de mas de un
 nodo. Como dato hice un map con las letras, para que fuera mas facil trabajar con el
 grafo.
 */
#include <bits/stdc++.h>
using namespace std;
typedef bitset<26> vb;
typedef vector<vector<int>> vvi;

int cont = 0;
inline void dfs(vvi & graph, vb & vis, int ini){
    vis[ini] = true;
    for(int i = 0; i < graph[ini].size(); i++){
        int u = graph[ini][i];
        if(!vis[u]){
            cont++;
            dfs(graph, vis, u);
        }
    }
}

int main (){
    
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    
    int t; cin>>t;
    while(t--){
        vb vis;
        vvi graph(26);
        string s;
        while(cin>>s && s[0] != '*'){
            int u = s[1] - 'A';
            int v = s[3] - 'A';
            graph[u].push_back(v);
            graph[v].push_back(u);
            
        }
        cin>>s;
        unordered_set<int> letters;
        for(int i = 0; i < s.size(); i++){
            if(i % 2 == 0)letters.insert(s[i]-'A');
        }
        
        //for(int x: letters)cout << x <<" ";
        //cout << endl;
            
        cont = 1;
        int x = 0, y = 0;
        for(int i = 0; i < 26; i++){
            if(letters.count(i)){
                if(!vis[i]){
                    cont = 1;
                    dfs(graph, vis, i);
                    if(cont > 1)x++; else y++;
                }
                
            }
        }
        
        cout << "There are "<<x<<" tree(s) and "<<y<<" acorn(s).\n";
        
        /*for(auto x: graph){
            cout << cont << ":\n";
            for(auto y: x){
                cout << y << " ";
            }
            cout << endl;
            cont++;
        }
        
        for(int x: letters)cout<<x<<" ";
        cout << endl;
        
        cout << "TERMINA EL CASO\n";*/
    }
    
    
    
    return 0;
}
