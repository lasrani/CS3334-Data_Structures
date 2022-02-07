#include <iostream>
#include <stack>
using namespace std;

int main() {
    int times;
    cin >> times;
    
    while (times--) {
        stack<int> s1;
        int num;
        cin >> num;
        
        for(int i = 0; i < num; i++){
            int temp;
            cin >> temp;
            s1.push(temp);
        }    
        int p;
        cin >> p;
        
        while (p--){
            stack<int> s2;
            stack<int> s3;
            int arr[num];
            
            for (int i = 0; i < num; i++) cin >> arr[i];
            
            s2 = s1;
            bool verdict = false;
            
            for (int i = 0; i < num; i++) {
                if (!s3.empty() && s3.top() == arr[i]) {
                    s3.pop();
                    verdict = true;
                }
                else{
                    while (!s2.empty() && (s2.top()!= arr[i])) {
                        s3.push(s2.top());
                        s2.pop();
                    }
                    if(arr[i] == s2.top()) {
                        s2.pop();
                        verdict = true;
                    }
                }
                if (verdict && i != (num -1)) {
                    verdict = false;
                }
                else{
                    break;
                }
            }
            
            if(verdict) cout<<"Aye"<<endl;
            else cout<<"Impossible"<<endl;
        }
    }
    return 0;
}