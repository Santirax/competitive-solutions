#include <bits/stdc++.h>
using namespace std;

int cmin (vector <int> & c){
    int mini = 1e6; int pos;
    pair<int, int> p;
    for(int i = 0; i < 3; i++){
        if(c[i] < mini){
            mini = c[i];
            //p.first = mini;
            pos = i;
        }
    }
    return pos;
}

int cmax (vector <int> & c){
    int maxi = -1; int pos;
    pair<int, int> p;
    for(int i = 0; i < 3; i++){
        if(c[i] > maxi){
            maxi = c[i];
            pos = i;
        }
    }
    return pos;
}

int main (){
    
    int t; cin>>t;
    while(t--){
        
        int n; cin>>n;
        //int c0 = 0, c1 = 0, c2 = 0;
        vector<int> c(3, 0);
        for(int i = 0; i < n; i++){
            int x;
            cin>>x;
            if(x % 3 == 0)c[0]++;
            if(x % 3 == 1)c[1]++;
            if(x % 3 == 2)c[2]++;
        }
        
        int niveles = n / 3;
        int cont = 0;
        while(c[0] != niveles || c[1] != niveles || c[2] != niveles){
            
            int max_pos = cmax(c);
            int min_pos = cmin(c);
            
            c[max_pos]--;
            c[min_pos]++;
            
            if(max_pos == 2 && min_pos == 1)cont+=2;
            else if(max_pos == 0 && min_pos == 2)cont+=2;
            else if(max_pos == 1 && min_pos == 0)cont+=2;
            else cont++;
            
        }
        cout << cont << endl;
    }
    
    
    return 0;
}
