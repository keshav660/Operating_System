#include <stdio.h>
#include <stdlib.h>
int mutex = 1;
int empty = 3;
int full = 0;
int x = 0;
int wait(int S)
{
    return (--S);
}
int signal(int S)
{
    return (++S);
}
void producer()
{
    mutex = wait(mutex);
    empty = wait(empty);
    x++;
    printf("\nProduce item is %d", x);
    mutex = signal(mutex);
    full = signal(full);
}
void consumer()
{
    mutex = wait(mutex);
    full = wait(full);
    printf("\nConsume item is %d", x);
    x--;
    mutex = signal(mutex);
    empty = signal(empty);
}
int main()
{
    int n;
    printf("1. Producer\n2. Consumer\n3. Exit");
    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            if (mutex == 1 && empty > 0)
            {
                producer();
            }
            else
            {
                printf("\nBuffer is full!");
            }
            break;
        case 2:
            if (mutex == 1 && full > 0)
            {
                consumer();
            }
            else
            {
                printf("\nBuffer is empty!");
            }
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("\nInvalid choice!");
            break;
        }
    }
}
