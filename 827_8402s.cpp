#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

priority_queue<int, vector<int>, greater<int>> createQueue(priority_queue<int, vector<int>, greater<int>> a, int n, int m, int seed){
    unsigned x = seed;
    
    for(int i = 1; i < n + 1; i++){
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
        a.push(x % m + 1);
    }
    
    return a;
}

priority_queue<int, vector<int>, greater<int>> Calculate(priority_queue<int, vector<int>, greater<int>> a){
    
    while(true){
        if(a.size() == 1)
            break;
        int small = a.top();
        a.pop();
        int big = a.top();
        a.pop();
        if(2*small > a.top()) a.push(2*small);
        else a.push(big);
    }

    return a;
}


int main(){
    int n, m, s;
    priority_queue<int, vector<int>, greater<int>> a;

    cin >> n >> m >> s;
    a = createQueue(a, n, m, s);

    a = Calculate(a);

    cout << a.top() << endl;

    return 0;
}