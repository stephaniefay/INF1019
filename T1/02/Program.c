#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <signal.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	printf("\n>>>>>> Program initialized (pid = %d)\n", getpid());
	char * testvar = strdup(argv[2]), * pch;
	printf("DEBUG: %s\n", testvar);
	printf("%s %s %s\n", argv[0], argv[1], argv[2]);
	int fatherPid = strtol(argv[1], NULL, 10), timeSlice;
	printf("DEBUG: %d %d\n", fatherPid, timeSlice);
	pch = strtok (testvar, ",");
	while (pch != NULL) {
		timeSlice = atoi(pch);		
		for (int i = 0; i < timeSlice; i++) {
			sleep(1);
			printf("\n>>>>>> Pid: %d\n", getpid());
		}
		pch = strtok (NULL, ",");

		if (pch != NULL) {
			printf("\n>>>>>> Entering IO\n");
			kill(fatherPid, SIGUSR1);
			kill(getpid(), SIGSTOP);
		}
	}

	printf("\n>>> Process %d - will terminate\n", getpid());
	kill(fatherPid, SIGCHLD);

    return 0;
}
