#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int num_requests, initial_head, i;
    int *requests;
    int total_head_movement = 0;

    printf("Enter the number of disk requests: ");
    scanf("%d", &num_requests);

    printf("Enter the initial head position: ");
    scanf("%d", &initial_head);

    // Allocate memory for the requests array
    requests = (int *)malloc(num_requests * sizeof(int));

    printf("Enter the disk request sequence:\n");
    for (i = 0; i < num_requests; i++)
    {
        printf("Request %d: ", i + 1);
        scanf("%d", &requests[i]);
    }

    // Calculate head movement
    total_head_movement += abs(initial_head - requests[0]);
    printf("Head movement for request %d: %d\n", 1, total_head_movement);

    for (i = 1; i < num_requests; i++)
    {
        total_head_movement += abs(requests[i] - requests[i - 1]);
        printf("Head movement for request %d: %d\n", i + 1, abs(requests[i] - requests[i - 1]));
    }

    printf("\nTotal head movement: %d\n", total_head_movement);
    printf("Average head movement: %.2f\n", (float)total_head_movement / num_requests);

    // Free dynamically allocated memory
    free(requests);

    return 0;
}
