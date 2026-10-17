#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

int main() {
    long long freq[26] = {0};
    int c;
    bool first = true;

    while (true) {
        c = getchar();
        if (c == '\n' || c == '\r' || c == EOF) {
            bool perfeito = true;
            for (int i=0; i<26; i++) {
                if (freq[i] != 0) {
                    perfeito = false;
                    break;
                }
            }
            if (perfeito) {
                printf("Sim\n");
                return 0;
            }
            printf("Nao\n");
            return 0;
        } else if (c == ' ') {
            first = false;
        } else {
            if (first) {
                freq[c-'a']++;
            } else {
                if (freq[c-'a'] == 0) {
                    printf("Nao\n");
                    return 0;
                }
                freq[c-'a']--;
            }   
        }
    }
}