#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

#include <sys/stat.h>

static void sighandler(int signo){

  if(signo == SIGINT){
    int fd = open("kills.txt", O_CREAT | O_RDWR | O_APPEND, 0664);
    char msg[] = "Exit due to SIGINT\n";
    write(fd, msg, sizeof(msg));
    close(fd);
    printf("Caught a SIGINT\n");
    exit(0);
  }
  else if (signo == SIGUSR1) {
    printf("ppid: %d\n", getppid());
  }
}
// signal(SIGINT,sighandler(SIGINT));

int main(){
  umask(0000);
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);
  
  while(1){
    printf("This program is running\n");
    printf("PID: %d\n",getpid());
    sleep(1);
  }
}

