#include <stdio.h>
int WT[10], AT[10], BT[10], TAT[10];
int main()
{
    int n, temp[10];
    int count = 0, t = 0, short_P;
    float
        total_WT = 0,
        total_TAT = 0, Avg_WT, Avg_TAT;
    printf("Enter the number of the process\n");
    scanf("%d", &n);
    printf("Enter the arrival time:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &AT[i]);
    }
    printf("Enter the burst time:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &BT[i]);
        temp[i] = BT[i];
    }
    BT[9] = 10000;
    for (t = 0; count != n; t++)
    {
        short_P = 9;
        for (int i = 0; i < n; i++)
        {
            if (BT[i] < BT[short_P] && (AT[i] <= t &&
                                        BT[i] > 0))
            {
                short_P = i;
            }
        }
        BT[short_P] = BT[short_P] - 1;
        if (BT[short_P] == 0)
        {
            count++;
            WT[short_P] = t + 1 - AT[short_P] -
                          temp[short_P];
            TAT[short_P] = t + 1 - AT[short_P];
            total_WT = total_WT + WT[short_P];
            total_TAT = total_TAT + TAT[short_P];
        }
    }
    Avg_WT = total_WT / n;
    Avg_TAT = total_TAT / n;
    printf("Id\tAT\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
    {

        printf("%d\t%d\t%d\t%d\t%d\n", i + 1, AT[i], temp[i], WT[i], TAT[i]);
    }
    printf("Avg waiting time of the process is %f\n", Avg_WT);
    printf("Avg turn around time of the process %f\n", Avg_TAT);
}
