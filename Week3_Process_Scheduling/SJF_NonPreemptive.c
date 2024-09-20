#include <stdio.h>

int main() {
    int n;
    printf("Enter the total number of processes: ");
    scanf("%d", &n);
    int at[n], bt[n], ct[n], tat[n], wt[n], done[n];

    printf("Enter the arrival times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &at[i]);
        done[i] = 0;
    }
    printf("Enter the burst times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }
    int time = 0, count = 0;
    while (count < n) {
        int min_bt = 10000, sj = -1;
        
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && !done[i] && bt[i] < min_bt) {
                min_bt = bt[i];
                sj = i;
            }
        }       
        if (sj == -1) {
            time++;
            continue;
        }   
        time += bt[sj];
        ct[sj] = time;
        tat[sj] = ct[sj] - at[sj];
        wt[sj] = tat[sj] - bt[sj];
        done[sj] = 1;
        count++;
    }
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    return 0;
}
