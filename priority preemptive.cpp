#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 10

struct Process {
    int pid;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
    int remaining_time;
};

void find_waiting_time(struct Process proc[], int n) {
    int time = 0;
    int remaining = n;
    int min_index;

    while (remaining > 0) {
        min_index = -1;

        for (int i = 0; i < n; i++) {
            if (proc[i].remaining_time > 0) {
                if (min_index == -1 || proc[i].priority < proc[min_index].priority) {
                    min_index = i;
                }
            }
        }

        proc[min_index].remaining_time--;
        time++;

        if (proc[min_index].remaining_time == 0) {
            remaining--;
            proc[min_index].waiting_time = time - proc[min_index].burst_time - proc[min_index].priority;

            if (proc[min_index].waiting_time < 0) {
                proc[min_index].waiting_time = 0;
            }
        }
    }
}

void find_turnaround_time(struct Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].turnaround_time = proc[i].burst_time + proc[i].waiting_time;
    }
}

void find_avg_time(struct Process proc[], int n) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    find_waiting_time(proc, n);
    find_turnaround_time(proc, n);

    printf("Process\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        total_waiting_time += proc[i].waiting_time;
        total_turnaround_time += proc[i].turnaround_time;

        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].burst_time, proc[i].priority, proc[i].waiting_time, proc[i].turnaround_time);
    }

    printf("Average waiting time = %.2f\n", (float) total_waiting_time / (float) n);
    printf("Average turnaround time = %.2f\n", (float) total_turnaround_time / (float) n);
}

int main() {
    int n;
    struct Process proc[MAX_PROCESS];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the burst time and priority for process %d: ", i + 1);
        scanf("%d %d", &proc[i].burst_time, &proc[i].priority);
        proc[i].pid = i + 1;
        proc[i].remaining_time = proc[i].burst_time;
    }

    find_avg_time(proc, n);

    return 0;
}
