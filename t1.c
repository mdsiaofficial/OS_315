#include <stdio.h>
int main(){

  int bt[10], at[10], wt[10], tat[10], n;
  printf("Enter process no: ");
  scanf("%d", &n);

  for(int i=0; i<n; i++){
    printf("Enter burst time of process: ");
    scanf("%d", &bt[i]);
  }


  float awt=0, atat=0; 

  wt[0] = 0;
  tat[0] = bt[0] + wt[0];
  atat += tat[0];

  for(int i=1; i<n; i++){
    wt[i] = bt[i-1] + wt[i-1];
    awt += wt[i];
    tat[i] = bt[i] + wt[i];
    atat += tat[i];
  }

  atat /= n;
  awt /= n;

  printf("Process\t\tBT\tWT\tTAT\t\n");
  for(int i=0; i<n; i++){
    printf("p[%d]\t\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
  }
  printf("Avg wt: %f\nAvg tat: %f\n", awt, atat);

}