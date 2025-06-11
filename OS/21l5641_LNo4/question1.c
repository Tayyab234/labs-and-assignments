#include <stdio.h>
#include<sys/wait.h>
#include<unistd.h>
int main(){
pid_t pid=fork();
if(pid==0){
char* args[] ={"./hello.o",NULL};
execv(args[0],args);

}
else{
wait(NULL);
printf("\nProgram Completed\n");
}

return 0;
}
