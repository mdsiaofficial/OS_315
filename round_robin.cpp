#include <iostream>
using namespace std;
int main(){
    int bt[100], tq, i, n, rembt[100], t = 0, wt[100], c = 0, p[100], tat[100];
    double total = 0, avgwt = 0;
    cout << "Enter process number: ";
    cin >> n;
    for (i = 0; i < n; i++){
        cout << "Input burst time for process P" << i + 1 << endl;
        cin >> bt[i];
        p[i] = i + 1;

    }
    cout << "Take input time quantum." << endl;
    cin>>tq;

    for (i = 0; i < n;i++){
        rembt[i] = bt[i];
    }
    while (c!=n)
    {
        for (i = 0; i < n; i++){
            if(rembt[i]>tq){
                t += tq;
                rembt[i] -= tq;
            }else if(rembt[i]!=0){
                t += rembt[i];
                wt[i] = t - bt[i];
                tat[i] = t;
                total += wt[i];
                rembt[i] = 0;
                c++;

            }
        }
    }

    avgwt = total / n;
    cout << "Process\tBurst Time\tWaiting Time\tTurnaround Time";
    for (i = 0; i < n; i++){
        total == bt[i];
        printf("P[%d]\t%d\t%d\t%d", p[i], bt[i], wt[i], tat[i]);
    }
    double avgtt = total / n;
    cout << "Average waiting time: " << avgwt << endl;
    cout << "Average turnaround time: " << avgtt << endl;
    return 0;
}
