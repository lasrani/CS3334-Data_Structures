#include <iostream>
#include <unordered_map>
#include <deque>
#include <string>
#include <unordered_set>   // if not working change to array
using namespace std;

int main(){
    int n;
    while(cin >> n){
        int essay;
        unordered_set<string> s1;
        unordered_map<string,int> m1;
        string temp;
        int min;

        for(int i=0; i< n;i++){
            cin >> temp;
            s1.insert(temp);
        }

        cin >> essay;
        deque<string> q1;
        
        while(essay--){
            cin >> temp;
            if(s1.count(temp)){
                m1[temp] = 1;
                q1.push_back(temp);
                min = 1;
                break;
            }
        }
        while(essay-- > 0){
            cin >> temp;
            q1.push_back(temp);
            if(s1.count(temp)){
                if(m1.count(temp)) m1[temp]++;
                else{
                    m1[temp] = 1;
                    min = q1.size();
                } 
            }
            while(m1.count(q1.front()) == 0 || m1[q1.front()] > 1){
                if (m1.count(q1.front())) m1[q1.front()]--;               
                q1.pop_front();
                if(min > q1.size()) min = q1.size();
                }
            }
            if(!q1.empty()){
            while(m1.count(q1.back()) == 0 || m1[q1.back()] > 1){
                if (m1.count(q1.back())) m1[q1.back()]--;
                q1.pop_back();
                if(min > q1.size()) min = q1.size();
            }
            }
            cout << m1.size() << endl;
            cout << ((q1.size() > min) ? min : q1.size()) << endl;


    }
    return 0;
}