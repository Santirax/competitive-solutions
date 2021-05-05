#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s){
    
    for(int i = 0, j = s.size()-1; i < s.size()/2; i++, j--){
        if(s[i] != s[j])return false;
    }
    return true;
}

bool isMirrored(string s){
    map<char, char> dictionary;
    dictionary['A'] = 'A';
    dictionary['E'] = '3';
    dictionary['3'] = 'E';
    dictionary['H'] = 'H';
    dictionary['I'] = 'I';
    dictionary['J'] = 'L';
    dictionary['L'] = 'J';
    dictionary['M'] = 'M';
    dictionary['O'] = 'O';
    dictionary['S'] = '2';
    dictionary['2'] = 'S';
    dictionary['T'] = 'T';
    dictionary['U'] = 'U';
    dictionary['V'] = 'V';
    dictionary['W'] = 'W';
    dictionary['X'] = 'X';
    dictionary['Y'] = 'Y';
    dictionary['Z'] = '5';
    dictionary['5'] = 'Z';
    dictionary['1'] = '1';
    dictionary['8'] = '8';
    
    
    if(s.size() % 2 == 1){
        int mid = s.size()/2;
        if(!dictionary.count(s[mid]))return false;
    }
    
    for(int i = 0, j = s.size()-1; i < s.size()/2; i++, j--){
        
        if(dictionary.count(s[i])){
            if(s[j] != dictionary[s[i]])
                return false;
        }else{
            return false;
        }
    }
    return true;
    
}


int main (){
    
    
    
    
    string s;
    
    while(cin>>s){
        
        cout << s;
        
        if(isPalindrome(s)){
            
            if(isMirrored(s)){
                cout << " -- is a mirrored palindrome.";
            }else{
                cout << " -- is a regular palindrome.";
            }
            
        }else{
            
            if(isMirrored(s)){
                cout << " -- is a mirrored string.";
            }else{
                cout << " -- is not a palindrome.";
            }
        }
        
       cout << "\n\n"; 
    }
    
    
    
    
    
    
    
    return 0;
}
