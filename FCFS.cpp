#include <iostream>
using namespace std;

int main() {
    int n = 4;
    int processes[] = {1, 2, 3, 4};
    int burst_time[] = {5, 9, 6, 2}; // Hardcoded burst times

    int waiting_time[n], turnaround_time[n];
    waiting_time[0] = 0;

    // Calculate waiting time
    for (int i = 1; i < n; i++) {
        waiting_time[i] = burst_time[i-1] + waiting_time[i-1];
    }

    // Calculate turnaround time
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
    }

    cout << "Process\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i] << "\t" << burst_time[i] << "\t\t" 
             << waiting_time[i] << "\t\t" << turnaround_time[i] << "\n";
    }
}
