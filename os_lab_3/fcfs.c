#include <stdio.h>
int main()
{
    int processes;
    printf("Enter Number of processes : ");
    scanf("%d", &processes);
    printf("\n");
    int burstTime[processes];
    int arrivalTime[processes];
    int turnAroundTime[processes];
    int waitingTime[processes];
    int ganttChart[processes * 2];
    int processArray[processes];
    for (int i = 0; i < processes; i++)
    {
        processArray[i] = i;
        printf("Enter Arrival and Burst Time of Process - %d : ", i);
        scanf("%d %d", &arrivalTime[i], &burstTime[i]);
        printf("\n");
    }

    for (int i = 0; i < processes; i++)
    {
        for (int j = 0; j < processes - i - 1; j++)
        {
            if (arrivalTime[j] > arrivalTime[j + 1])
            {
                int temp = arrivalTime[j];
                arrivalTime[j] = arrivalTime[j + 1];
                arrivalTime[j + 1] = temp;
                temp = burstTime[j];
                burstTime[j] = burstTime[j + 1];
                burstTime[j + 1] = temp;
                temp = processArray[j];
                processArray[j] = processArray[j + 1];
                processArray[j + 1] = temp;
            }
        }
    }

    int completionTime[processes];
    int start = 0;
    int k = 0;
    for (int i = 0; i < processes; i++)
    {
        ganttChart[k] = start;
        ganttChart[k + 1] = start + burstTime[i];
        k += 2;
        start += burstTime[i];
        completionTime[i] = start;
        turnAroundTime[i] = completionTime[i] - arrivalTime[i];
        printf("The Turn-Around-Time for process P%d is : %d", i, turnAroundTime[i]);
        waitingTime[i] = turnAroundTime[i] - burstTime[i];
        printf("The Waiting Time for process P%d is : %d\n", i, waitingTime[i]);
        printf("The Completion Time for process P%d is : %d\n", i, completionTime[i]);
        printf("\n");
    }
    int avgTurnAroundTime = 0;
    int avgWaitingTime = 0;
    for (int i = 0; i < processes; i++)
    {
        avgTurnAroundTime += turnAroundTime[i];
        avgWaitingTime += waitingTime[i];
    }
    int z = 0;
    for (int i = 0; i < processes; i++)
    {
        printf("---------------");
    }
    printf("\n");
    printf("|");
    while (z < processes)
    {
        printf("      P%d      |", processArray[z]);
        z++;
    }
    printf("\n");
    for (int i = 0; i < processes; i++)
    { 
        printf("---------------");
    }
    printf("\n");
    printf("|");
    z = 0;
    while (z < processes * 2)
    {
        printf("   %d - %d   |", ganttChart[z], ganttChart[z + 1]);
        z += 2;
    }
    printf("\n");
    for (int i = 0; i < processes; i++)
    {
        printf("---------------");
    }
    printf("\n");
    printf("The Average Turn-Around-Time is : %d\n", avgTurnAroundTime / processes);
    printf("\n");
    printf("The Average Waiting Time is : %d\n", avgWaitingTime / processes);
    return 0;
}