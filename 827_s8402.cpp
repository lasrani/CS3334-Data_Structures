#include <iostream>
using namespace std;

void generateArray(int* arr, int n, int m, int seed) {
    unsigned x = seed;
    for (int i = 1; i <= n; i++) {
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
        arr[i] = x % m + 1; 
    } 
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] >= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(){
    int n,m,seed;
    cin >> n >> m >> seed;
    int *arr = new int[n];
    generateArray(arr, n, m, seed);
    quickSort(arr,0,n-1);
    
    for(int i = 0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}