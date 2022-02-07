#include <iostream>
#include <sstream>
#include <set>
using namespace std;

int main(){
    string s;
    set<string> s1;
    while(cin>>s){
        string temp = "";
        bool flag = true;
        for(int i =0;i<s.length();i++){
            if(s[i] >= 65 && s[i]<=90){
                temp += s[i] + 32;
                flag = false;
            }
            else if(!((s[i] >= 65 && s[i]<=90) || (s[i] >= 97 && s[i]<= 122))){
                if(flag == false){
                    if(!temp.empty()) s1.insert(temp);
                    temp = "";
                    flag = true;
                }
            }
            else{
                temp += s[i];
                flag = false;
            }
        }
        if(!temp.empty()) s1.insert(temp);
    }
    for(auto a:s1){
        cout << a << endl;;
    }
    return 0;
}