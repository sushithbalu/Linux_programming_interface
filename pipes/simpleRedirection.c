#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>

void errxt(char *);

int main()
{
	int fd, fdw;
	fdw = open("new", O_WRONLY|O_CREAT|O_TRUNC, 0644);
	fd = fork();
	if(fd == -1)
		errxt("fork");
	if(fd == 0){
		close(1);
		dup(fdw);
		execlp("ls", "ls", NULL);
		printf("hello");
	}
	return 0;		
}
void errxt(char *err)
{
	perror(err);
	exit(EXIT_FAILURE);
}
