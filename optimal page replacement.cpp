#include <stdio.h>

#define MAX_PAGES 100
#define MAX_REF_STRING 1000

int pages[MAX_PAGES];
int nPages;
int refString[MAX_REF_STRING];
int nRef;

int findNextUse(int page, int start) {
    for(int i = start; i < nRef; i++) {
        if(refString[i] == page) {
            return i;
        }
    }
    return nRef;
}

int main() {
    printf("Enter the number of pages: ");
    scanf("%d", &nPages);

    printf("Enter the reference string: ");
    for(int i = 0; i < MAX_REF_STRING; i++) {
        scanf("%d", &refString[i]);
        if(refString[i] == -1) {
            nRef = i;
            break;
        }
    }

    int hits = 0, faults = 0;
    for(int i = 0; i < nRef; i++) {
        int page = refString[i];
        int found = 0;
        for(int j = 0; j < nPages; j++) {
            if(pages[j] == page) {
                hits++;
                found = 1;
                break;
            }
        }
        if(!found) {
            faults++;
            if(i == nRef-1) {
                pages[0] = page;
            } else {
                int maxNextUse = -1, maxPage = -1;
                for(int j = 0; j < nPages; j++) {
                    int nextUse = findNextUse(pages[j], i);
                    if(nextUse > maxNextUse) {
                        maxNextUse = nextUse;
                        maxPage = j;
                    }
                }
                pages[maxPage] = page;
            }
        }
    }

    printf("Hits: %d\n", hits);
    printf("Faults: %d\n", faults);

    return 0;
}
