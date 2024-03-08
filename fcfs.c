#include <stdio.h>

int main() {
    int n;  // Number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int pid[n];     // Process IDs
    int arrival[n]; // Arrival times
    int burst[n];   // Burst times (CPU time required)
    int waiting[n]; // Waiting times
    int turnaround[n]; // Turnaround times

    // Input process details
    for (int i = 0; i < n; i++) {
        printf("\nProcess %d:\n", i + 1);
        printf("Arrival time: ");
        scanf("%d", &arrival[i]);
        printf("Burst time: ");
        scanf("%d", &burst[i]);
        pid[i] = i + 1;  // Assign process ID
    }

    // Sort processes by arrival time (FCFS order)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arrival[j] > arrival[j + 1]) {
                int temp = arrival[j];
                arrival[j] = arrival[j + 1];
                arrival[j + 1] = temp;

                temp = burst[j];
                burst[j] = burst[j + 1];
                burst[j + 1] = temp;

                temp = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = temp;
            }
        }
    }

    // Calculate waiting time and turnaround time for each process
    waiting[0] = 0;  // First process has no waiting time
    turnaround[0] = burst[0];  // Turnaround time = burst time for first process

    for (int i = 1; i < n; i++) {
        waiting[i] = waiting[i - 1] + burst[i - 1];  // Waiting time = previous waiting time + previous burst time
        turnaround[i] = waiting[i] + burst[i];  // Turnaround time = waiting time + burst time
    }

    float avg_waiting = 0, avg_turnaround = 0;

    // Print process details, waiting time, and turnaround time
    printf("\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", pid[i], arrival[i], burst[i], waiting[i], turnaround[i]);
        avg_waiting += waiting[i];
        avg_turnaround += turnaround[i];
    }

    avg_waiting /= n;
    avg_turnaround /= n;

    printf("\nAverage waiting time: %.2f\n", avg_waiting);
    printf("Average turnaround time: %.2f\n", avg_turnaround);

    return 0;
}
