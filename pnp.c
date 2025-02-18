#include <stdio.h>

int main() {
    int n, bt[10], pri[10], wt[10], tat[10], p[10], ct[10], total_wt = 0, total_tat = 0;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Burst Time and Priority for each process:\n");
    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Process %d: ", p[i]);
        scanf("%d %d", &bt[i], &pri[i]);
    }

    // Sorting processes based on priority (lower value = higher priority)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (pri[j] > pri[j + 1]) {
                int temp;

                temp = pri[j]; pri[j] = pri[j + 1]; pri[j + 1] = temp;
                temp = bt[j]; bt[j] = bt[j + 1]; bt[j + 1] = temp;
                temp = p[j]; p[j] = p[j + 1]; p[j + 1] = temp;
            }
        }
    }

    // Calculating Completion Time, Turnaround Time, and Waiting Time
    ct[0] = bt[0];  // First process completion time = burst time
    for (int i = 1; i < n; i++) {
        ct[i] = ct[i - 1] + bt[i];  // Completion time = previous CT + current BT
    }

    for (int i = 0; i < n; i++) {
        tat[i] = ct[i];  // Turnaround Time = Completion Time (Since AT = 0)
        wt[i] = tat[i] - bt[i];  // Waiting Time = TAT - BT
        total_wt += wt[i];
        total_tat += tat[i];
    }

    // Gantt Chart
    printf("\nGantt Chart:\n ");
    for (int i = 0; i < n; i++) printf("----- ");
    printf("\n|");
    for (int i = 0; i < n; i++) printf(" P%d  |", p[i]);
    printf("\n ");
    for (int i = 0; i < n; i++) printf("----- ");
    printf("\n0");
    for (int i = 0; i < n; i++) printf("    %d", ct[i]);
    printf("\n");

    // Displaying process details
    printf("\nProcess\tBT\tPriority\tCT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t\t%d\t%d\t%d\n", p[i], bt[i], pri[i], ct[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_tat / n);

    return 0;
}
