#include "logger.h"

#include <stdarg.h>

// The file that is being logged to
static FILE *log_file = NULL;

// The current log level
static LogLevel current_level = LOGGER_LOGLEVEL_NONE;

// Message headers
char *LOG_HEADERS[] = {
    "",            // LogLevel.LOGGER_LOGLEVEL_NONE
    "[DEBUG] ",    // LogLevel.LOGGER_LOGLEVEL_DEBUG
    "[VERBOSE] ",  // LogLevel.LOGGER_LOGLEVEL_VERBOSE
    "[INFO] ",     // LogLevel.LOGGER_LOGLEVEL_INFO
    "[ERROR] ",    // LogLevel.LOGGER_LOGLEVEL_ERROR
};

void logger_init(FILE *file, LogLevel level) {
    log_file      = file;
    current_level = level;
}

void logger_log(LogLevel level, const char *format, ...) {
    if (level < current_level || current_level == LOGGER_LOGLEVEL_NONE) return;

    FILE *fp = (log_file != NULL) ? log_file : stdout;

    fprintf(fp, "%s", LOG_HEADERS[level]);

    va_list args;
    va_start(args, format);
    vfprintf(fp, format, args);
    va_end(args);
}
