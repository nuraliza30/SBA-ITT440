#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

int pipes[num_children][2];

void signal_handler(int signum){
	printf ("Received signal%d\n", signum);
	exit(0);
}

void child_process(int id_child, int pipe_read, int pipe_write){
	close(pipes[id_child][1]);

	char messages [50];
	read (pipe_read, messages, sizeof(messages));
	printf ("Child %d received meesage : %s\n", id_child, message);

	kill(getpid(), SIGUSR1);

	exit(0);
}

int main (){
	signal(SIGUSR1), signal_handler);
	
	for (int i = 0; i < num_children; i++){
		if (pipe(pipes[i])== -1){
			perror ("Pipe failed");
			exit (1);
		}
	}

	for (int i=0; i<num_children; i++){
	close(pipes[i][0]);
	}

	char* messages[num_children] = {"Hi there!"};
	for (int i=0; i<num_children; i++){
		write(pipes [i][1], messages[i], strlen(messages[i] + 1);
	}

	for (int i=0; i<num_chlidren; i++){
		wait (NULL);
	}

	printf ("Parent process exiting \n");

	return 0;
}
 


