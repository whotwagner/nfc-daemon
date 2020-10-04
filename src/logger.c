#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "logger.h"

extern enum log_levels loglevel;

int set_loglevel(int level)
{
	switch(level)
	{
		case none:
			loglevel = none;
			break;
		case warn:
			loglevel = warn;
			break;
		case info:
			loglevel = info;
			break;
		case error:
			loglevel = error;
			break;
		case debug:
			loglevel = debug;
			break;
		default:
			return -1;
			break;
	}

	return 0;
}

void log_format(const char* tag, const char* message, va_list args) 
{   
	time_t now;
	time(&now);     
	char * date =ctime(&now);   
	date[strlen(date) - 1] = '\0';  
	fprintf(stderr,"%s [%s] ", date, tag);
	vfprintf(stderr,message, args);     
	fprintf(stderr,"\n");
}

void log_error(const char* message, ...) 
{  
	va_list args;   
	if(loglevel >= error)
	{
		va_start(args, message);    
		log_format("error", message, args);     
		va_end(args); 
	}
}

void log_warn(const char* message, ...) 
{  
	va_list args;   
	if(loglevel >= warn)
	{
		va_start(args, message);    
		log_format("warn", message, args);     
		va_end(args); 
	}
}

void log_info(const char* message, ...) 
{   
	va_list args;   
	if(loglevel >= info)
	{
		va_start(args, message);    
		log_format("info", message, args);  
		va_end(args); 
	}
}

void log_debug(const char* message, ...) 
{  
	va_list args;   
	if(loglevel == debug)
	{
		va_start(args, message);    
		log_format("debug", message, args);     
		va_end(args); 
	}
}

