#include <iostream>
using namespace std;

struct N{
    int num;
    N *next;
};

class MainL{
public:    
    N *head, *tail;
    
    MainL(){
        head = NULL;
        tail = NULL;
    }
    
    N *makeMakeL(int num){
        for (int i = 0; i < num; i++){
            N *n1 = new N;
            
            if (head == NULL){
                n1 -> next = NULL;
                head = n1;
                tail = n1;
            }
            
            else{
                tail -> next = n1;
                n1 -> next = NULL;
                tail = n1;
            }
        }
        return head;
    }
    
    N *insert(int i, int num){
        N *ptr = head;
        
        for ( int j = 1; j < i ; j++)
        {
            ptr = ptr -> next;
        }
        
        N *n1 = new N;
        n1 -> next = ptr -> next;
        n1 -> num = num;
        ptr -> next = n1 ;
        return head;
    }

    N *Delete (int i){
        N *ptr = head;
        N *preptr = ptr;
        
        if (i == 1){
            head = head -> next;
        }
        else{
            for (int j = 1; j < i ; j++){
                    preptr = ptr;
                    ptr = ptr -> next;
                }
        }
        
        preptr -> next = ptr -> next;
        delete ptr;
        
        return head;
    }
    
    N *reverse (int i, int j){
        
        int *arr = new int [j - i + 1];
        int k = 0;
        int temp;
        
        N *temp1 = head;
        N *temp2 = head;
        
        for (int k = 1; k < i - 1 ; k++){
            temp1 = temp1 -> next;
        }
        
        for (int k = 1; k < j + 1 ; k++){
            temp2 = temp2 -> next;
        }

        N *ptr;
        N *ptr1;
        
        if (i == 1){
            ptr = temp1  ;
            ptr1 = temp1 ;
        }
        else{
            ptr = temp1 -> next  ;
            ptr1 = temp1 -> next  ;
        }
        
        while (ptr != temp2 ){
            arr[k] = ptr -> num;
            k++;
            ptr = ptr -> next;
        }
        
        while (ptr1 != temp2 ){
            temp = ptr1 -> num;
            ptr1 -> num = arr[k-1];
            arr[k-1] = temp;
            k--;
            ptr1 = ptr1 -> next;
        }

        return head;
    }

    N *insertValues(int arr[]){
        N *ptr = head;
        int i = 0;
        
        while (ptr != NULL)
        {
            ptr -> num = arr[i];
            ptr = ptr -> next;
            i++;
        }
        return head;
    }


    void output (int pos){
        N *ptr = head;
        
        for (int i = 1; i < pos; i++)
        {
            ptr = ptr -> next;
        }
        cout << ptr -> num << endl;
    }
    
};

int main (){
    MainL manipulateMainL;
    
    int N, Q, q, position, val;
    int delPos, revI, revJ, pos;
    cin >> N;
    
    int *a = new int[N];
    
    manipulateMainL.makeMakeL(N);
    
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    
    manipulateMainL.insertValues(a);
    
    cin >> Q;
    
    for (int i = 0; i < Q; i++)
    {
        cin >> q;
        
        if(q == 1) {
            cin >> position >> val;
            manipulateMainL.insert(position, val);
        }        
        if( q == 2){
            cin >> delPos;
            manipulateMainL.Delete(delPos);
        }       
        if( q == 3){
            cin >> revI >> revJ;
            manipulateMainL.reverse(revI, revJ);
         }
                
        if(q == 4){
            cin >> pos;
            manipulateMainL.output(pos);
        }
       
    }
    return 60;
}