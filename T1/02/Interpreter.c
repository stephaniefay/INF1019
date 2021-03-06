#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/shm.h>
#include <string.h>

#define BUFFER_SIZE 200
#define NAME_SIZE 20
#define IO_SIZE 200

int main(int argc, char const *argv[]) {
	char programName[NAME_SIZE];
	char io[IO_SIZE];
	char * buffer[BUFFER_SIZE];
	int index = 1;

	printf("Digite o comando 'exec <nome do programa> <fatias de tempo separadas por virgulas>'\n");
	printf("Ao finalizar digite 'fim'\n");

	while(scanf(" exec %s %s", programName, io) == 2){
			 buffer[index] = (char*)malloc(strlen(programName)+1);
			 strcpy(buffer[index], programName);
			 index++;
			 buffer[index] = (char*)malloc(strlen(io)+1);
			 strcpy(buffer[index], io);
			 index++;
	}
	buffer[index] = NULL;
	buffer[0] = "Scheduler";
	execv("./Scheduler", buffer);
	perror("Falha ao iniciar Scheduler\n");

	return 0;
}

