#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int isPrime(int num) {
    if (num <= 1)
        return 0;

    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0)
            return 0;
    }

    return 1;
}

void generateFibonacci(int n) {
    int first = 0, second = 1;
    printf("Fibonacci Series child process: %d, %d, ", first, second);

    for (int i = 2; i < n; ++i) {
        int next = first + second;
        printf("%d%s", next, (i == n - 1) ? "" : ", ");
        first = second;
        second = next;
    }

    printf("\n");
}

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        generateFibonacci(10);
    } else {
        // Parent process
        int status;
        wait(&status);

        if (WIFEXITED(status)) {
            printf("Prime Numbers parent process: ");
            for (int i = 2; i <= 20; ++i) {
                if (isPrime(i))
                    printf("%d ", i);
            }
            printf("\n");
        }
    }

    return 0;
}
