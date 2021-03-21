#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

static void handler (int signo){
	printf ("%s[%d] signal is caughted\n", sys_siglist[signo], signo);
}

int main (void){
	int status;
	pid_t pid;
	printf("PID of Parent = %d\n", getpid());
	if(fork() == 0){
		printf("PID of child ============= %d\n", getpid());
		signal(SIGINT, handler);
		pause();
		exit(10);
	}
	pid = wait (&status);
	printf("PID of Child terminated = %d\n", pid);
	if (pid == -1)
		perror ("wait");
	if (WIFEXITED (status))
		printf ("Normal termination with exit status=%d\n", WEXITSTATUS (status));
	if (WIFSIGNALED (status))
		printf ("Killed by signal=%d%s\n", WTERMSIG (status), \
										WCOREDUMP (status) ? " (dumped core)" : "");
	return 0;
}