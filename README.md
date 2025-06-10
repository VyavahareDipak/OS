
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
