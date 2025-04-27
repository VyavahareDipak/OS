
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

