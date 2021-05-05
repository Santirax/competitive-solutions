//#include <bits/stdc++.h>
#include <iostream>
#include <queue>
using namespace std;
int main ()
{
    
    int N;
    while(cin>>N && N != 0)
    {
        //Poner la pila de menor a mayor
        priority_queue< int, vector<int>, greater<int> > numeros;
        for(int i = 0; i < N; i++)
        {
            int x;
            cin>>x;
            numeros.push(x);
        }
        
        int cost = 0;
        while(numeros.size() > 1)
        {
            int aux = numeros.top();
            numeros.pop();
            cost += aux+numeros.top();
            numeros.push(aux+numeros.top());
            numeros.pop();
        }
        
        cout<<cost<<endl;
        
    }
    
    
    
    
    
    return 0;
}
