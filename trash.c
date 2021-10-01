include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#define BUFFER 10
int mutex = 1, full = 0, empty = 10;

int arr[BUFFER] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void wait()
{
    while (mutex <= 0)
        ;
    mutex--;
}
void signal()
{
    mutex++;
}

void *producerfn(void *arg)
{
    while (1)
    {
        if (full < 10 && empty > 0)
        {
            wait(mutex);
            sleep(1);
            arr[full] = 1;
            full++;
            empty--;
            printf("Producer produces %d item\n", full);
            signal(mutex);
            if (full >= 10)
                printf("Buffer is full\n");
        }
    }
}

void *consumerfn(void *arg)
{
    while (1)
    {
        if (empty < 10 && full > 0)
        {
            wait(mutex);
            sleep(1);
            arr[full] = 0;
            full--;
            empty++;
            printf("Consumer consumes %d item\n", full);
            signal(mutex);
            if (empty >= 10)
                printf("Buffer is empty\n");
        }
    }
}

int main(void)
{
    pthread_t producer, consumer;
    pthread_create(&producer, NULL, producerfn, NULL);
    pthread_create(&consumer, NULL, consumerfn, NULL);

    pthread_join(producer, NULL);
    pthread_join(consumer, NULL);
}
