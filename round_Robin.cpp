#include <bits/stdc++.h>
using namespace std;

struct Process {
    int pid;
    int bt;  // burst time
    int at;  // arrival time
    int remaining_bt;  // remaining burst time for the process (to simulate preemption)

    Process(int p, int b, int a) : pid(p), bt(b), at(a), remaining_bt(b) {}
};

int main() {
    int n = 4;  // Number of processes
    int quantum = 4;  // Time quantum for each process
    
    // Hardcoded processes (pid, burst time, arrival time , remain_bt)
    vector<Process> processes = {
        {1, 10, 0},
        {2, 5, 1},
        {3, 8, 2},
        {4, 6, 3}
    };

    // Sort processes by arrival time
    sort(processes.begin(), processes.end(), [](Process a, Process b) {
        return a.at < b.at;
    });


    queue<Process> q; // Queue to simulate Round Robin scheduling
    int t = 0;  // current time
    int index = 0;  // pointer to processes
    vector<int> completion_time(n + 1, 0); // To store completion times
    vector<int> waiting_time(n + 1, 0); // To store waiting times
    vector<int> turnaround_time(n + 1, 0); // To store turnaround times


    while (index < n || !q.empty()) {
        // Push all processes that have arrived by time t into the queue
        while (index < n && processes[index].at <= t) {
            q.push(processes[index]);
            index++;
        }

        if (!q.empty()) {
            Process current = q.front();
            q.pop();

            // Execute the process for the time quantum or until it finishes
            int exec_time = min(current.remaining_bt, quantum);
            current.remaining_bt -= exec_time;
            t += exec_time;

            // If the process is finished, record its completion time
            if (current.remaining_bt == 0) {
                completion_time[current.pid] = t;
            } else {
                // If it's not finished, put it back in the queue
                q.push(current);
            }
        } else {
            // If no process is ready, time passes
            t++;
        }
    }

    // Calculate waiting and turnaround times
    for (int i = 0; i < n; i++) {
        int tat = completion_time[processes[i].pid] - processes[i].at;
        int wt = tat - processes[i].bt;
        turnaround_time[processes[i].pid] = tat;
        waiting_time[processes[i].pid] = wt;
    }

    // Display results
    cout << "Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i].pid << "\t" 
             << processes[i].at << "\t\t" 
             << processes[i].bt << "\t\t"
             << completion_time[processes[i].pid] << "\t\t"
             << turnaround_time[processes[i].pid] << "\t\t"
             << waiting_time[processes[i].pid] << "\n";
    }

    return 0;
}

/*
Process Arrival Time    Burst Time      Completion Time Turnaround Time Waiting Time
1       0               10              22              22              12
2       1               5               23              22              17
3       2               8               27              25              17
4       3               6               29              26              20
*/
