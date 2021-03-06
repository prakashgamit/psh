#include "builtin.h"


char *builtin_commands[NUM_BUILTIN_COMMANDS] =
    {   "cd",
        "history",
        "exit"
    };


int is_builtin(char *command)
{
    int i;
    for(i = 0; i < NUM_BUILTIN_COMMANDS; i++){
        if(!strcmp(command, builtin_commands[i]))
            return i;
    }
    // not a builtin command
    return -1;
}


void execute_builtin(char *command, char **argv)
{
    if(!strcmp(command, "cd")){
        // cd to argv[1] directory
        if(argv[1] != NULL && chdir(argv[1]) < 0){
            fprintf(stderr, "%s : path not found! :(\n", argv[1]);
        }
    }else if(!strcmp(command, "exit")){
        exit(EXIT_SUCCESS);
    }else{
        fprintf(stderr, "%s : command not found! :(\n", command);
    }
}
