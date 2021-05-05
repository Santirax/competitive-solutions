#include <bits/stdc++.h>
using namespace std;

class UnionFind {                                           

private:
  vector<int> p, rank, setSize;                       
  int numSets;

public:
  UnionFind(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; 
  }
    
    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    
    void unionSet(int i, int j) { 
        if (!isSameSet(i, j)) { numSets--; 
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
            else { p[x] = y; setSize[y] += setSize[x];
                if (rank[x] == rank[y]) rank[y]++; 
            } 
        } 
    }
    
    int numDisjointSets() { return numSets; }
    
    int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

int main (){
    
    int T;
    cin>>T;
    while(T--){
        map<string, int> mapa;
        
        int n;
        cin>>n;
        
        UnionFind uf(2*n+1);
        
        string f1, f2;
        int cont = 1;
        for(int i = 0; i < n; i++){
            cin>>f1>>f2;
            
            if(mapa[f1] == 0){
                mapa[f1] = cont;
                cont++;
            }
            
            if(mapa[f2] == 0){
                mapa[f2] = cont;
                cont++;
            }
            
            uf.unionSet(mapa[f1], mapa[f2]);
            
            cout<<uf.sizeOfSet(mapa[f1])<<"\n";
        }
        
    }
    
    
    return 0;
}
