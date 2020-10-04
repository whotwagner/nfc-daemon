#ifndef RUNNER_H 
#define RUNNER_H

#include <sys/types.h>

pid_t run_script(const char *runscript, const char *uid);
pid_t end_script(const char *runscript);

#endif
