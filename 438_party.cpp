#include <iostream>
using namespace std;

int main(){
    
    int test;
    cin >> test;

    for (int i = 0;i<test;i++){
        int check;
        cin >> check;
        if(check > 2){
            cout << check - 2 << endl;
        }
        else{
            cout << 0 << endl;
        }
    }

}