#include <iostream>
using namespace std;
int main ()
{
 int N;
 cin>>N;
 for(int i = 0; i<N; i++)
 {
   long long int a, b;
   cin>>a>>b;
   if (a>b)
    cout<<">\n";
      else if (b>a)
       cout<<"<\n";
         else
           cout<<"=\n";
 }


 return 0;
}
