#include <stdio.h>

void main() {
    int i, bt[10], wt[10], tat[10], p[10], pri[10], at[10], n, rt[10], time = 0, gantt_chart[100], gantt_index = 0, idx, gantt_time[100], completed = 0,prev=-1;
    float tot_wt = 0, tot_tat = 0;
    int min_gantt[100],min_time[100],gantt_minin=0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for P%d:\n", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        printf("Enter priority for P%d: ", i + 1);
        scanf("%d", &pri[i]);
        p[i] = i + 1;  
        rt[i] = bt[i]; 
    }
    while(completed != n) {
        int min_prio = 9999;
        idx = -1;
        for(i = 0; i < n; i++) {
            if(rt[i] > 0 && at[i] <= time && pri[i] < min_prio) {
                min_prio = pri[i];
                idx = i;
            }
        }
        if(idx == -1) {
            time++;
            continue;
        }
        rt[idx]--;
        if(prev!=idx){
        min_gantt[gantt_minin] = p[idx];
        min_time[gantt_minin] = time;
        gantt_minin++;
        prev=idx;
        }
        gantt_chart[gantt_index] = p[idx];
        gantt_time[gantt_index] = time;
        gantt_index++;
        time++;
        
        if(rt[idx] == 0) {
            tat[idx] = time - at[idx];  
            wt[idx] = tat[idx] - bt[idx]; 
            tot_wt+=wt[idx]; 
            tot_tat += tat[idx];
            completed++;
        }
        gantt_time[gantt_index]=time;
        min_time[gantt_minin]=time;
    }
    printf("\nGantt Chart:\n");
    printf("\n|");
    for(i = 0; i < gantt_index; i++) {
        printf("P%d|", gantt_chart[i]);
    }
    printf("\n0");
    for(i = 1; i <= gantt_index; i++) {
        printf(" %d", gantt_time[i]);
    }
    printf("\n");
printf("\nGantt Chart Min:\n");
printf("\n|");
for(i=0;i<gantt_minin;i++)
{
printf(" P%d |",min_gantt[i]);
}
printf("\n0");
for(i=1;i<=gantt_minin;i++)
{
printf("    %d",min_time[i]);
}
printf("\n");
    printf("\nProcess  Burst Time  Arrival Time  Waiting Time  Turnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], at[i], wt[i], tat[i]);
    }
    printf("\nAverage waiting time: %.2f", tot_wt / n);
    printf("\nAverage turnaround time: %.2f", tot_tat / n);
}