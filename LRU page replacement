#include <stdio.h>

#define MAX_PAGES 100
#define MAX_REF_STRING 1000

int pages[MAX_PAGES];
int nPages;
int refString[MAX_REF_STRING];
int nRef;
int pageAge[MAX_PAGES];

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
                pageAge[j] = 0;
            } else {
                pageAge[j]++;
            }
        }
        if(!found) {
            faults++;
            int maxAge = -1, maxPage = -1;
            for(int j = 0; j < nPages; j++) {
                if(pageAge[j] > maxAge) {
                    maxAge = pageAge[j];
                    maxPage = j;
                }
            }
            pages[maxPage] = page;
            pageAge[maxPage] = 0;
        }
    }

    printf("Hits: %d\n", hits);
    printf("Faults: %d\n", faults);

    return 0;
}
