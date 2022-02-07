#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;
    queue<int> q1;
    map<int,int> hash1;
    for(int i =0; i < n;i++){
        int temp;
        cin >> temp;
        if(!q1.empty()){
            int checking  = temp - q1.front();
            while(checking >= 86400){
                q1.pop();
                int num = q1.front();
                q1.pop();
                for(int k =0 ;k<num;k++){
                    hash1[q1.front()]--;
                    if(hash1[q1.front()] == 0){
                        hash1.erase(q1.front());
                    }
                    q1.pop();
                }
                checking = temp - q1.front();
            }
        }
        q1.push(temp);
        cin >> temp;
        q1.push(temp);
        for(int j =0;j<temp;j++){
            int check;
            cin>>check;
            q1.push(check);
            if(hash1.count(check)){
                hash1[check]++;
            }
            else{
                hash1[check] = 1;
            }
        }
        cout << hash1.size() << endl;

    }
    return 0;
}