#include <stdio.h>

int main() {
    int n, quantum;
    printf("Enter the total number of processes: ");
    scanf("%d", &n);
    int at[n], bt[n], remaining_bt[n], ct[n], tat[n], wt[n];
    int total_tat = 0, total_wt = 0;
    
    printf("Enter the arrival times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }
    
    printf("Enter the burst times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        remaining_bt[i] = bt[i];
    }
    
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);
    
    int time = 0, completed = 0;
    
    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && remaining_bt[i] > 0) {
                if (remaining_bt[i] > quantum) {
                    time += quantum;
                    remaining_bt[i] -= quantum;
                } else {
                    time += remaining_bt[i];
                    ct[i] = time;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];
                    remaining_bt[i] = 0;
                    completed++;
                }
            }
        }
    }
    
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
        total_tat += tat[i];
        total_wt += wt[i];
    }
    
    printf("\nAverage Turnaround Time: %.2f\n", (float) total_tat / n);
    printf("Average Waiting Time: %.2f\n", (float) total_wt / n);
    
    return 0;
}
