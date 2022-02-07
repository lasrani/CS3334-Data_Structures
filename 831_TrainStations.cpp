#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 2e3 + 5;

struct tree {
    int v, next;
};

int n, m, t, k, len;

int h[N], p[N], f[N], ind[N], w[N];

const int M = 2 * N * N;

tree e[M];

int sorted() {
    queue<int> q1;

    for (int x = 1; x <= t; x++) {
        if (x <= n) 
            w[x] = 1;
        if (!ind[x]) 
            q1.push(x);
    }

    while (!q1.empty()) {
        int u = q1.front();
        q1.pop();

        for (int y = h[u]; y; y = e[y].next) {
            int v = e[y].v;

            if (v <= n) 
                w[v] = w[u] + 1;
            else 
                w[v] = w[u];
            
            ind[v]--;

            if (!ind[v]) 
                q1.push(v);
        }
    }

    int calculate = 0;

    for (int x = 1; x <= n; x++){
        calculate = max(calculate, w[x]);
    }

    return calculate;
}

void utilFunc(int u, int v) {
    len++;
    e[len].v = v; 
    e[len].next = h[u];
    h[u] = len;
}

int main() {


    scanf("%d%d", &n, &m);
    t = n;
    for (int x = 1; x <= m; x++) {
        scanf("%d", &k);

        for (int y = 1; y <= k; y++)
            scanf("%d", &p[y]); p[k + 1] = -1;

        for (int y = 1; y <= k; y++){
            for (int u = p[y] + 1; u < p[y + 1]; u++){
                utilFunc(u , t + 1);
                ind[t + 1]++;
            }

            utilFunc(t + 1, p[y]); ind[p[y]]++;
        }
        t++;
    }

    printf("%d\n", sorted());

    return 0;
}