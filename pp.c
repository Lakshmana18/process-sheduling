#include <stdio.h>

int main() {
    int n, time = 0, completed = 0, min_pri, idx;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int p[n], at[n], bt[n], pri[n], wt[n], tat[n], remaining[n], ct[n];
    float avg_wt = 0, avg_tat = 0;
    
    printf("Enter Arrival Time, Burst Time, and Priority for each process:\n");
    for (int i = 0; i < n; i++) {
        p[i] = i + 1;  
        printf("Process %d: ", p[i]);
        scanf("%d %d %d", &at[i], &bt[i], &pri[i]);
        remaining[i] = bt[i];  
    }

    int gantt[100], gantt_p[100], gantt_idx = 0;

    // Preemptive Priority Scheduling
    while (completed < n) {
        min_pri = 9999;
        idx = -1;
        
        // Find the highest-priority process available at the current time
        for (int i = 0; i < n; i++) {
            if (remaining[i] > 0 && at[i] <= time && pri[i] < min_pri) {
                min_pri = pri[i];
                idx = i;
            }
        }

        // If no process is found, move forward in time
        if (idx == -1) {
            time++;
            continue;
        }

        // Execute the process for 1 unit of time
        remaining[idx]--;
        
        // Record Gantt Chart entry only if process is changing
        if (gantt_idx == 0 || gantt_p[gantt_idx - 1] != p[idx]) {
            gantt[gantt_idx] = time;
            gantt_p[gantt_idx++] = p[idx];
        }

        time++;

        // If a process is completed
        if (remaining[idx] == 0) {
            completed++;
            ct[idx] = time;  
            tat[idx] = ct[idx] - at[idx];  
            wt[idx] = tat[idx] - bt[idx];  
            avg_wt += wt[idx];
            avg_tat += tat[idx];
        }
    }
     printf("\nGantt Chart:\n ");
    for (int i = 0; i < gantt_idx; i++) 
        printf("----- ");
    printf("\n|");
    for (int i = 0; i < gantt_idx; i++) 
        printf(" P%d  |", gantt_p[i]);
    printf("\n ");
    for (int i = 0; i < gantt_idx; i++) 
        printf("----- ");
    
    printf("\n0");
    for (int i = 0; i < gantt_idx; i++) 
        printf("    %d", gantt[i] + 1);
    printf("\n");
    
    printf("\nProcess\tAT\tPriority\tBT\tCT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t\t%d\t%d\t%d\t%d\n", p[i], at[i], pri[i], bt[i], ct[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat / n);
    return 0;
}
