#include <stdio.h>
int main() {
    int n;
    printf("Enter the total number of processes: ");
    scanf("%d", &n);
    int at[n], bt[n], remaining_bt[n], ct[n], tat[n], wt[n], done[n];
    int total_tat = 0, total_wt = 0;

    printf("Enter the arrival times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &at[i]);
        done[i] = 0;
    }
    
    printf("Enter the burst times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        remaining_bt[i] = bt[i];
    }

    int time = 0, completed = 0, min_bt, sj;
    while (completed < n) {
        min_bt = 9999;
        sj = -1;

        for (int i = 0; i < n; i++) {
            if (at[i] <= time && !done[i] && remaining_bt[i] < min_bt && remaining_bt[i] > 0) {
                min_bt = remaining_bt[i];
                sj = i;
            }
        }
        if (sj == -1) {
            time++;
            continue;
        }
        remaining_bt[sj]--;
        time++;
        if (remaining_bt[sj] == 0) {
            completed++;
            done[sj] = 1;
            ct[sj] = time;
            tat[sj] = ct[sj] - at[sj];
            wt[sj] = tat[sj] - bt[sj];
        }
    }
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
        total_tat += tat[i];
        total_wt += wt[i];
    }
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_tat / n);
    printf("Average Waiting Time: %.2f\n", (float)total_wt / n);
    return 0;
}
