#include <sys/types.h>
#include <unistd.h>
#include<stdlib.h>

#include<stdio.h>

	int main()
	{
		pid_t t;
		
		char Wbuff[22]="hello";
		char Rbuff[128];
		int fpipe;
		int pfd[1];
		fpipe=pipe(pfd);
		t=fork();
		
			
	//	fpipe=pipe(pfd);
		if(t==0)
		{
			write(pfd[1],"hello\n",6);
			close(pfd[1]);
			printf("i am child\n");
		
		}
		else if(t>0)
		{
			read(pfd[0],Rbuff,12);
		  printf("i am parent\n  %s\n",Rbuff);
		  close(pfd[0]);
		
		}
	

	return 0;
	}



