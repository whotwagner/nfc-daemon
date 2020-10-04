#ifndef LOG_H 
#define LOG_H

enum log_levels { none = 0, error = 1, warn = 2, info = 3, debug = 4 };

extern enum log_levels loglevel;

int set_loglevel(int level);
void log_error(const char* message, ...);
void log_info(const char* message, ...); 
void log_warn(const char* message, ...); 
void log_debug(const char* message, ...);

#endif
