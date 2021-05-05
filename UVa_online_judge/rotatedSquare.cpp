#include <iostream>
#define T 500
using namespace std;
int main ()
{
long long int n, N;
int contRot;
int cont[4];//Contador para el numero de veces que se repite la cadena
int con = 0;//contador por cada carácter que es igual
int contAr=0; //contador del arreglo cont[0];
/*Arreglo auxiliar*/
char big [T][T];
char small [T][T];

while (cin>>N && cin>>n && N!=0 && n!=0)
{
  //cin>>n;
 //cout<<N<<" y "<<n<<endl;


for(int x = 0; x < N; x++)
{
  for (int y = 0; y < N; y++)
  {
    cin>>big[x][y];
  }
}


for(int x = 0; x < n; x++)
{
  for (int y = 0; y<n; y++)
  {
    cin>>small[x][y];
  }
}




//while que controla todo el proceso, comparación, rotación y comparación por cada rotación
contRot = 1;
while(contRot <= 4)
{

/*cout<<"Matriz a comparar:\n"<<endl;
for(int x = 0; x < n; x++)
{
  for (int y = 0; y<n; y++)
  {
    cout<<small[x][y];
  }
 cout<<"\n";
}

cout<<"\n";*/



con=0;
for(int i = 0; i < N; i++)
{
 for (int j = 0; j < N; j++)
 {
  for (int x = 0; x < n; x ++)
  {
    for (int y = 0; y < n; y++)
    {
      if (small[x][y] == big[x+i][y+j])
      {
         con++;
         if (con == (n*n))
         {
             //cout<<"Iguales\n";
             cont[contAr]+=1;
         }

      }
      
    }
   //cout<<"\n";
  }
  //cout<<"\n";
  con =0;
 }
 //cout<<"\n";
}



/*ROTAR LA MATRIZ PEQUEÑA*/

char small2 [n][n];

for(int x = 0; x < n; x++)
{
  for (int y = 0; y<n; y++)
  {
    small2[x][y] = small[x][y];
    //cout<<"Impression del small 2: "<<small2[x][y]<<"\n";
  }
 //cout<<"\n";
}


/*Rotamos la Matriz usando el auxiliar*/
for(int x = 0; x < n; x++)
{
  for (int y = n-1, aux_y = 0; y>=0 && aux_y<n; y--, aux_y++)
  {
    //cout<<small[x][aux_y] <<" y " <<small[y][x]<<"\n";
    small[x][aux_y] = small2[y][x];
  }
  //cout<<"\n";
}


contRot++;//Controla el numero de rotaciones que llevamos
contAr++; //Controla la posición del arreglo por rotaciones que son

}//Fin del while padre

if(n==N && big[0][0] == small[0][0])
cout<<1<<" "<<1<<" "<<1<<" "<<1<<endl;
else
cout<<cont[0]<<" "<<cont[1]<<" "<<cont[2]<<" "<<cont[3]<<endl;

for(int x = 0; x< 4; x++)
cont[x] = 0;//Contador para el numero de veces que se repite la cadena

con = 0;//contador por cada carácter que es igual
contAr=0; //contador del arreglo cont[0];

}



return 0;
}
