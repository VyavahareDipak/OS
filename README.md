
# 📚 CPU Scheduling - Important Formulas

## 1. Turnaround Time (TAT)

\[
\text{TAT} = \text{Completion Time} - \text{Arrival Time}
\]

- **Meaning**:  
  How long a process stayed in the system from its arrival to completion.

---

## 2. Waiting Time (WT)

\[
\text{WT} = \text{Turnaround Time} - \text{Burst Time}
\]
or
\[
\text{WT} = (\text{Completion Time} - \text{Arrival Time}) - \text{Burst Time}
\]

- **Meaning**:  
  Total time the process spent waiting (not executing) inside the system.

---

## 🛠 Quick Example

| Process | Arrival Time (AT) | Burst Time (BT) | Completion Time (CT) |
|:-------:|:-----------------:|:---------------:|:--------------------:|
|    1    |        0           |        5        |          10          |

### Calculations:
- **Turnaround Time (TAT)** = CT - AT = 10 - 0 = **10**
- **Waiting Time (WT)** = TAT - BT = 10 - 5 = **5**

---

## ✅ Summary Table

| Term | Formula |
|:----|:--------|
| **Turnaround Time (TAT)** | Completion Time (CT) - Arrival Time (AT) |
| **Waiting Time (WT)** | Turnaround Time (TAT) - Burst Time (BT) |

---

## 🎯 Memory Trick
- First calculate **TAT** (easy: just CT - AT).
- Then **WT = TAT - BT**.  
  ➔ "Turnaround minus Burst gives Waiting."

algorithms
1 . FCFS
2 . Shortest job first (premtive / non-premptive) in non-preptive case just execute process completely
3 . Priority based (premtive / non-premptive) in non-preptive case just execute process completely
4 . Round robin
Input: List of processes with 
       - PI: Process ID 
       - AT: Arrival Time 
       - BT: Burst Time
## 1 . FCFS
1. Sort all processes by Arrival Time (AT).
   If two processes have the same AT, use PI as tie-breaker.

2. Initialize:
   - current_time = 0
   - For each process, compute:
     - CT  = Completion Time
     - TAT = Turnaround Time = CT - AT
     - WT  = Waiting Time = TAT - BT

3. For each process in sorted order:
   a. If current_time < AT:
         current_time = AT   (CPU idle until the process arrives)
   b. CT = current_time + BT
   c. TAT = CT - AT
   d. WT = TAT - BT
   e. Update current_time = CT

4. Output:
   - PI, AT, BT, CT, TAT, WT for each process
   - Average Turnaround Time (TAT)
   - Average Waiting Time (WT)
## 2. SJF. 
for premtive (shortest remaining time first). increment current time by 1 each time.
Input: List of processes with 
       - PI: Process ID 
       - AT: Arrival Time 
       - BT: Burst Time

1. Initialize:
   - completed = 0
   - current_time = 0
   - Mark all processes as "not completed"

2. While completed < total number of processes:
   a. From the list of processes that have arrived (AT <= current_time) and are not completed,
      pick the one with the smallest Burst Time (BT).
      If multiple such processes exist, break ties using:
         - lower BT first
         - then lower AT
         - then lower PI

   b. If no such process exists (CPU is idle), increment current_time.

   c. Else:
      i.   CT = current_time + BT
      ii.  TAT = CT - AT
      iii. WT = TAT - BT
      iv.  Mark process as completed
      v.   Update current_time = CT
      vi.  Increment completed count

3. Output:
   - PI, AT, BT, CT, TAT, WT for each process
   - Average Turnaround Time (TAT)
   - Average Waiting Time (WT)

## 3. Priority based . 
(primtive - increment current pointer by one each time and maintain remaining bt of each process)
Input: List of processes with 
       - PI: Process ID 
       - AT: Arrival Time 
       - BT: Burst Time 
       - Priority: Lower value means higher priority (e.g., 1 is highest)

1. Initialize:
   - completed = 0
   - current_time = 0
   - Mark all processes as "not completed"

2. While completed < total number of processes:
   a. From the list of processes that have arrived (AT <= current_time) and are not completed,
      pick the one with the **highest priority** (lowest priority number).
      If multiple such processes exist, break ties using:
         - lower AT first
         - then lower PI

   b. If no such process is found (CPU is idle), increment current_time.

   c. Else:
      i.   CT = current_time + BT
      ii.  TAT = CT - AT
      iii. WT = TAT - BT
      iv.  Mark process as completed
      v.   Update current_time = CT
      vi.  Increment completed count

3. Output:
   - PI, AT, BT, Priority, CT, TAT, WT for each process
   - Average Turnaround Time (TAT)
   - Average Waiting Time (WT)
## 4. Round Robin
   Input:
- List of processes with:
     PI: Process ID
     AT: Arrival Time
     BT: Burst Time
- TQ: Time Quantum (fixed CPU time slice for each process)

1. Initialize:
   - current_time = 0
   - A queue to maintain the order of ready processes
   - remaining_bt[] = copy of all burst times
   - CT = Completion Time (to be computed)
   - visited[] = to track if a process has been added to the queue
   - completed = 0

2. Sort processes by Arrival Time (AT)
   Enqueue the first process that arrives at AT = 0

3. While completed < number of processes:
   a. Dequeue a process from the front of the queue

   b. If remaining_bt > TQ:
        - Execute process for TQ
        - current_time += TQ
        - remaining_bt -= TQ
   c. Else:
        - Execute process for remaining_bt
        - current_time += remaining_bt
        - CT = current_time
        - completed++
        - remaining_bt = 0

   d. After current_time is updated:
        - Enqueue all processes that have arrived (AT <= current_time)
          and are not visited yet
        - If the current process still has remaining_bt > 0,
          enqueue it again at the end

   e. If queue becomes empty:
        - Jump to the next uncompleted process with the earliest AT
        - Update current_time accordingly
        - Enqueue it

4. After completion:
   - For each process:
       TAT = CT - AT
       WT = TAT - BT

5. Output:
   - PI, AT, BT, CT, TAT, WT
   - Average Turnaround Time (TAT)
   - Average Waiting Time (WT)
