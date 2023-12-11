#include "types.h"
#include "user.h"
// #include <stdio.h>

#define PROCS_NUM 5

int main()
{
    printf(1 , "foo userprogram started\n");
    for (int i = 0; i < PROCS_NUM; ++i)
    {
        int pid = fork();
        if (pid > 0)
            continue;
        if (pid == 0)
        {
            sleep(2000);
            for (int j = 0; j < 1000 * i; ++j)
            {
                int x = 5;
                for (long k = 0; k < 10000000000; ++k)
                    x++;
            }
            exit();
        }
    }
    while (wait() != -1)
        ;
    exit();
}