#include <stdio.h>
#include <pthread.h>

int use_barrier;
pthread_barrier_t barrier;

void *slave(void *arg)
{
    int id = (int)arg;
    printf("T%d\n", id);

    // The synchornization point
    if (use_barrier)
        pthread_barrier_wait(&barrier);

    printf("  T%d\n", id);
    return NULL;
}

#define NUMBER 3
void test()
{
    int i;
    pthread_t tids[NUMBER];

    pthread_barrier_init(&barrier, NULL, NUMBER);
    for (i = 0; i < NUMBER; i++)
        pthread_create(&tids[i], NULL, slave, (void *)i);

    for (i = 0; i < NUMBER; i++)
        pthread_join(tids[i], NULL);
    pthread_barrier_destroy(&barrier);
}

int main()
{
    use_barrier = 0;
    test();
    puts("");

    use_barrier = 1;
    test();
    puts("");
    return 0;
}
