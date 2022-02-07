#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;


int arr[1025][1025], Q[12][1025*1025], t;
void numbers(int x, int y, int X, int Y){
    if (X - x == 2 && Y - y == 2) {
        Q[0][t] = arr[x][y];
        arr[x][y] = t++;
        Q[0][t] = arr[x][y+1];
        arr[x][y+1] = t++;
        Q[0][t] = arr[x+1][y];
        arr[x+1][y] = t++;
        Q[0][t] = arr[x+1][y+1];
        arr[x+1][y+1] = t++;
    }
    else
    {
        numbers(x,y, (x+X)/2, (y+Y)/2);        
        numbers(x, (y+Y)/2, (x+X)/2, Y);
        numbers((x+X)/2,y, X, (y+Y)/2);
        numbers((x+X)/2,(y+Y)/2, X,Y);
    }
}

int main(){
    int times;
    cin >> times;
    
    for(int a = 0;a<times;a++){
        int num;
        cin >> num;
        int Size = pow(2,num);
        char c;
        for (int i = 0; i < Size; i++) {
            for (int j=0; j < Size; j++) {
                cin >> c;
                arr[i][j] = c-48;
            }
        }
        
        int Cal[12];
        long long int ans = 1;
        memset(Cal,0,sizeof(Cal)); 
        t = 0;
        
        if (Size == 1){
            Q[0][Cal[0]] = arr[0][0];
            Cal[0]++;
        }
        else {
            numbers(0,0,Size,Size);
            Cal[0] = t;
            
            for(int i=1; i<12; i++) {
                for(int j=0; j<Cal[i-1]; j++) {
                    if (Q[i-1][j] == Q[i-1][j+1] && Q[i-1][j] == Q[i-1][j+2] && Q[i-1][j] == Q[i-1][j+3] && Q[i-1][j] != -1) {
                        Q[i][Cal[i]++] = Q[i-1][j];
                    }
                    else {
                        Q[i][Cal[i]++] = -1;
                        ans += 4;
                    }
                    j += 3;
                }
                if (Cal[i] == 1)
                    break;
            }
        }
                
        int m;
        cin >> m;
        
        while(m--) {
            int row,col;
            cin >> row >> col;
            row--; 
            col--;

            int I = arr[row][col];
            long int Value; 
            long int Ans = ans;
            
            if(Q[0][I] == 1) Value = 0;
            else Value = 1;
             
            for(int i=0; i<12; i++) {
                if(Cal[i] == 1 || Q[i][I] == Value) break;
                         
                int Lower = I - I % 4;
                if (Q[i][Lower] == Q[i][Lower+1] && Q[i][Lower] == Q[i][Lower+2] && Q[i][Lower] == Q[i][Lower+3]) {
                    
                    if(Q[i][Lower] != -1)
                        Ans += 4;
                    Q[i][I] = Value;
                    Value = -1;
                }
                else {
                    Q[i][I] = Value;
                    
                    if (Q[i][Lower] == Q[i][Lower+1] && Q[i][Lower] == Q[i][Lower+2] && Q[i][Lower] == Q[i][Lower+3]) {
                        
                        if(Value != -1) Ans -= 4;
                    }
                    else Value = -1;
                }
                I /= 4;
            }
            ans = Ans;
            cout << Ans << endl;
        }
    }
    return 0;
}