# Sweet Harmony Bakery
**Sweet Harmony Bakery** is a multithreaded C simulation that models a fair entry system for a bakery. Customers are divided into two color-coded groups — **Red** and **Blue** — and must maintain a balance when entering the bakery. The program uses POSIX threads, semaphores, and mutexes to simulate real-world constraints like limited seating and fair queuing.

---

##  Problem Description

- Customers are categorized:
  - Even-numbered IDs → **Red**
  - Odd-numbered IDs → **Blue**
- Entry condition:
  - No group can outnumber the other by more than 1.
- Inside the bakery:
  - Limited number of **tables** are shared.
  - Each customer spends random time enjoying pastries.

---

##  Key Components
| Component            | Description                                    |
| -------------------- | ---------------------------------------------- |
| `pthread_t`          | Thread management for customers                |
| `sem_t`              | Semaphores for queue and table synchronization |
| `pthread_mutex_t`    | Mutex for shared variable safety               |
| `sleep() / usleep()` | Simulates wait and enjoy time                  |


##  Constraints
Max supported customers: 100
(Adjust #define max_customers to change this.)

---

##  Build Instructions 
To compile the program, use the following command:
```bash
gcc -pthread -o sweet_harmony sweet_harmony.c
```
To run the compiled executable:

```bash
./sweet_harmony

