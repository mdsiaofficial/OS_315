#include <stdio.h>
int main()
{
  int bt[10], wt[10], tat[10];
  double awt, atat;

  int n;
  printf("Enter process no. : ");
  scanf("%d", &n);

  printf("Enter %d burst times: ", n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &bt[i]);
  }

  wt[0] = 0;
  tat[0] = bt[0];
  awt += wt[0];
  atat += bt[0];

  for (int i = 1; i < n; i++)
  {
    wt[i] = wt[i - 1] + bt[i - 1];
    awt += wt[i];
    tat[i] = bt[i] + wt[i];
    atat += tat[i];
  }

  printf("Process\t\tBT\tWT\tTAT\n");
  for (int i = 0; i < n; i++)
  {
    printf("P[%d]\t\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
  }
  printf("Avg wt: %lf\n Avg tat: %lf\n", awt, atat);

  return 0;
}
