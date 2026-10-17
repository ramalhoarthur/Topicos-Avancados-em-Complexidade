#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

bool dois(vector<int>& array, int i, int j, int k) {
    int jj = j;
    int kk = k;
    bool sim = false;

    while(jj != kk) {
        long long s = (long long) array[i] + array[jj] + array[kk];
        if (s == 0) {
            printf("%d %d %d\n", i, jj, kk);
            sim = true;
            jj++;
        } else if (s < 0) {
            jj++;
        } else {
            kk--;
        }
    }

    return sim;
}

int main() {
    int n;
    scanf("%d", &n);
    if (n < 3) {
        printf("0\n");
        return 0;
    }
    vector<int> array(n);
    int entrada;
    for (int i=0; i<n; i++) {
        scanf("%d", &entrada);
        array[i] = entrada;
    }

    bool nao = true;

    for (int i=0; i<n-2; i++) {
        if (dois(array, i, i+1, n-1)) {nao = false;}
    }

    if (nao) {
        printf("0\n");
    }

    return 0;
}
          