#include <iostream>
using namespace std;

int main(){
    int num;
    while (cin >> num){
        int arr[1000000] = {0};
        int temp;
        bool flag = true;
        for(int i =0;i<num;i++){
            cin >> temp;
            if(temp <= num){
                arr[temp] = 1;
            }
        }
        for(int i =1;i<=num;i++){
            if(arr[i] == 0){
                cout << i << endl;
                flag = false;
                break;
            }
        }
    
        if(flag) cout << 0 << endl;
    
    }

    return 0;
}