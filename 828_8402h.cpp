#include <iostream>
#include <algorithm>  
using namespace std;

long long int a1[10000005];
int a[10000005];

//copy the method below into your program:
void generateArray(int* arr, int n, int m, int seed) { 
	unsigned w = seed;
	for (int i = 0; i < n; i++) {
		w ^= w << 13;
		w ^= w >> 17;
		w ^= w << 5;
		arr[i + 1] = w % m + 1;

	}
}
//and call it in main() as below to acquire and store the generated numbers

int main() {
	int norm;
	int seed;
    int field;

    int temp2 = 0;
	int temp3 = 0;
    int temp4 = 0;
    int temp5 = 0;
    int oneTest = 1;
	int min = 0;

    bool c = true;


	cin >> norm >> field >> seed;

	generateArray(a, norm, field, seed);

	sort(a + 1, a + norm + 1);

	if (norm == 1) {
		cout << a[1] << endl;
		c = false;
	}

    int maximum = norm;

	while (maximum + min > 1 && c) {
		
        long long check = 0;
		long long flag = 0;

		if (maximum >= 1 && min >= 1) {
			if (a[oneTest] > a1[temp2]) {
				check = a1[temp2];
				temp2++; min--;
			}
			else {
                check = a[oneTest];
				oneTest++;
				maximum--;
			}
		}

		else if (maximum == 0) {
			check = a1[temp2];
			temp2++;
			min--;
		}

		else {
			check = a[oneTest];
			oneTest++; 
			maximum--;
		}

		if (maximum >= 1 && min >= 1) {
			if (a[oneTest] <= a1[temp2]) {
				flag = a[oneTest];
				oneTest++; 
				maximum--;
			}

			else {
				flag = a1[temp2];
				temp2++; 
				min--;
			}
		}

		else if (maximum == 0) {
			flag = a1[temp2];
			temp2++;
			min--;
		}

		else {
			flag = a[oneTest];
			oneTest++;
			maximum--;
		}

		if (check > flag) 
            swap(check, flag); 
		
        long long int num = max(2 * check, flag);

		a1[temp3++] = num;
		min++;
	}
    temp3--;
	cout << a1[temp3] << endl;

    return 0;
}