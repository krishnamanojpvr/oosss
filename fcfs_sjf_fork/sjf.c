/* Write a program for SJF
Enter the number of process:4
Enter process name, arrival time& burst time:1
1
3
Enter process name, arrival time& burst time:2
2
4
Enter process name, arrival time& burst time:3
1
2
Enter process name, arrival time& burst time:4
4
4

Processname	arrivaltime	bursttime	waitingtime	turnaroundtime
3	       1		       2		       0		       2
1	       1		       3		       2		       5
2	       2		       4		       4		       8
4	       4		       4		       6		      10
Average waiting time: 3.000000
Average turnaroundtime: 6.250000*/
#include<stdio.h>

int main(){
    int n;
    printf("Enter the number of process:");
    scanf("%d",&n);
    int processname[n], arrivaltime[n], bursttime[n];
    int waitingtime[n], turnaroundtime[n];
    int totalwaitingtime = 0, totalturnaroundtime = 0;
    for(int i=0;i<n;i++){
        printf("Enter process name , arrival time& burst time:");
        scanf("%d",&processname[i]);
        scanf("%d",&arrivaltime[i]);
        scanf("%d",&bursttime[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arrivaltime[j] < arrivaltime[i]) {
                int temp = arrivaltime[i];
                arrivaltime[i] = arrivaltime[j];
                arrivaltime[j] = temp;
                temp = bursttime[i];
                bursttime[i] = bursttime[j];
                bursttime[j] = temp;
                temp = processname[i];
                processname[i] = processname[j];
                processname[j] = temp;
            }
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arrivaltime[i] == arrivaltime[j] && bursttime[j] < bursttime[i]) {
                int temp = arrivaltime[i];
                arrivaltime[i] = arrivaltime[j];
                arrivaltime[j] = temp;
                temp = bursttime[i];
                bursttime[i] = bursttime[j];
                bursttime[j] = temp;
                temp = processname[i];
                processname[i] = processname[j];
                processname[j] = temp;
            }
        }
    }
    waitingtime[0] = 0;
    for (int i = 1; i < n; i++) {
        if (arrivaltime[i] > arrivaltime[i - 1] + bursttime[i - 1]) {
            waitingtime[i] = 0;
        } else {
            waitingtime[i] = waitingtime[i - 1] + bursttime[i - 1] - (arrivaltime[i] - arrivaltime[i - 1]);
        }
    }
    for (int i = 0; i < n; i++) {
        turnaroundtime[i] = waitingtime[i] + bursttime[i];
    }
    for (int i = 0; i < n; i++) {
        totalwaitingtime += waitingtime[i];
        totalturnaroundtime += turnaroundtime[i];
    }
    printf("\nProcessname\tarrivaltime\tbursttime\twaitingtime\tturnaroundtime\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processname[i], arrivaltime[i], bursttime[i], waitingtime[i], turnaroundtime[i]);
    }
    float avgwaitingtime = (float)totalwaitingtime / n;
    float avgturnaroundtime = (float)totalturnaroundtime / n;
    printf("Average waiting time: %f\n", avgwaitingtime);
    printf("Average turnaroundtime: %f\n", avgturnaroundtime);
    return 0;
}