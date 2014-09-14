#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>

int main()
{
	int p[2];
	char array[20] = "";

	if(pipe(p) == -1){
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	
	printf("writing to fd-%d\n", p[1]);
	write(p[1], "ken thomson", 12);
	printf("reading from fd-%d\n", p[0]);
	read(p[0], array, 12);
	printf("read \"%s\"\n", array);
	return 0;
}
