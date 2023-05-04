#include <stdio.h>

#define MAX_PROCESS 10

struct process {
    int pid;
    int burst_time;
    int priority;
    int arrival_time;
};

int main() {
    struct process p[MAX_PROCESS];
    int n, i, j, time = 0, smallest, temp;
    float waiting_time = 0, turnaround_time = 0;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    for(i = 0; i < n; i++) {
        printf("Enter arrival time, burst time, and priority for process %d: ", i + 1);
        scanf("%d%d%d", &p[i].arrival_time, &p[i].burst_time, &p[i].priority);
        p[i].pid = i + 1;
    }
    
    for(i = 0; i < n - 1; i++) {
        smallest = i;
        for(j = i + 1; j < n; j++) {
            if(p[j].arrival_time < p[smallest].arrival_time) {
                smallest = j;
            } else if(p[j].arrival_time == p[smallest].arrival_time && p[j].priority < p[smallest].priority) {
                smallest = j;
            }
        }
        temp = p[i].arrival_time;
        p[i].arrival_time = p[smallest].arrival_time;
        p[smallest].arrival_time = temp;
        temp = p[i].burst_time;
        p[i].burst_time = p[smallest].burst_time;
        p[smallest].burst_time = temp;
        temp = p[i].priority;
        p[i].priority = p[smallest].priority;
        p[smallest].priority = temp;
        temp = p[i].pid;
        p[i].pid = p[smallest].pid;
        p[smallest].pid = temp;
        
    }
    
    for(i = 0; i < n; i++) {
        waiting_time += time - p[i].arrival_time;
        time += p[i].burst_time;
        turnaround_time += time - p[i].arrival_time;
    }
    
    printf("PID\t Arrival Time\t Burst Time\t Priority\t Waiting Time\t Turnaround Time\n");
    
    for(i = 0; i < n; i++) {
        printf("%d\t %d\t\t %d\t\t %d\t\t %d\t\t %d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].priority, time - p[i].arrival_time - p[i].burst_time, time - p[i].arrival_time);
    }
    
    printf("Average waiting time: %.2f\n", waiting_time / n);
    printf("Average turnaround time: %.2f\n", turnaround_time / n);
    
    return 0;
}
