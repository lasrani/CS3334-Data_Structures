#include <iostream>
#include <string>
using namespace std;

string traverse(int inorder[], int preorder[], int deep)
{
    string s;
    int i;

    for(i =0;i<deep;i++){

        if(inorder[i]==preorder[0]) break;
    }
    if(i != 0) 
        s+=traverse(inorder, preorder+1, i);
    if(i != deep-1) 
        s+=traverse(inorder+i+1, preorder+i+1, deep-i-1);
    return s + to_string(preorder[0]) + " ";
}

int main() {
    int times;
    cin>>times;

    while(times--){

        int num;
        cin>>num;

        int pre[100],in[100];
        
        for(int i=0;i<num;i++){
            cin>>pre[i];
        }

        for(int j=0;j<num;j++){
            cin>>in[j];
        }

        string final = traverse(in, pre, num);

        cout << final.substr(0,final.length() -1) << endl;

    }
    return 0;
}