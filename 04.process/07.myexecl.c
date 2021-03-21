#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>

int main(void) {
	pid_t pid;

	switch (pid=fork()) {
		case -1:
				perror("fork failed");
				break;
		case 0:				// child process
				printf("CHILD PROCESS : %d\n", getpid());
				execl("./00.mytask", "00.mytask", "100", (char *)0);
				// for(int i=0; i<100; i++){
					// printf("MyTask_%i\n", i);
					// sleep(1);
				// }
				perror("execl failed");
		default:
				system("ps -ejl | head -1");
				system("ps -ejl | tail -5");
				printf("PARENT PROCESS : %d\n", getpid());
				wait((int *)0);
				printf("parent : completed!\n");
				exit(0);
	}
	return 0;
}
