#include <iostream>
using namespace std;

int P(int i, int *array){
    
    if(array[i]!=i)
        array[i]=P(array[i], array);

    return array[i];
}

void Union(int *array, const int i, const int j, int *rank){
    
    int a= P(i, array);
    int b= P(j, array);
    
    if (a!=b){
        if(rank[a] > rank[b]){
            array[b]=a;
        }
        else if (rank[b] > rank[a]){
            array[a]=b;
        }
        else {
            array[b] = a;
            rank[a] += 1;
        }
    }
}


int main(){
    int times;
    int count=0;
    cin>> times;

    while(times--){

        count++;

        int n;
        scanf("\n%d\n",&n);

        int *array= new int[n+1];
        int *rank = new int[n+1];

        for(int i=0;i<=n;i++){
            array[i]=i;
            rank[i]=1;
        }

        int failure = 0;

        int success=0;
        int x,y;
        char c;
        string s;

        while(true){
            if(!getline(cin,s) || s.empty()) 
                break;
            sscanf(s.c_str(),"%c %d %d",&c,&x,&y);
            if (c=='c'){
                Union(array, x, y, rank);
            }
            if(c=='q'){
                if(P(x, array)==P(y, array))
                    success++;
                else
                    failure++;
            }
        }

        if(count!=1) 
            cout<<endl;

        cout<<success<<failure<<endl;
    }
}