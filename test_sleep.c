#include <stdio.h>
#include <unistd.h> 

int main(){
    int i = 0;
    printf("%d", i);
    while(1){
        printf("%d", i);
        i++;
        sleep(1);
    }
    return 0;
}