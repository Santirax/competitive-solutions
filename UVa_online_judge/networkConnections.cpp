#include <bits/stdc++.h>
#define endl "\n"
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
          //cin.ignore(numeric_limits<int>::max(),'\n');
        //cout<<"T = "<<T<<"\n";
        int n;
        cin>>n;
        //cout<<"n = "<<n<<endl;
        UnionFind uf(n+1);
        
        int si = 0, no = 0;
        string s;
        int u, v;
        char c;
        cin.ignore();
        while(true){
            
            getline(cin, s);
            //cout<<s<<"\n";
            
            if(s.compare("") == 0){
                //cout<<"salto\n";
                break;
                
            }else {
                stringstream ss(s);
                ss>>c>>u>>v; 
            }
            //u--, v--;
            //cout<<c<<" "<<u<<" "<<v<<"\n";
            
            if(c == 'c'){
                uf.unionSet(u,v);
            }else if (c == 'q'){
                if(uf.isSameSet(u, v)) si++; else no++; 
            }
            
        }
        cout<<si<<","<<no<<"\n";
        if(T)cout<<"\n";
        //cin.ignore();
        
    }
    
    return 0;
}
