#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

using namespace std;

void motd() {
	cout << "Hello World\n";
	cout << "------------------Starting program----------------------\n";
}

void type_prompt() {
	cout << "shell> ";
}

void read_command(char* command, char** parameters) {
	string input;
	getline(cin, input);
	input = "/bin/" + input;

	char* input_copy = strdup(input.c_str());
	char* token = strtok(input_copy, " ");
	int i = 0;

	while (token != NULL && i < 10 - 1) {
		parameters[i++] = token;
		token = strtok(NULL, " ");
	}

	parameters[i] = NULL;

	if (i > 0) {
		strcpy(command, parameters[0]);
	}
	else {
		command[0] = '\0';
	}

	free(input_copy);
}

void execute_command(char* command, char** parameters) {
	if (strcmp(command, "/bin/cd") == 0) {
		if (parameters[1] == NULL) {
			cerr << "cd: expected arguments\n";
		}
		else if (chdir(parameters[1]) != 0) {
			perror("cd failed");
		}
	}
	else {
		pid_t pid = fork();
		if (pid == 0) {
			execvp(command, parameters);
			perror("execvp failed");
			exit(1);
		}
		else if (pid > 0) {
			int status;
			wait(&status);
		}
		else {
			perror("fork failed");
        	}
	}
}

int main() {
	motd();

	char command[256];
	char* parameters[10];

	while (true) {
		type_prompt();

		read_command(command, parameters);

		if (strcmp(command, "/bin/exit") == 0) {
			break;
		}

		execute_command(command, parameters);
	}

	cout << "------------------------End Program---------------------\n";
	return 0;
}
