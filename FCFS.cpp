#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Process {
    int pid;    // Process ID
    int at;     // Arrival Time
    int bt;     // Burst Time
    int ct;     // Completion Time
    int tat;    // Turnaround Time
    int wt;     // Waiting Time
};

// Sort by Arrival Time, then by Process ID
bool compareArrival(Process a, Process b) {
    if (a.at == b.at)
        return a.pid < b.pid;
    return a.at < b.at;
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);

    // Input
    for (int i = 0; i < n; i++) {
        cout << "Enter Process ID, Arrival Time and Burst Time for Process " << i + 1 << ": ";
        cin >> p[i].pid >> p[i].at >> p[i].bt;
    }

    // Sort processes by arrival time
    sort(p.begin(), p.end(), compareArrival);

    int current_time = 0;
    float total_tat = 0, total_wt = 0;

    for (int i = 0; i < n; i++) {
        if (current_time < p[i].at) {
            current_time = p[i].at;
        }

        p[i].ct = current_time + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;

        current_time = p[i].ct;

        total_tat += p[i].tat;
        total_wt += p[i].wt;
    }

    // Output
    cout << "\nFCFS Scheduling Result:\n";
    cout << left << setw(10) << "PID" << setw(10) << "AT" << setw(10) << "BT"
         << setw(10) << "CT" << setw(10) << "TAT" << setw(10) << "WT" << endl;

    for (const auto& proc : p) {
        cout << left << setw(10) << proc.pid << setw(10) << proc.at << setw(10) << proc.bt
             << setw(10) << proc.ct << setw(10) << proc.tat << setw(10) << proc.wt << endl;
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Turnaround Time: " << total_tat / n;
    cout << "\nAverage Waiting Time   : " << total_wt / n << endl;

    return 0;
}
