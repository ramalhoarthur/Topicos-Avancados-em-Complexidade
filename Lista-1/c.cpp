#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

int main() {
    long freq[26] = {0};
    char s1[1000010], s2[1000010];
    scanf("%s %s", s1, s2);
    bool tem = false;

    long t = strlen(s1);
    for (int i=0; i<t; i++) {
        freq[s1[i]-'a']++;
    }

    int j = 0;
    for (int i=0; i<t; i++) {
        if (s2[j+i] == '\0') {
            printf("Nao\n");
            return 0;
        }
        freq[s2[j+i]-'a']--;
    }
    bool deucerto = true;
    for (int i=0; i<26; i++) {
        if (freq[i] != 0) {
            deucerto = false;
            break;
        }
    }
    if (deucerto) {
        printf("%d\n", j);
        tem = true;
    }
    while(s2[j+t] != '\0') {
        freq[s2[j]-'a']++;
        freq[s2[j+t]-'a']--;
        deucerto = true;
        for (int i=0; i<26; i++) {
            if (freq[i] != 0) {
                deucerto = false;
                break;
            }
        }
        j++;
        if (deucerto) {
            printf("%d\n", j);
            tem = true;
        }
    }


    if (!tem) {
        printf("Nao\n");
        return 0;
    }
    
}
          