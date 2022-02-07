#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

class Coordinate{
   public:
    long long int x, y;
};

Coordinate p0;

long long int structure(Coordinate p, Coordinate q, Coordinate r){
    long long int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;
    return (val > 0)? 1: 2;
}


Coordinate ForTop(stack<Coordinate> &S){
    Coordinate p = S.top();
    S.pop();
    Coordinate res = S.top();
    S.push(p);
    return res;
}



long long int distSq(Coordinate p1, Coordinate p2){
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}



void swap(Coordinate &p1, Coordinate &p2){
    Coordinate temp = p1;
    p1 = p2;
    p2 = temp;
}


int compare(const void *vp1, const void *vp2) {
    Coordinate *o1 = (Coordinate *)vp1;
    Coordinate *o2 = (Coordinate *)vp2;

    double angle1 = atan2(o1->y - p0.y, o1->x - p0.x);
    double angle2 = atan2(o2->y - p0.y, o2->x - p0.x);

    if(angle1 > angle2) 
        return 1;
    else if (angle2 > angle1) 
        return -1;
    return 0;
}



void convexHull(Coordinate Coordinates[], long long int n){
    long long int xmin = Coordinates[0].x, min = 0;
    
    for (long long int i = 1; i < n; i++){
        long long int x = Coordinates[i].x;

        if ((xmin == x && Coordinates[i].y < Coordinates[min].y) || (x < xmin)){
            xmin = Coordinates[i].x;
            min = i;
        }
    }

    swap(Coordinates[0], Coordinates[min]);

    p0 = Coordinates[0];

    qsort(&Coordinates[1], n-1, sizeof(Coordinate), compare);

    stack<Coordinate> S;

    S.push(Coordinates[0]);
    S.push(Coordinates[1]);
    S.push(Coordinates[2]);

    for (long long int i = 3; i < n; i++){
        long long int k = 2;
        if(Coordinates[i].x < 0) k = 1;
        
        while (structure(ForTop(S), S.top(), Coordinates[i]) != 2 && 
                        structure(ForTop(S), S.top(), Coordinates[i]) != 0 && S.size()>1)
            S.pop();
        S.push(Coordinates[i]);
    }
    
    cout << S.size() << endl;

    stack<Coordinate> D;

    while (!S.empty()){
        D.push(S.top());
        S.pop();
    }

    while(!D.empty()){
        Coordinate p = D.top();
        cout << p.x << " " << p.y << endl;
        D.pop();
    }
}



int main(){
    int times;
    cin >> times;
    while(times--){
        long long int num, x, y;

        cin >> num;

        Coordinate arr[num];

        for(long long int i = 0; i < num; i++){
            cin >> x >> y;
            arr[i].x = x;
            arr[i].y = y;
        }
        
        convexHull(arr, num);
    }
    return 0;
}