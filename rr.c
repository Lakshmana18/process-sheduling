#include <stdio.h>

int main() {
    int n, i, t;
    float tot_wt = 0, tot_tat = 0;
    float avg_wt, avg_tat;
    
    printf("Round Robin scheduling :\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    int wt[n], bt[n], tat[n], p[n];
    int remainingTime[n];

    // Input burst times for each process
    for(i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Enter the burst time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
        remainingTime[i] = bt[i];
        wt[i] = 0;
    }

    printf("Enter the time slice for assigning each process: ");
    scanf("%d", &t);

    int time = 0;
    int completed = 0;
    int ganttp[100];
    int ganttT[100];
    int ganttIndex = 0;

    while (completed < n) {
        for (i = 0; i < n; i++) {
            if (remainingTime[i] > 0) {
                ganttp[ganttIndex] = p[i];
                ganttT[ganttIndex++] = time;
                
                if (remainingTime[i] > t) {
                    time += t;
                    remainingTime[i] -= t;
                } else {
                    time += remainingTime[i];
                    tat[i] = time; // Turnaround time is completion time
                    remainingTime[i] = 0;
                }
                if (remainingTime[i] == 0) {
                    completed++;
                }
            }
        }
    }

    ganttT[ganttIndex] = time;

    for (i = 0; i < n; i++) {
        wt[i] = tat[i] - bt[i];
        tot_wt += wt[i];
        tot_tat += tat[i];
    }

    printf("Gantt Chart:\n\n");
      printf("| P%d ", ganttp[0]);
   
    for (i = 1; i < ganttIndex; i++) {
        if(ganttp[i]!=ganttp[i-1]){
        printf("| P%d ", ganttp[i]);
    }
    }
    printf("|\n");
    printf("  %d",ganttT[0]);
    for (i = 1; i <= ganttIndex; i++) {
        if(i==ganttIndex||ganttp[i]!=ganttp[i-1]){
        printf("  %d ", ganttT[i]);
    }}

    printf("\n");
    avg_wt = tot_wt / n;
    avg_tat = tot_tat / n;
    printf("\n Process | Burst Time | Waiting Time | Turnaround Time |\n");
    for(i = 0; i < n; i++) {
        printf("|  P%d\t\t%d\t\t%d\t\t%d\t |\n", i + 1, bt[i], wt[i], tat[i]);
    }
    printf("\nAverage waiting time: %.2f\n", avg_wt);
    printf("Average turnaround time: %.2f\n", avg_tat);
    return 0;
}