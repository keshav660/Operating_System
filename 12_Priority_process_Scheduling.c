#include <stdio.h>

int main()
{
    struct Process
    {
        int id, at, bt, ct, tat, wt, priority;
    };

    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process proc[n];
    int total_tat = 0, total_wt = 0;
    printf("Enter the burst times of the processes: \n");
    for (int i = 0; i < n; i++)
    {
        proc[i].id = i;
        scanf("%d", &proc[i].bt);
    }
    printf("Enter the arrival times of the processes: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &proc[i].at);
    }

    printf("Enter the priorities of the processes: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &proc[i].priority);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (proc[j].priority > proc[j + 1].priority ||
                (proc[j].priority == proc[j + 1].priority && proc[j].at > proc[j + 1].at))
            {
                struct Process temp = proc[j];
                proc[j] = proc[j + 1];
                proc[j + 1] = temp;
            }
        }
    }

    int time = 0;
    printf("\nGantt Chart:\n|");

    for (int i = 0; i < n; i++)
    {
        if (time < proc[i].at)
        {
            time = proc[i].at;
        }
        time += proc[i].bt;
        proc[i].ct = time;
        proc[i].tat = proc[i].ct - proc[i].at;
        proc[i].wt = proc[i].tat - proc[i].bt;
        total_tat += proc[i].tat;
        total_wt += proc[i].wt;

        printf(" P%d |", proc[i].id); // Display Gantt chart
    }

    printf("\n\nAverage waiting time: %.2f", (float)total_wt / n);
    printf("\nAverage turnaround time: %.2f", (float)total_tat / n);

    return 0;
}
