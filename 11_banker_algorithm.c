#include<stdio.h>
#include<stdbool.h>

int main()
{
    int n, i, j;
    int tr[3] = {10, 5, 7};
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int allocation[n][3], max[n][3], remain[n][3], total_alloc[3] = {0, 0, 0}, available[3];
    bool finished[n];
    int safe_sequence[n], index = 0;
    for(i = 0; i < n; i++) {
        finished[i] = false;
    }
    printf("Enter the allocated resources:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }
    printf("Enter the maximum needed resources:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &max[i][j]);
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < 3; j++) {
            remain[i][j] = max[i][j] - allocation[i][j];
        }
    }
    for (j = 0; j < 3; j++) {
        for (i = 0; i < n; i++) {
            total_alloc[j] = total_alloc[j] + allocation[i][j];
        }
    }
    for (j = 0; j < 3; j++) {
        available[j] = tr[j] - total_alloc[j];
    }
    printf("Available resources:\n");
    for (j = 0; j < 3; j++) {
        printf("Resource %d: %d\n", j + 1, available[j]);
    }
    while (index < n) {
        bool found = false;
        for (i = 0; i < n; i++) {
            if (!finished[i]) {
                bool possible = true;
                for (j = 0; j < 3; j++) {
                    if (remain[i][j] > available[j]) {
                        possible = false;
                        break;
                    }
                }
                if (possible) {
                    for (j = 0; j < 3; j++) {
                        available[j] += allocation[i][j];
                    }
                    safe_sequence[index++] = i;
                    finished[i] = true;
                    found = true;
                }
            }
        }
        if (!found) {
            printf("System is in a deadlock state.\n");
            return 0;
        }
    }

    printf("System is in a safe state.\nSafe sequence is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", safe_sequence[i]);
    }
    printf("\n");

    return 0;
}
