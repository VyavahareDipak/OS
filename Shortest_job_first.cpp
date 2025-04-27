#include <iostream>
#include <algorithm>
using namespace std;

struct Process {
    int pid, bt;
};

bool cmp(Process a, Process b) {
    return a.bt < b.bt;
}

int main() {
    int n = 4;
    Process p[] = {{1, 6}, {2, 8}, {3, 7}, {4, 3}}; // Hardcoded processes

    sort(p, p + n, cmp);

    int waiting_time[n], turnaround_time[n];
    waiting_time[0] = 0;

    for (int i = 1; i < n; i++) {
        waiting_time[i] = p[i-1].bt + waiting_time[i-1];
    }

    for (int i = 0; i < n; i++) {
        turnaround_time[i] = p[i].bt + waiting_time[i];
    }

    cout << "Process\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << p[i].pid << "\t" << p[i].bt << "\t\t" 
             << waiting_time[i] << "\t\t" << turnaround_time[i] << "\n";
    }
}
