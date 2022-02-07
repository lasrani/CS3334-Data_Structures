#include <iostream>
#include <map>
using namespace std;

class Disjoint_set{
    private:
        int* set;
        int size;
        map<int,int> m1;


    public:
        Disjoint_set(int *a, int n){
            set = a;
            size = n;
        }
        

        void Sunion(int a, int b){
            int rA = find(a);
            int rB = find(b);

            if(rA != rB){
                if(set[rA] < set[rB]){
                    set[rB] = rA;
                }else if(set[rB] < set[rA]){
                    set[rA] = rB;
                }else{
                    set[rB] = rA;
                    set[rA]--;
                }
            }
        }

        void Enemy(int i, int j){
            if(m1.count(i)){
                Sunion(m1[i],j);
            }
            if(m1.count(j)){
                Sunion(m1[j],i);
            }
            m1[i] = j;
            m1[j] = i;
        }


        int find(int i){
            if(set[i]>= 0){
                return find(set[i]);
            }
            else{
                return i;
            }
        }

        int Max_gang(){
            int count = 0;
            for (int i =0;i < size;i++){
                if(set[i] <0) count++;
            }
            return count;
        }
};

int main(){


    int total, cases;
    cin >> total >> cases;

    int *arr = new int[total];
    for(int i = 0;i<total;i++){
        arr[i] = -1;
    }
    Disjoint_set set(arr,total);
    for(int i = 0; i < cases; i++){
        char ef;
        int a, b;
        cin >> ef >> a >> b;

        if(ef == 'F') set.Sunion(a-1, b-1);
        else set.Enemy(a-1,b-1);
    }

    cout << set.Max_gang() << endl;

    return 0;
}