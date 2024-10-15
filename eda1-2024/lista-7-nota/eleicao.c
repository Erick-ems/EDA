#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTES 1000000

typedef struct {
    int code;
    int votes;
} Candidate;

int compare(const void *a, const void *b) {
    Candidate *c1 = (Candidate *)a;
    Candidate *c2 = (Candidate *)b;
    if (c1->votes != c2->votes)
        return c2->votes - c1->votes; // Decreasing order of votes
    return c2->code - c1->code; // Decreasing order of code in case of tie
}

int main() {
    int S, F, E;
    scanf("%d %d %d", &S, &F, &E);

    Candidate president[100] = {{0, 0}};
    Candidate senator[1000] = {{0, 0}};
    Candidate depFed[10000] = {{0, 0}};
    Candidate depEst[100000] = {{0, 0}};

    int validVotes = 0, invalidVotes = 0;
    int vote;

    while (scanf("%d", &vote) != EOF) {
        if (vote < 0) {
            invalidVotes++;
            continue;
        }

        validVotes++;
        if (vote < 100) {
            president[vote].code = vote;
            president[vote].votes++;
        } else if (vote < 1000) {
            senator[vote].code = vote;
            senator[vote].votes++;
        } else if (vote < 10000) {
            depFed[vote].code = vote;
            depFed[vote].votes++;
        } else if (vote < 100000) {
            depEst[vote].code = vote;
            depEst[vote].votes++;
        }
    }

    // Sort and find the winners
    qsort(president, 100, sizeof(Candidate), compare);
    qsort(senator, 1000, sizeof(Candidate), compare);
    qsort(depFed, 10000, sizeof(Candidate), compare);
    qsort(depEst, 100000, sizeof(Candidate), compare);

    // Print results
    printf("%d %d\n", validVotes, invalidVotes);

    int totalPresidentialVotes = 0;
    for (int i = 0; i < 100; i++) {
        if (president[i].votes > 0)
            totalPresidentialVotes += president[i].votes;
    }

    if (president[0].votes > totalPresidentialVotes / 2) {
        printf("%d\n", president[0].code);
    } else {
        printf("Segundo turno\n");
    }

    for (int i = 0; i < S; i++) {
        if (i > 0) printf(" ");
        printf("%d", senator[i].code);
    }
    printf("\n");

    for (int i = 0; i < F; i++) {
        if (i > 0) printf(" ");
        printf("%d", depFed[i].code);
    }
    printf("\n");

    for (int i = 0; i < E; i++) {
        if (i > 0) printf(" ");
        printf("%d", depEst[i].code);
    }
    printf("\n");

    return 0;
}
