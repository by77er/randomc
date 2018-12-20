#include <pthread.h>
#include <stdio.h>

typedef struct _item {
    int locked; // 0: unlocked - 1: locked
    int num; // integer
} P_pointer;

P_pointer val = {0, 0};

void acquire_lock(P_pointer* protected) { // basic spinlock
    asm( "lock_retry:"
         "  xor %%eax, %%eax;"
         "  mov $1, %%ebx;"
         "  lock cmpxchg %%ebx, %0;" // atomic operation
         "  jnz lock_retry;"
    :"=m"(protected->locked)
    :
    :"%eax", "%ebx"
    );
}

void release_lock(P_pointer* protected) {
    protected->locked = 0;
}

void *loopadd(void* _) {
    unsigned long cur = pthread_self(); // store this
    for (int j = 0; j < 1000; j++) {
        acquire_lock(&val);
        printf("\rThread %lu owns i", cur);
        val.num++;
        release_lock(&val);
    }
    return NULL;
}

int main(void) {
    printf("Initial value of i: %d\n", val.num);

    pthread_t threads[10];
    // schedule threads
    for (int k = 0; k < sizeof(threads)/sizeof(pthread_t); k++) {
        pthread_create(&threads[k], NULL, &loopadd, NULL);
    }
    // wait for threads
    for (int l = 0; l < sizeof(threads)/sizeof(pthread_t); l++) { 
        pthread_join(threads[l], NULL); // will all eventually return 0
    }
    
    printf("\rFinal value of i: %d          \n", val.num);
}