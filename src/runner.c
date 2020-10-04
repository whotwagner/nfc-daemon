#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include "logger.h"

pid_t run_script(const char *runscript, const char *uid)
{
	pid_t child;
	log_info("Executing %s with UID: %s", runscript, uid);
	child = fork();
	if(child == 0)
	{
		log_debug("child process id: %d" , getpid());
		if( execl(runscript,runscript,uid,NULL) < 0)
		{
			log_error("Could not execute script: %s", strerror(errno));
			exit(EXIT_FAILURE);
		}
	}
	if(child == -1)
	{
		log_error("Failed to create a sub-process");
	}
	if(child > 0)
	{
		log_debug("I am the parent. Stuff get serious here");
	}

	return child;	
}

pid_t end_script(const char *runscript)
{
	pid_t child;
	log_info("Executing %s", runscript);
	child = fork();
	if(child == 0)
	{
		log_debug("child process id: %d" , getpid());
		if( execl(runscript,runscript,NULL) < 0)
		{
			log_error("Could not execute script: %s", strerror(errno));
			exit(EXIT_FAILURE);
		}
	}
	if(child == -1)
	{
		log_error("Failed to create a sub-process");
	}
	if(child > 0)
	{
		log_debug("I am the parent. Stuff get serious here");
		/* 
		   wait for the child to exit.
		   we only accept new figures after
		   the end-script has finished.
		*/
		wait(NULL); 
	}

	return child;	
}
