#include "shell.h"


int execute_args(char **args)
{
	pid_t pid;
	int status;
	char *builtin_func_list[] = {
		"cd",
		"exit",
	};
	int (*builtin_func[])(char **) = {
		// you should add something here
		&own_cd,
		&own_exit,
	};

	long unsigned int i = 0;
	for (; i < sizeof(builtin_func_list) / sizeof(char *); i++)
	{
		/* if there is a match execute the builtin command */
		if (strcmp(args[0], builtin_func_list[i]) == 0)
		{
			return ((*builtin_func[i])(args));
		}
	}
	pid = fork();
	if(pid == 0 ){
		if(execvp(args[0],args) == -1){
			perror("execvp failed");
		}
		exit(EXIT_FAILURE);
	}
	else if(pid < 0){
		perror("Error fork");
	}
	else{
		do
		{
			waitpid(pid, &status,WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		
	}

	return (-1); // this status code means everything is ok
}