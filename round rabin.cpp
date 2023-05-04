#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 10

struct Process {
    int pid;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
};

void find_waiting_time(struct Process proc[], int n, int quantum) {
    int time = 0;
    int remaining = n;

    while (remaining > 0) {
        for (int i = 0; i < n; i++) {
            if (proc[i].remaining_time > 0) {
                if (proc[i].remaining_time <= quantum) {
                    time += proc[i].remaining_time;
                    proc[i].remaining_time = 0;
                    proc[i].waiting_time = time - proc[i].burst_time;
                    remaining--;
                } else {
                    time += quantum;
                    proc[i].remaining_time -= quantum;
                }
            }
        }
    }
}

void find_turnaround_time(struct Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].turnaround_time = proc[i].burst_time + proc[i].waiting_time;
    }
}

void find_avg_time(struct Process proc[], int n, int quantum) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    find_waiting_time(proc, n, quantum);
    find_turnaround_time(proc, n);

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        total_waiting_time += proc[i].waiting_time;
        total_turnaround_time += proc[i].turnaround_time;

        printf("%d\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].burst_time, proc[i].waiting_time, proc[i].turnaround_time);
    }

    printf("Average waiting time = %.2f\n", (float) total_waiting_time / (float) n);
    printf("Average turnaround time = %.2f\n", (float) total_turnaround_time / (float) n);
}

int main() {
    int n;
    int quantum;
    struct Process proc[MAX_PROCESS];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    for (int i = 0; i < n; i++) {
        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &proc[i].burst_time);
        proc[i].pid = i + 1;
        proc[i].remaining_time = proc[i].burst_time;
    }

    find_avg_time(proc, n, quantum);

    return 0;
}
