//fcfs arrival time=0
#include <stdio.h>
int burst[50];
int i, n;
int wat[50], turn[50];
int wait()
{
    wat[0] = 0;
    for (i = 1; i < n; i++)
    {
        wat[i] = wat[i - 1] + burst[i - 1];
    }
}
int tat()
{
    for (i = 0; i < n; i++)
    {
        turn[i] = wat[i] + burst[i];
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
    printf("Enter Burst time:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &burst[i]);
    }
    wait();
    tat();
    printf("\nTABLE:\n");
    printf("Process\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
    {

        printf("P%d\t%d\t%d\t%d\n", i + 1, burst[i], wat[i], turn[i]);
    }
    printf("\nAverage waiting time:");
    average(wat);
    printf("\nAverage turn around time:");
    average(turn);
}
