#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void) {
    int n; // alphabet size
    int m; // relations size
    if (scanf("%d %d", &n, &m) != 2) {
        return 0;
    }

    char elems[26][2];
    int id[26];

    for (int i = 0; i < 26; i++) {
        id[i] = -1;
    };

    for (int i = 0; i < n; i++) {
        scanf("%1s", elems[i]);
        int c = elems[i][0] - 'a';
        id[c] = i;
    }

    // Relation matrix
    unsigned char rel[26][26] = {0};

    for (int t = 0; t < m; t++) {
        char a[2];
        char b[2];
        scanf("%1s %1s", a, b);
        int u = id[a[0] - 'a'];
        int v = id[b[0] - 'a'];
        rel[u][v] = 1;
    }

    // R: рефлексивность
    bool isR = true;
    for (int i = 0; i < n; i++) {
        if (!rel[i][i]) {
            isR = false; break;
        }
    }

    // S: симметричность
    bool isS = true;
    for (int i = 0; i < n && isS; i++) {
        for (int j = 0; j < n; j++) {
            if (rel[i][j] && !rel[j][i]) {
                isS = false; break;
            }
        }
    }

    // A: антисимметричность
    bool isA = true;
    for (int i = 0; i < n && isA; i++) {
        for (int j = i + 1; j < n; j++) {
            if (rel[i][j] && rel[j][i]) {
                isA = false; break;
            }
        }
    }

    // T: транзитивность
    bool isT = true;
    for (int i = 0; i < n && isT; i++) {
        for (int j = 0; j < n && isT; j++) {
            if (rel[i][j]) {
                for (int k = 0; k < n; k++) {
                    if (rel[j][k]) {
                        if (!rel[i][k]) {
                            isT = false; break;
                        }
                    }
                }
            }
        }
    }

    putchar(isR ? 'R' : '*');
    putchar(isS ? 'S' : '*');
    putchar(isT ? 'T' : '*');
    putchar(isA ? 'A' : '*');

    return 0;
}