#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_NOTE_WORDS 100
#define MAX_WORD_LENGTH 20

int main() {
    int T, N, M;
    scanf("%d", &T);

    while (T--) {
        scanf("%d %d", &N, &M);

        char lecture[MAX_WORDS][MAX_WORD_LENGTH];
        for (int i = 0; i < M; i++) {
            scanf("%s", lecture[i]);
        }

        char notes[N][MAX_NOTE_WORDS][MAX_WORD_LENGTH];
        int wordCounts[N];

        for (int i = 0; i < N; i++) {
            scanf("%d", &wordCounts[i]);
            for (int j = 0; j < wordCounts[i]; j++) {
                scanf("%s", notes[i][j]);
            }
        }

        int found, valid = 1;

        for (int i = 0; i < M; i++) {
            found = 0;
            for (int j = 0; j < N && !found; j++) {
                for (int k = 0; k < wordCounts[j] && !found; k++) {
                    if (strcmp(lecture[i], notes[j][k]) == 0) {
                        found = 1;
                    }
                }
            }
            if (!found) { 
                valid = 0;
                break;
            }
        }

        printf("%d\n", valid);
    }

    return 0;
}
