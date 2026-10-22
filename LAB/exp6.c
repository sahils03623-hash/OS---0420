
#include <stdio.h>
int main() {
    int n, i, time = 0, completed = 0;
    int at[20], bt[20], rt[20], priority[20];
    int ct[20], tat[20], wt[20];
    int smallest, minPriority;
    float avgWT = 0, avgTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter Arrival Time, Burst Time and Priority for P%d: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &priority[i]);
        rt[i] = bt[i];
    }

    while (completed < n) {
        smallest = -1;
        minPriority = 9999;

        for (i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0) {
                if (priority[i] < minPriority) {
                    minPriority = priority[i];
                    smallest = i;
                }
            }
        }

        if (smallest == -1) {
            time++;
            continue;
        }

        rt[smallest]--;
        time++;

        if (rt[smallest] == 0) {
            completed++;
            ct[smallest] = time;
        }
    }

    printf("\nProcess\tAT\tBT\tPriority\tCT\tTAT\tWT\n");

    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avgTAT += tat[i];
        avgWT += wt[i];

        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], priority[i],
               ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", avgTAT / n);
    printf("\nAverage Waiting Time = %.2f\n", avgWT / n);

    return 0;
}

