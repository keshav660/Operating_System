#include <stdio.h>
int main() {
    int n;
    printf("Enter the total number of processes: ");
    scanf("%d", &n);
    int At[n], Bt[n], ct[n], tat[n], wt[n];

    printf("Enter the arrival times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &At[i]);
    }
    printf("Enter the burst times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &Bt[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (At[j] > At[j + 1]) {
            
                int tempAt = At[j];
                At[j] = At[j + 1];
                At[j + 1] = tempAt;

                int tempBt = Bt[j];
                Bt[j] = Bt[j + 1];
                Bt[j + 1] = tempBt;
            }
        }
    }
    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (currentTime < At[i]) {
            currentTime = At[i]; 
        }
    
        ct[i] = currentTime + Bt[i];
        tat[i] = ct[i] - At[i];
        wt[i] = tat[i] - Bt[i];
        
        currentTime = ct[i];
    }
    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, At[i], Bt[i], ct[i], tat[i], wt[i]);
    }
    
    return 0;
}