#include <stdio.h>

int main() {
    int n, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], ct[n], tat[n], wt[n];

    // Input burst times
    for(i = 0; i < n; i++) {
        printf("Enter Burst Time for Process P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Calculate Completion Time
    ct[0] = bt[0];
    for(i = 1; i < n; i++) {
        ct[i] = ct[i-1] + bt[i];
    }

    // Calculate Turnaround Time and Waiting Time
    for(i = 0; i < n; i++) {
        tat[i] = ct[i];           // TAT = CT - AT, AT = 0
        wt[i] = tat[i] - bt[i];   // WT = TAT - BT
    }

    // Display table
    printf("\nProcess\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", i+1, bt[i], ct[i], tat[i], wt[i]);
    }

    // Gantt Chart
    printf("\nGantt Chart:\n");
    printf("|");
    for(i = 0; i < n; i++) {
        printf("  P%d  |", i+1);
    }

    printf("\n0");
    for(i = 0; i < n; i++) {
        printf("     %d", ct[i]);
    }

    return 0;
}

