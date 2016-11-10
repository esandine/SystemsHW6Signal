#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
static void sighandler(int signo){
  printf("Signal Caught");
}
// signal(SIGINT,sighandler(SIGINT));

int main(){
  while(1){
    printf("This program is running\n");
    printf("PID: %d\n",getpid());
    sleep(1);
    signal(SIGINT,sighandler(SIGINT));
  }
}

