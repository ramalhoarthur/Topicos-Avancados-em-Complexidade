#include <bits/stdc++.h>
#include <cmath>
using namespace std;

typedef long long ll;

int main () {
       ll n, k;
       scanf("%lld %lld", &n, &k);

       long long maximo = 0, soma = 0;

       ll peso[n];
       for(int i = 0 ; i < n ; i++) {
              scanf("%lld", &peso[i]);
              soma = soma + peso[i];
              if(peso[i] > maximo) maximo = peso[i];
       }

       ll ini = maximo-1, fim = soma-1;

       while(ini < fim) {

              ll meio = ini + (fim - ini +1) / 2;

              int dias = 1;
              ll pesado = 0;

              for(int i = 0 ; i < n ; i++) {

                     if(pesado + peso[i] > meio) {
                            dias++;
                            pesado = 0;

                            if(dias > k) break;
                     }
                     pesado = pesado + peso[i];
              }
              if(dias > k) ini = meio;
              else fim = meio -1;
       }

       printf("%lld\n", ini +1);

       return 0;
}