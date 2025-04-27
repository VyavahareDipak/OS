#include <bits/stdc++.h>
using namespace std;

struct Process {
    int pid;
    int at;  // arrival time
    int bt;  // remaining burst time
    int priority;

    // Comparator for priority queue
    bool operator<(const Process& other) const {
        return priority > other.priority; // Min-heap: lower priority number means higher priority
    }
};

int main() {
    int n = 4;
    
    // Hardcoded processes (pid, arrival time, burst time, priority)
    vector<Process> processes = {
        {1, 0, 10, 2},
        {2, 1, 5, 1},
        {3, 2, 8, 3},
        {4, 3, 6, 2}
    };

    // Sort processes by arrival time
    sort(processes.begin(), processes.end(), [](Process a, Process b) {
        return a.at < b.at;
    });

    priority_queue<Process> pq; // Min-heap by priority (smaller number = higher priority)

    int t = 0; // current time
    int index = 0; // pointer to processes
    int completed = 0;
    vector<int> completion_time(n + 1, 0);

    while (completed != n) {
        // Push all newly arrived processes
        while (index < n && processes[index].at <= t) {
            pq.push(processes[index]);
            index++;
        }

        if (!pq.empty()) {
            Process current = pq.top();
            pq.pop();

            // Execute for 1 time unit
            current.bt--;
            t++;

            // If still has burst time, push it back
            if (current.bt > 0) {
                pq.push(current);
            } else {
                // Process finished
                completion_time[current.pid] = t;
                completed++;
            }
        } else {
            // No process is ready, time passes
            t++;
        }
    }

    cout << "Process\tArrival\tPriority\tCompletion\tTurnaround\tWaiting\n";
    for (auto p : processes) {
        int tat = completion_time[p.pid] - p.at;
        int wt = tat - p.bt; // Simplified later
        cout << p.pid << "\t" << p.at << "\t" << p.priority << "\t\t"
             << completion_time[p.pid] << "\t\t" 
             << tat << "\t\t" << wt << "\n";
    }

    return 0;
}
/*
Process Arrival Priority        Completion      Turnaround      Waiting
1       0       2               21              21              11
2       1       1               6               5               0
3       2       3               29              27              19
4       3       2               18              15              9

*/
