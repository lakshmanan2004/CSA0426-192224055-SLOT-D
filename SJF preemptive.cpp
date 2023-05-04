#include <stdio.h>

#define MAX_PROCESS 10

struct process {
    int pid;
    int burst_time;
    int remaining_time;
    int arrival_time;
};

int main() {
    struct process p[MAX_PROCESS];
    int n, time = 0, smallest, completed = 0, i;
    float waiting_time = 0, turnaround_time = 0;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    for(i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d%d", &p[i].arrival_time, &p[i].burst_time);
        p[i].pid = i + 1;
        p[i].remaining_time = p[i].burst_time;
    }
    
    while(completed != n) {
        smallest = -1;
        for(i = 0; i < n; i++) {
            if(p[i].arrival_time <= time && p[i].remaining_time > 0) {
                if(smallest == -1 || p[i].remaining_time < p[smallest].remaining_time) {
                    smallest = i;
                }
            }
        }
        
        if(smallest == -1) {
            time++;
        } else {
            p[smallest].remaining_time--;
            if(p[smallest].remaining_time == 0) {
                completed++;
                waiting_time += time - p[smallest].arrival_time - p[smallest].burst_time;
                turnaround_time += time - p[smallest].arrival_time;
            }
            time++;
        }
    }
    
    printf("PID\t Arrival Time\t Burst Time\t Waiting Time\t Turnaround Time\n");
    
    for(i = 0; i < n; i++) {
        printf("%d\t %d\t\t %d\t\t %d\t\t %d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, time - p[i].arrival_time - p[i].burst_time, time - p[i].arrival_time);
    }
    
    printf("Average waiting time: %.2f\n", waiting_time / n);
    printf("Average turnaround time: %.2f\n", turnaround_time / n);
    
    return 0;
}
