#include <stdio.h>
#include <stdlib.h>
#include <lib.h>

#include <sys/types.h>
#include <unistd.h>
#include <minix/type.h>
#include <time.h>

int main(int argc, char *argv[])
{
	int i,j;
	int reslt = 0;
	time_t start, end, elapsed_time;
	message m;
	pid_t pid = getpid();
	
	int group = argc > 1 ? atoi(argv[1]) : -1;
	int newtime = argc > 2 ? atoi(argv[2]) : -1;

	if(group >= 0 && group <=2) /*it must be A(0),B(1) or C(2)*/
	{
	   m.m1_i1 = pid;
	   m.m1_i2 = group;
	   printf("Testing the function for the process with pid %d that changes a group...\n", pid);
	   _syscall(MM, USR_CHANGEGR, &m);
	   if(newtime > 0)
	   {
	  	m.m1_i1 = group;
	  	m.m1_i2 = newtime;
	  	printf("Testing the function for the process with pid %d that changes quantum...\n", pid);
	  	_syscall(MM, USR_CHANGEQUA, &m);
	   }
	   else
	  {
	  	m.m1_i1 = reslt;
	  	m.m1_i2 = group;
	  	printf("Testing the function for the process with pid %d that gets quantum...\n", pid);
	  	reslt = _syscall(MM, USR_GETQUA, &m);
	  }
	}
	else
	{
	  m.m1_i1 = pid;
	  printf("Testing the function for the process with pid %d that gets a group...\n", pid);
	  reslt = _syscall(MM, USR_GETGR, &m);
	}

	start = time(NULL);
	for (i = 0; i< 9000; ++i) 
	{
		for (j=0; j<4000; ++j) {}
	}

	end = time(NULL);

	elapsed_time = end - start;
	printf("ended: %d, Elapsed time: %d\n", group, elapsed_time);

	while(1){} /*endless loop*/
	return 0;
}

   
 

