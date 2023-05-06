#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 1000

int abs(int x) {
    return (x < 0) ? -x : x;
}

void scan(int requests[], int numRequests, int head, int direction) {
    int totalHeadMovement = 0;
    int currentTrack = head;
    int i, j;

    // Sort the requests in ascending order
    for (i = 0; i < numRequests - 1; i++) {
        for (j = 0; j < numRequests - i - 1; j++) {
            if (requests[j] > requests[j + 1]) {
                int temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }

    // Find the position to change direction
    int directionChange = 0;
    for (i = 0; i < numRequests; i++) {
        if (requests[i] > head) {
            directionChange = i;
            break;
        }
    }

    // Calculate head movement
    if (direction == 1) {
        for (i = directionChange; i < numRequests; i++) {
            totalHeadMovement += abs(requests[i] - currentTrack);
            currentTrack = requests[i];
        }

        totalHeadMovement += abs(currentTrack - 199);
        currentTrack = 199;

        for (i = directionChange - 1; i >= 0; i--) {
            totalHeadMovement += abs(requests[i] - currentTrack);
            currentTrack = requests[i];
        }
    } else {
        for (i = directionChange - 1; i >= 0; i--) {
            totalHeadMovement += abs(requests[i] - currentTrack);
            currentTrack = requests[i];
        }

        totalHeadMovement += abs(currentTrack - 0);
        currentTrack = 0;

        for (i = directionChange; i < numRequests; i++) {
            totalHeadMovement += abs(requests[i] - currentTrack);
            currentTrack = requests[i];
        }
    }

    printf("Average head movement: %.2f\n", (float)totalHeadMovement / numRequests);
}

int main() {
    int requests[MAX_REQUESTS];
    int numRequests, head, direction;
    int i;

    printf("Enter the number of requests: ");
    scanf("%d", &numRequests);

    printf("Enter the requests (0-199): ");
    for (i = 0; i < numRequests; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the initial position of the head: ");
    scanf("%d", &head);

    printf("Enter the direction of head movement (1 for right, -1 for left): ");
    scanf("%d", &direction);

    scan(requests, numRequests, head, direction);

    return 0;
}
