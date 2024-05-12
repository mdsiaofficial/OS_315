#include <stdio.h>
int main()
{
  int i, n, j, temp, ta = 0, min;
  int bt[100], wt[100], ct[100], tat[100], pt[100], at[100], sum = 0, d = 0, k = 1;
  float awt = 0, atat = 0;
  printf("Shortest Job First Scheduling Non-Primitive(Varried Arrival)\n");
  printf("Enter the No. of processes : ");
  scanf("%d", &n);
  for (i = 0; i < n; i++)
  {
    printf("Enter the arrival time of %d process : ", i + 1);
    scanf("%d", &at[i]);
    printf("Enter the burst time of %d process : ", i + 1);
    scanf("%d", &bt[i]);
    pt[i] = i + 1;
  }
  /*Sorting According to Burst Time because arrival time is already sorted*/
  for(i=0; i<n; i++){
    for(j=i+1; i<n; j++){
      if(bt[i] > bt[j]){
        temp = bt[j];
        bt[j] = bt[i];
        bt[i] = temp;

        temp = at[j];
        at[j] = at[i];
        at[i] = temp;

        temp = pt[j];
        pt[j] = pt[i];
        pt[i] = temp;
      }
    }
  }

  min = at[0];

  for(i = 0; i<n; i++){
    if(min>at[i]){
      min = at[i];
      d = i;
    }
  }

  ta = min;
  ct[d] = ta + bt[d];
  ta = ct[d];

  for(i=0; i<n; i++){
    if(at[i] != min){
      ct[i] = bt[i] + ta;
      ta = ct[i];
    }
  }

  for(i=0; i<n; i++){
    tat[i] = ct[i] - at[i];
    atat += tat[i];
    wt[i] = tat[i] - bt[i];
    awt += wt[i];
    printf("P[%d]\t %3d\t%3d\t%4d\n", pt[i], bt[i], wt[i], tat[i]);
  }

  atat /= n;
  awt /= n;
  // printf("Process.\tB.T.\tW.T.\tT.A.T.\n");
  // for (i = 0; i < n; i++)
  // {
  //   printf("P[%d]\t %3d\t%3d\t%4d\n", pt[i], bt[i], wt[i], tat[i]);
  // }
  printf("Average Waiting Time: %0.3f\nAverage Turn Around Time:%0.3f", awt, atat);
  return 0;
}
