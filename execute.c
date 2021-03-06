#include "execute.h"
#include "builtin.h"


void execute(char **argv, const int bg)
{
    char *command = argv[0];

    //check if its a builtin command
    //no need to fork & exec if builtin command
    if(is_builtin(command) != -1){
        execute_builtin(command, argv);
        return;
    }

    //fork a child process
    int child_pid;
    if((child_pid = fork()) < 0){
        perror("fork");

    }else if(child_pid == 0){
        //child process = exec command
        if(execvp(command, argv) == -1){
            fprintf(stderr, "%s : command not found! :(\n", command);
            exit(EXIT_FAILURE);
        }

    }else{
        //parent process
        //wait for child if bg = 0 else continue

        if(!bg){
            //return status of child
            int status;

            //pid of the child which terminated
            //it may not be always child_pid if some process was
            //running in the background
            int ret_pid;

            //wait for child to terminate
            ret_pid = wait(&status);
            //do something with @status and @ret_pid
        }
    }
}
