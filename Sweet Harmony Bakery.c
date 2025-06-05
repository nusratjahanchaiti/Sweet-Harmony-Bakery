#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define max_customers 100

sem_t red_sem, blue_sem, queue_sem, tables_sem;
pthread_mutex_t lock;

int red_count = 0;
int blue_count = 0;
int total_customers, total_tables;

void *customer(void *arg) {
    int id = *(int*)arg;
    char color;
    if (id % 2 == 0) {
        color = 'R';
    } else {
        color = 'B';
    }
    printf("Customer %d (%c) is waiting to enter the bakery.\n", id, color);

    sem_wait(&queue_sem);

    pthread_mutex_lock(&lock);

    while ((color == 'R' && red_count >= blue_count + 1) ||
           (color == 'B' && blue_count >= red_count + 1)) {
        pthread_mutex_unlock(&lock);
        usleep(100000);
        pthread_mutex_lock(&lock);
    }

    if (color == 'R') {
        red_count++;
    } else {
        blue_count++;
    }

    printf("Customer %d (%c) entered the bakery. Red: %d, Blue: %d\n", id, color, red_count, blue_count);
    pthread_mutex_unlock(&lock);

    sem_wait(&tables_sem);
    printf("Customer %d (%c) found a table and is enjoying pastries.\n", id, color);

    sleep(rand() % 5 + 1);

    sem_post(&tables_sem);
    printf("Customer %d (%c) is leaving the bakery.\n", id, color);

    pthread_mutex_lock(&lock);
    if (color == 'R') {
        red_count--;
    } else {
        blue_count--;
    }

    pthread_mutex_unlock(&lock);
    sem_post(&queue_sem);
    return NULL;
}

int main() {
    printf("Enter the total number of customers: ");
    scanf("%d", &total_customers);

    printf("Enter the number of tables in the bakery: ");
    scanf("%d", &total_tables);

    sem_init(&queue_sem, 0, total_tables);
    sem_init(&tables_sem, 0, total_tables);
    pthread_mutex_init(&lock, NULL);

    pthread_t threads[max_customers];
    int customer_id[max_customers];

    for (int i = 0; i < total_customers; i++) {
        customer_id[i] = i;
        pthread_create(&threads[i], NULL, customer, &customer_id[i]);
        usleep(100000);
    }

    for (int i = 0; i < total_customers; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&red_sem);
    sem_destroy(&blue_sem);
    sem_destroy(&queue_sem);
    sem_destroy(&tables_sem);
    pthread_mutex_destroy(&lock);

    return 0;
}
