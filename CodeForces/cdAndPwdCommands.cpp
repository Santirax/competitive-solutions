#include <iostream>
#include <vector>

using namespace std;

int main (){

  int n; cin>>n;
  vector<string>rutes;
  while(n--){
    string s;
    cin>>s;
    if(s[0] == 'p'){
      cout << "/";
      for(string rute: rutes){
        cout <<rute << "/";
      }
      cout << "\n";

    } else {
      string rute; cin>>rute;
      //cout << rute << endl;
      if(rute[0] == '/')rutes.clear();
      
      string folder{};
      for(int i = 0; i < rute.size(); i++){
        //cout << i << " -> " << rute[i] << endl;
        if(rute[i] == '.' && rute[i+1] == '.'){
          if(rutes.size() >= 1)
            rutes.pop_back();
          i+=2;
        } else if(rute[i] == '/'){
          if(folder != "")
            rutes.push_back(folder); folder = "";
        } else {
          folder += rute[i];
        }
      }
      if(folder != "")
        rutes.push_back(folder);


    }


  }




  return 0;
}
