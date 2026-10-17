#include <bits/stdc++.h>
using namespace std;

int main () {

       ios::sync_with_stdio(false);
       cin.tie(nullptr);

       int n, m;

       scanf("%d", &n);
       int A[n];

       long long somaA = 0;
       for(int i = 0 ; i < n ; i++) {
              cin >> A[i];
              somaA = somaA + A[i];
       }

       scanf("%d", &m);
       int B[m]; 

       long long somaB = 0;
       for(int i = 0 ; i < m ; i++) {
              cin >> B[i];
              somaB = somaB + B[i];
       }

       long long diff = abs(somaA - somaB);

       if( (somaA + somaB) % 2 == 1 ) {
              printf("-1\n");
              return 0;
       }

       else {

              long long coisa = diff / 2;

              sort(A, A + n);
              sort(B, B + m);

              for(int i = 0 ; i < n ; i++) {
                     
                     int k;

                     if(somaA > somaB) k = A[i] - coisa;
                     else if(somaB > somaA) k = A[i] + coisa;

                     int ini = 0, fim = m-1;
                     while(ini <= fim) {

                            int meio = floor(ini + (fim - ini) / 2);
                            
                            if(B[meio] == k) {
                                   printf("%d %d\n", A[i], B[meio]);
                                          return 0;
                            }
                            else if(B[meio] < k) {
                                   ini = meio +1;
                            }
                            else {
                                   fim = meio -1;
                            }
                     }
              }
              printf("-1\n");
       }
       return 0;
}