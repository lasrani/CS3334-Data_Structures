#include <iostream>
#include <queue>
using namespace std;

int main(){
    int num;
    while(cin >> num){
    int a,o,l,last_o = -1;
    int discarded = -1;
    int current_time = 0;
    queue<int> q1;
    cin >> a >> o >> l;
    current_time = a;
    q1.push(o + a);
    for(int i =1;i<num;i++){
        cin >> a >> o >> l;
        while(!q1.empty() && q1.front() <= a){ // current_time != a
            q1.pop();
        }
        if(q1.size() <= l){
            if(a <= q1.back()){
                current_time = q1.back();
                q1.push(q1.back()+o);
            }
            else{
                current_time = a;
                q1.push(a + o);
            }
        }
        else{
            current_time = -1;
            discarded = a;
            last_o = o;
        }
    }
    cout << current_time << endl;
    }
    return 0;
}