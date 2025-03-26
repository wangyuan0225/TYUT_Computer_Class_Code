/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : OS
  * @File           : fork.c
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024/11/11 9:06
  * @Version        : 1.0
  ****************************************************************************************
  */
// fork.c
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    pid_t childpid;
    int retval;
    int status;
    childpid = fork();
    if (childpid >= 0) {
        if (childpid == 0) {
            printf("CHILD: I am the child process! \n");
            printf("CHILD: Here's my PID: %d\n", getpid());
            printf("CHILD: My parent's PID is: %d\n", getppid());
            printf("CHILD: The value of fork return is: %d\n", childpid);
            printf("CHILD: Sleep for 1 second...\n");
            sleep(1);
            printf("CHILD: Enter an exit value (0 to 255): ");
            scanf("%d", &retval);
            printf("CHILD: Goodbye!\n");
            exit(retval);
        } else {
            printf("PARENT: I am the parent process! \n");
            printf("PARENT: Here's my PID: %d\n", getpid());
            printf("PARENT: The value of my child's PID is: %d\n", childpid);
            printf("PARENT: I will now wait for my child to exit.\n");
            wait(&status);
            printf("PARENT: Child's exit code is: %d\n", WEXITSTATUS(status));
            printf("PARENT: Goodbye!\n");
            exit(0);
        }
    } else {
        perror("fork error!");
        exit(0);
    }

    return 0;
}
