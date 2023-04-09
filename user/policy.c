#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
int main(int argc, char *argv[])
{
    ///debug
    // int* stats=malloc(sizeof(int)*4);
    // stats[0]=0; stats[1]=1; stats[2]=2; stats[3]=3;
    // set_cfs_priority(1);
    // get_cfs_stats(getpid(),&stats[0],&stats[1],&stats[2],stats[3]);
    // printf("PID: %d, CFS priority: %d, runtime: %d, sleep time: %d,runnable time: %d",
    // getpid(),stats[0],stats[1],stats[2],stats[3]);
    // free(stats);

   // printf("debug----------id: %d\n",*argv[1]-'0');
    int ok=set_policy(*argv[1]-'0');
    if(ok==0){
        int id=*argv[1]-'0';
        if(id==0){
            printf("policy changed to RR\n"); 
        }
        if(id==1){
            printf("policy changed to PS\n"); 
        }
        if(id==2){
            printf("policy changed to CFS\n"); 
        }
        
        return -1;
    }
    printf("policy change failed, return num: %d\n",ok);
    return 0;
}