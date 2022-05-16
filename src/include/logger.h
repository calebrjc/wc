#pragma once

#include <stdbool.h>
#include <stdio.h>

// Represents the different levels that a message may be logged at.
typedef enum {
    LOGGER_LOGLEVEL_NONE    = 0,
    LOGGER_LOGLEVEL_DEBUG   = 1,
    LOGGER_LOGLEVEL_VERBOSE = 2,
    LOGGER_LOGLEVEL_INFO    = 3,
    LOGGER_LOGLEVEL_ERROR   = 4,
} LogLevel;

// Initializes this logging module to log to `file` at the log level specified by `level`.
//
// No logs will be output from this module until this function is called at least once. Calling
// this function with `file == NULL` is equivalent to calling this function with `file == stdout`.
void logger_init(FILE *fp, LogLevel level);

// Logs the message with at the level specified using printf-style formatting.
void logger_log(LogLevel level, const char *format, ...);

// Equivalent to `logger_log(LOGGER_LOGLEVEL_DEBUG, format, ...)`
#define log_debug(...) logger_log(LOGGER_LOGLEVEL_DEBUG, __VA_ARGS__)

// Equivalent to `logger_log(LOGGER_LOGLEVEL_VERBOSE, format, ...)`
#define log_verbose(...) logger_log(LOGGER_LOGLEVEL_VERBOSE, __VA_ARGS__)

// Equivalent to `logger_log(LOGGER_LOGLEVEL_INFO, format, ...)`
#define log_info(...) logger_log(LOGGER_LOGLEVEL_INFO, __VA_ARGS__)

// Equivalent to `logger_log(LOGGER_LOGLEVEL_ERROR, format, ...)`
#define log_error(...) logger_log(LOGGER_LOGLEVEL_ERROR, __VA_ARGS__)
