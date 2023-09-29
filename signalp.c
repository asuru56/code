#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<sys/wait.h>
#include<signal.h>

int main(int argc, char*argv[]){
    int pid = fork(); 
    if(pid == -1){
        return 1;
    }

    if(pid == 0){
        while(1){
            //execl("q1","q1",NULL);
            //execl("q2","q2",NULL);
            execl("q3","q3",NULL);
            printf("Some text goes here %d \n" , pid );
            usleep(500000); 
        }
    } else {
        sleep(1);
        kill(pid,SIGKILL);
        wait(NULL); 
    }
}