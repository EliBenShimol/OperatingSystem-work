#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]){
    int a = memsize();
    printf("before malloc: %d\n", a);
    char* arr = (char*)malloc(20000);
    a = memsize();
    printf("after malloc: %d\n", a);
    free(arr);
    a = memsize();
    printf("after release: %d\n", a);
    return 0;
}