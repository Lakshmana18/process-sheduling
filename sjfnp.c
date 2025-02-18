#include <stdio.h>
int main() {
    int n, bt[10], wt[10], tat[10], p[10], total_wt = 0, total_tat = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Process %d burst time: ", p[i]);
        scanf("%d", &bt[i]);
          
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (bt[j] > bt[j + 1]) {
                int temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    wt[0] = 0; 
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];  
        total_wt += wt[i];
    }
    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];  
        total_tat += tat[i];
    }
       printf("\nGantt Chart:\n ");
    for (int i = 0; i < n; i++) printf("----- ");
    printf("\n|");
    for (int i = 0; i < n; i++) printf(" P%d  |", p[i]);
    printf("\n ");
    for (int i = 0; i < n; i++) printf("----- ");
    printf("\n0");
    for (int i = 0; i < n; i++) printf("    %d", tat[i]);
    printf("\n");
    printf("\nProcess\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }
    printf("\nAverage Waiting Time: %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_tat / n);
    return 0;
}