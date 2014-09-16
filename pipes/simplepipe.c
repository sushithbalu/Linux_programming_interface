#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>

void errxt(char *);

int main()
{
	int fd, p[2];

	if(pipe(p) == -1) /* pipe():allocates fd 3 and 4 for pipe */
		errxt("pipe");
	fd = fork();
	if(fd == -1)
		errxt("fork");
	if(fd == 0){
		close(1); /*close normal stdout*/
		dup(p[1]); /*dup stdout, p[1]*/
		close(p[0]); /*no need of p[0] here*/
		execlp("ls", "ls", NULL);
	} else {
		close(0); /*close normal stdin*/
		dup(p[0]); /*dup stdin, p[0]*/
		close(p[1]); /*no need of p[1] here*/
		execlp("wc", "wc", "-l", NULL);
	}
	return 0;
}

void errxt(char *err)
{
	perror(err);
	exit(EXIT_FAILURE);
}
