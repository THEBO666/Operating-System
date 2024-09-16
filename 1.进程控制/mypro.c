#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/// @brief
/// @param
/// @return

int main(void)
{
	pid_t id;
	
	while (1)
	{
		id = fork();
		if (id == 0)
		{
			sleep(5);
			printf("child: pid: %d, ppid: %d\n", getpid(), getppid());
		}
		else
			printf("parent: pid: %d, ppid: %d\n", getpid(), getppid());
	}

	return 0;
}
