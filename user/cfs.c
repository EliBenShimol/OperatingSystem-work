#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    printf("Starting cfs test\n");
    int pid;
    pid = fork();
    if(pid < 0){
    printf("test error: fork failed\n");
      return -1;
    }
    if(pid == 0){
        //child 1
        sleep(7);
        printf("Starting child 1 test\n");
        set_cfs_priority(0);
        for(int i=0;i<1000000;i++){
        if(i%100000==0){
            printf("child 1 %d/100 done\n",i/10000);
            sleep(10);
        }
    }
    char* stats=malloc(sizeof(char)*4);
    get_cfs_stats(getpid(), stats);;
    printf("PID: %d, CFS priority: %d, runtime: %d, sleep time: %d,runnable time: %d\n",
        getpid(),stats[0],stats[1],stats[2],stats[3]);
    free(stats);
    exit(0, "");
    }
    else{
        pid = fork();
        if(pid < 0){
         printf("test error: fork failed\n");
          return -1;
        }
        if(pid == 0){
        //child 2
        sleep(3);
        printf("Starting child 2 test\n");
        for(int i=0;i<1000000;i++){
        if(i%100000==0){
            printf("child 2 %d/100 done\n",i/10000);
            sleep(10);
            }
        }
        char* stats=malloc(sizeof(char)*4);
        get_cfs_stats(getpid(),stats);
        printf("PID: %d, CFS priority: %d, runtime: %d, sleep time: %d,runnable time: %d\n",
        getpid(),stats[0],stats[1],stats[2],stats[3]);
        free(stats);  
        exit(0, "");
        }
        else {
                pid = fork();
                if(pid < 0){
                printf("test error: fork failed\n");
                return -1;
                }
                if(pid == 0){
                //child 3
                sleep(5); 
                printf("Starting child 3 test\n");
                set_cfs_priority(2);
                for(int i=0;i<1000000;i++){
                    if(i%100000==0){
                        printf("child 3 %d/100 done\n",i/10000);
                        sleep(10);
                    }
                } 
                char* stats=malloc(sizeof(char)*4);
                get_cfs_stats(getpid(),stats);
                printf("PID: %d, CFS priority: %d, runtime: %d, sleep time: %d,runnable time: %d\n",
                getpid(),stats[0],stats[1],stats[2],stats[3]);
                free(stats);
                exit(0, "");
                }
                else {
                //perent
                exit(0,"");
                }
            }
        }
    return 0;
}