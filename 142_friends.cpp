#include <iostream>
using namespace std;

class Disjoint_Set{
    private:
        int *set;
        int Max;
        int c = 0;
        
    public:
        Disjoint_Set(int size){
            this->Max = size;
            set = new int[size];
            for(int i = 1; i < size;i++){
                set[i] = -1;
            }
        }

        void Union(int i,int j){
            int a = findRootIndex(i);
            int b = findRootIndex(j);
            
            if(a != b){
                set[a] -= (-1*set[b]);
                int te = -1*set[a];
                if(te>c) c = te;
                set[b] = a;
            }
        }

        int findRootIndex(int i){
            if(set[i]>= 1){
                return findRootIndex(set[i]);
            }
            else{
                return i;
            }
        }
        
        int getCount(){
            return c;
        }

};
int main(){
    int times;
    cin >> times;
    for (int i =0;i<times;i++){

        int total,cases;
        cin >> total >> cases;

        Disjoint_Set set1(total+1);

        for (int j =0; j< cases;j++){
            int in1,in2;
            cin >> in1 >> in2;
            set1.Union(in1,in2);
        }
        cout << set1.getCount() << endl;
    }
    return 0;
}