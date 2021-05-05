#include <iostream>
using namespace std;
int main ()
{
  int T, N, may, c;
  cin>>T;
  for (int x = 1; x<=T; x++)
  {   
      cin>>N;
      cin>>c;
      may = c;
      for(int y = 1; y < N; y++)
      {
        cin>>c;
        if (c > may)
         may = c;
      }
      cout<<"Case "<<x<<": "<<may<<endl;
  }


return 0;
}
