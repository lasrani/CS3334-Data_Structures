#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};


class Stack1{
public:
    Node* top;
    Stack1(){
        top = NULL;
    }

    bool isEmpty(){
        return top == NULL;
    }
    
    void push(int num){
        Node * node = new Node;
        node -> data = num;
        
        if(isEmpty())
        {
            top = node;
            node -> next = NULL;
        }
        else
        {
            node -> next = top;
            top = node;
        }
    }
    
    void pop(){
        Node *ptr = top;
        if(!isEmpty()){
            top = top -> next;
            delete ptr;
        }
    }
    
    int max(){
        int max;
        Node *ptr = top;
        max = top -> data;
        
        while (ptr != NULL){
            if (max < ptr -> data){
                max = ptr -> data;
            }
            ptr = ptr -> next;
        }
        return max;
    }
};

int main()
{
    int times,num, m;
    int n, I;
    char M;

    cin >> times;
    Stack1 *s1 = new Stack1[times];
    
    for(int i = 0;i < times;i++){
        cin >>num;
        for(int j =0;j < num;j++){
            cin >> n;
            s1[i].push(n);
        }
        cin >> m;
        for(int j =0;j<m;j++){
            cin >> M;

            if(M == 'm') cout << s1[i].max() << endl;

            else if(M == 'r') s1[i].pop();

            else if(M == 'a'){
                cin >> I;
                s1[i].push(I);
            }
                    
        }
    }
    return 0;
}
