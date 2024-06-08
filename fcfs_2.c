// fcfs arrival time != 0
#include <stdio.h>
int
    n,
    x, i, y, temp, pid[50], at[50], bt[50], wt[50], tat[50], ct[50], sum = 0;
int sort()
{
    for (x = 0; x < n - 1; x++)
    {
        for (y = 0; y < n - x - 1; y++)
        {
            if (at[y] > at[y + 1])
            {
                temp = at[y];
                at[y] = at[y + 1];
                at[y + 1] = temp;
                temp = pid[y];
                pid[y] = pid[y + 1];
                pid[y + 1] = temp;
                temp = bt[y];
                bt[y] = bt[y + 1];
                bt[y + 1] = temp;
            }
        }
    }
}
int average(int arr[])
{
    float sum = 0.0;
    float avg;
    for (i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    avg = sum / n;
    printf("%.2f", avg);
}
int main()
{
    printf("Enter no. of processes:");
    scanf("%d", &n);
    printf("Enter process no.s:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &pid[i]);
    }
    printf("Enter arrival time:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &at[i]);
    }
    printf("Enter burst time:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }
    sort();
    sum += bt[0];
    ct[0] += sum;
    for (i = 1; i < n; i++)
    {
        sum += bt[i];
        ct[i] += sum + 1;
    }
    for (i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
    }
    for (i = 0; i < n; i++)
    {
        wt[i] = tat[i] - bt[i];
    }
    for (x = 0; x < n - 1; x++)
    {
        for (y = 0; y < n - x - 1; y++)
        {
            if (pid[y] > pid[y + 1])
            {
                temp = at[y];
                at[y] = at[y + 1];
                at[y + 1] = temp;
                temp = pid[y];
                pid[y] = pid[y + 1];
                pid[y + 1] = temp;
                temp = bt[y];
                bt[y] = bt[y + 1];
                bt[y + 1] = temp;
                temp = ct[y];
                ct[y] = ct[y + 1];
                ct[y + 1] = temp;
                temp = tat[y];
                tat[y] = tat[y + 1];
                tat[y + 1] = temp;
                temp = wt[y];
                wt[y] = wt[y + 1];
                wt[y + 1] = temp;
            }
        }
    }
    printf("TABLE:\n");
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++)
    {

        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i],
               bt[i], ct[i], tat[i], wt[i]);
    }
    printf("\nAverage waiting time:");
    average(wt);
    printf("\nAverage turn around time:");
    average(tat);
}