#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int counter = 0;  // Shared variable

void *increment_counter(void *arg) {
    while (1) {
        sleep(1);
        counter++;  // Increase counter every second
    }
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, increment_counter, NULL);

    char key;
    while (1) {
        printf("Press 'd' to display counter or 'q' to quit: ");
        scanf(" %c", &key);  // Read user input

        if (key == 'd') {
            printf("Counter: %d\n", counter);
        } else if (key == 'q') {
            break;
        }
    }

    pthread_cancel(thread);  // Stop the counter thread (optional)
    pthread_join(thread, NULL); // Wait for thread to exit
    return 0;
}

