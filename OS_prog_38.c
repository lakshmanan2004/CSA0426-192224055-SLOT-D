#include <stdio.h>

void sjf_scheduling(int processes[], int burst_time[], int n) {
    int waiting_time[n], turnaround_time[n], completion_time[n];
    int total_waiting_time = 0, total_turnaround_time = 0;

    // Sort the processes based on their burst time using selection sort
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (burst_time[j] < burst_time[min_index])
                min_index = j;
        }
        // Swap burst time
        int temp = burst_time[min_index];
        burst_time[min_index] = burst_time[i];
        burst_time[i] = temp;

        // Swap process ID
        temp = processes[min_index];
        processes[min_index] = processes[i];
        processes[i] = temp;
    }

    // Calculate waiting time, turnaround time, and completion time
    waiting_time[0] = 0;
    completion_time[0] = burst_time[0];
    turnaround_time[0] = completion_time[0];
    for (int i = 1; i < n; i++) {
        waiting_time[i] = completion_time[i - 1];
        completion_time[i] = completion_time[i - 1] + burst_time[i];
        turnaround_time[i] = completion_time[i] - waiting_time[i];
    }

    // Calculate total waiting time and total turnaround time
    for (int i = 0; i < n; i++) {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }

    // Calculate average waiting time and average turnaround time
    float avg_waiting_time = (float)total_waiting_time / n;
    float avg_turnaround_time = (float)total_turnaround_time / n;

    // Display the results
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    }
    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], burst_time[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the burst time for process %d: ", i);
        scanf("%d", &burst_time[i]);
        processes[i] = i;
    }

    sjf_scheduling(processes, burst_time, n);

    return 0;
}
