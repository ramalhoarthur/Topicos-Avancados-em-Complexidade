#include <bits/stdc++.h>
using namespace std;

int main () {

       int n;
       scanf("%d", &n);

       int A[n];

       for(int i = 0 ; i < n ; i++) {
              scanf("%d", &A[i]);
       }

       for (int i = 0; i < n; i++) {

              int k = n - i;

              if ( A[i] >= k && (i == 0 || A[i - 1] < k) ) {
                     printf("%d\n", k);
                     return 0;
              }
       }
       
       printf("-1\n");
       return 0;
}