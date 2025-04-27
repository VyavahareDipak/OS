#include <bits/stdc++.h>
using namespace std;

struct Process {
    int pid;
    int bt;  // remaining burst time
    int at;  // arrival time

    // Comparator for priority queue
    bool operator<(const Process& other) const {
        return bt > other.bt; // Min-heap based on remaining burst time
    }
};

int main() {
    int n = 4;
    
    // Hardcoded processes (pid,  burst time ,arrival time)
    vector<Process> processes = {
        {1, 8,0},
        {2, 4,1},
        {3, 2,2},
        {4, 1,3}
    };

    // Sort processes by arrival time
    sort(processes.begin(), processes.end(), [](Process a, Process b) {
        return a.at < b.at;
    });

    priority_queue<Process> pq; // Min-heap by remaining burst time

    int t = 0; // current time
    int index = 0; // pointer to processes
    int completed = 0;
    vector<int> completion_time(n + 1, 0);
    vector<int> waiting_time(n + 1, 0);

    while (completed != n) {
        // Push all processes that have arrived
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

            // If process still has burst time left, push it back
            if (current.bt > 0) {
                pq.push(current);
            } else {
                // Process completed
                completion_time[current.pid] = t;
                completed++;
            }
        } else {
            // No process ready, move time ahead
            t++;
        }
    }

    cout << "Process\tArrival\tCompletion\tTurnaround\tWaiting\n";
    for (auto p : processes) {
        int tat = completion_time[p.pid] - p.at;
        int wt = tat - p.bt;
        cout << p.pid << "\t" << p.at << "\t" 
             << completion_time[p.pid] << "\t\t" 
             << tat << "\t\t" << wt << "\n";
    }

    return 0;
}
