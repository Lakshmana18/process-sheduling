#include <stdio.h>

int main() {
    int n, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], ct[n], wt[n], tat[n];
    char pid[n][5];

    // Input burst times
    for(i = 0; i < n; i++) {
        printf("Enter Process ID for process %d: ", i + 1);
        scanf("%s", pid[i]);
        printf("Enter Burst Time for %s: ", pid[i]);
        scanf("%d", &bt[i]);
    }

    // Calculate Completion Time
    ct[0] = bt[0];
    for(i = 1; i < n; i++) {
        ct[i] = ct[i-1] + bt[i];
    }

    // Calculate Turnaround Time and Waiting Time
    for(i = 0; i < n; i++) {
        tat[i] = ct[i];
        wt[i] = tat[i] - bt[i];
    }

    // Display results
    printf("\nProcess\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t%d\t%d\n", pid[i], bt[i], ct[i], tat[i], wt[i]);
    }

    // Gantt Chart
    printf("\nGantt Chart:\n");
    printf("|");
    for(i = 0; i < n; i++) {
        printf("  %s  |", pid[i]);
    }

    printf("\n0");
    for(i = 0; i < n; i++) {
        printf("     %d", ct[i]);
    }

    return 0;
}
