#include <iostream>
#include <deque>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
    int times;
    cin >> times;
    while(times--){
        deque<int> c1;
        int num;
        cin >> num;

        string str;
        getline(cin, str);

        stringstream ss(str);

        while(num--){
            getline(cin, str);
            stringstream ss(str);

            char c;
            ss >> c;

            if (c == 'Q') {
                int which;
                ss >> which;
                cout << *(c1.begin() + which -1) << endl;
            }
            else if(c == 'R') {
                char p;
                ss >> p;
                if(p == 'H') 
                    c1.pop_front(); 
                else 
                c1.pop_back();
            }
            
            else{
                char w;
                int val;
                ss >> w;
                ss >> val;
                if(w == 'H'){
                    c1.push_front(val);
                }
                else{
                    c1.push_back(val);
                }
            }
        }
    }
    return 0;
}