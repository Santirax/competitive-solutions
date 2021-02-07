#include <bits/stdc++.h>
using namespace std;

int main (){
    
    deque <pair<int, int>> childs;
    
    int n, m; cin>>n>>m;
    
    for(int i = 0; i < n; i++){
        int x; cin>>x;
        childs.push_back({x, i+1});
    }
    
    while(childs.size() > 1){
        auto x = childs.front();
        childs.pop_front();
        if(x.first - m > 0){
            childs.push_back({x.first - m, x.second});
        }
    }
    
    cout << childs[0].second << endl;
    
    return 0;
}
