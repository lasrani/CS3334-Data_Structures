#include <iostream>
#include <bitset>
#include <math.h>
using namespace std;

int RSum (int r , int c , int arr[100][10]) {
    int sum0 = 0;
    int sum1 = 0;

        for (int j = 0; j < c; j++) {
            if (arr[r][j] == 1) {
                sum1++;
            }
            else {
                sum0++;
            }
        }
        if (sum1 >= sum0) return sum1;
        else return sum0;
}

void changeColumn(int a, int arr[100][10] , int n) {
    for (int j = 0; j < n; j++) {
        if (arr[j][a] == 0) arr[j][a] = 1;
        else arr[j][a] = 0;
    }
}

int main() {
    int r = 0;
    int c = 0;
    int sum = 0;
    int max = 0;

    int arr[100][10];

    int num[10];
    
    string temp = " ";

    while (cin >> r) {
        cin >> c;
        for (int i = 0; i < r; i++) {
            cin >> temp;

            for (int j = 0; j < c; j++) {
                arr[i][j] = temp[j] - '0';
            }
        }
        for (int i = 0; i < pow(2, c); i++) {
            string str = bitset <10>(i).to_string();
            int x = 0;
            for (int j = 10-c; j < 10; j++) {
                num[x] = str[j] - '0';
                x++;
            }
            for (int k = 0; k < c; k++) {
                if (num[k] == 1)
                    changeColumn(k, arr, r);
            }
            for (int k = 0; k < r; k++) {
                sum += RSum(k, c, arr);
            }
            if (sum > max) max = sum;
            sum = 0;
            for (int k = 0; k < c; k++) {
                if (num[k] == 1)
                    changeColumn(k, arr, r);
            }
        }
        cout << max << endl;
        max = 0;
    }
    return 0;
}