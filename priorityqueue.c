#include <stdio.h>
int main()
{
  int bt[20], p[20], wt[20], tat[20], pr[20], i, j, n, total = 0, pos, temp;
  float awt = 0, atat = 0;
  printf("Enter Total Number of Process:");
  scanf("%d", &n);

  printf("\nEnter Burst Time and Priority\n");
  for (i = 0; i < n; i++)
  {
    printf("\nP[%d]\n", i + 1);
    printf("Burst Time:");
    scanf("%d", &bt[i]);
    printf("Priority:");
    scanf("%d", &pr[i]);
    p[i] = i + 1; // contains process number
  }
  // sorting burst time, priority and process number in ascending order using selection sort
  for (i = 0; i < n; i++)
  {
    for (j = i + 1; j < n; j++)
    {
      if (pr[j] < pr[i])
      {
        temp = pr[i];
        pr[i] = pr[j];
        pr[j] = temp;

        temp = bt[i];
        bt[i] = bt[j];
        bt[j] = temp;

        temp = p[i];
        p[i] = p[j];
        p[j] = temp;
      }
    }
  }

  /*waiting time & turnaround time calculation of every process*/
  wt[0] = 0;
  tat[0] = bt[0] + wt[0];
  atat += tat[0];

  for (i = 1; i < n; i++)
  {
    wt[i] = bt[i - 1] + wt[i - 1];
    awt += wt[i];
    tat[i] = wt[i] + bt[i];
    atat += tat[i];
  }
  atat /= n;
  awt /= n;


  
  printf("\nProcess\t Burst Time \tWaiting Time\tTurnaround Time");
  for (i = 0; i < n; i++)
  {
    tat[i] = bt[i] + wt[i]; // calculate turnaround time
    total += tat[i];
    printf("\nP[%d]\t\t %d\t\t %d\t\t\t%d", p[i], bt[i], wt[i], tat[i]);
  }
  
  printf("\n\nAverage Waiting Time=%d", awt);
  printf("\nAverage Turnaround Time=%d\n", atat);
  return 0;
}
