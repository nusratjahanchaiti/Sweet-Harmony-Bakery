# Sweet Harmony Bakery
In the small, picturesque town of Pastelville, there is a lovely bakery called "Sweet Harmony."
This bakery is famous for its scrumptious pastries and charming atmosphere. The bakery has a
limited number of tables for customers to sit and enjoy their treats. To maintain the pleasant
ambiance, they have a unique rule: at any given time, there can only be an equal number of
customers wearing red and blue outfits inside the bakery.

**Sweet Harmony Bakery** is a multithreaded C simulation that models a fair entry system for a bakery. Customers are divided into two color-coded groups — **Red** and **Blue** — and must maintain a balance when entering the bakery. The program uses POSIX threads, semaphores, and mutexes to simulate real-world constraints like limited seating and fair queuing.

---

##  Features

- Fair admission: Red and Blue customers alternate fairly.
- Table management: Limited tables using semaphores.
- Thread-safe logic with mutexes.
- Randomized pastry enjoyment times.
- Clean resource management (joins, destroys).

---

## 📋 Problem Description

- Customers are categorized:
  - Even-numbered IDs → **Red**
  - Odd-numbered IDs → **Blue**
- Entry condition:
  - No group can outnumber the other by more than 1.
- Inside the bakery:
  - Limited number of **tables** are shared.
  - Each customer spends random time enjoying pastries.

---
## 🔄 How It Works
Each customer is created as a thread.

 1. Threads are color-coded based on ID (Red or Blue).

 2. queue_sem: limits number of customers trying to enter.

 3. tables_sem: manages access to a limited number of tables.

 4. mutex lock: protects shared counters (red_count, blue_count).

 5. Fair entry is enforced using color balance conditions.

 6. Customers randomly stay between 1–5 seconds.

---
## 📦 Key Components
| Component            | Description                                    |
| -------------------- | ---------------------------------------------- |
| `pthread_t`          | Thread management for customers                |
| `sem_t`              | Semaphores for queue and table synchronization |
| `pthread_mutex_t`    | Mutex for shared variable safety               |
| `sleep() / usleep()` | Simulates wait and enjoy time                  |

## Cleanup
After all customers have completed their visit:

- All threads are joined.

- All semaphores are destroyed.

- Mutex is released.

## ⚠️ Constraints
Max supported customers: 100
(Adjust #define max_customers to change this.)

## 📚 Dependencies
- POSIX Threads: -pthread

- Standard headers:

  - <stdio.h>

  - <stdlib.h>

  - <unistd.h>

  - <pthread.h>

  - <semaphore.h>

## 🏗️ Build Instructions 
To compile the program, use the following command:
<pre> gcc -pthread -o sweet_harmony sweet_harmony.c </pre>

To run the compiled executable:

```bash
./sweet_harmony

