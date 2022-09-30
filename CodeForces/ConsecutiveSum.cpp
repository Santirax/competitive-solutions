
#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    int t; cin>>t;
    while(t--){
        
        int n, k; cin>>n>>k;
        
        long long sum = 0;
        vector<int> vec(n);
        
        for(int i = 0; i < n; i++){
            int x; cin>>x;
            vec[i] = x;
            sum += x;
        }
        
        if(n == k){
            cout << sum << endl;
        } else {
            
            for(int i = 0; i < n-k; i++){
                int p1 = i;
                int p2 = i+k;
                if(vec[p1] > vec[p2]){
                    swap(vec[p1], vec[p2]);
                }
            }
            
            sum = 0;
            for(int i = n-1; i >= n-k; i--){
                sum += vec[i];
            }
            cout << sum << endl;
        }
        
    }

    return 0;
}
