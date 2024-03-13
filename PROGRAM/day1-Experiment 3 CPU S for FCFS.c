#include <stdio.h>

#define MAX_PROCESSES 10

struct Process {
    int pid; 
    int arrival_time; 
    int burst_time; 
};

int main() {
    struct Process processes[MAX_PROCESSES];
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].pid = i + 1;
    }

    int completion_time = 0;
    float total_waiting_time = 0;

    printf("\nGantt Chart:\n");
    printf("-----------\n");
    printf("| Process | Completion Time |\n");
    printf("|---------|----------------|\n");

    for (int i = 0; i < n; i++) {
        if (completion_time < processes[i].arrival_time)
            completion_time = processes[i].arrival_time;

        printf("|    P%d   |        %d       |\n", processes[i].pid, completion_time + processes[i].burst_time);

        total_waiting_time += completion_time - processes[i].arrival_time;
        completion_time += processes[i].burst_time;
    }
    printf("-----------\n");

    printf("\nAverage Waiting Time: %.2f\n", total_waiting_time / n);

    return 0;
}
