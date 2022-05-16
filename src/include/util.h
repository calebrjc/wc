#ifndef WC_UTIL_H_
#define WC_UTIL_H_

#include <time.h>

#include "wc_core.h"

// Prints the stats associated with the inputted WordCountResult and elapsed time
void print_stats(const WordCountResult result, const double elapsed_sec);

// Prints the error message associated with `errno` with the specified header and exits the program
//
// See: `man perror`
void perror_and_exit(const char *message);

// Returns the size of the file referenced by `file_name`
long get_file_size(const char *file_name);

// Returns the elapsed time (in seconds) between `begin` and `end`
double get_elapsed_time(const struct timespec begin, const struct timespec end);

// Returns the clamped value for the inputted integer given the minimum and maximum values for its
// range
int clamp(int value, int min, int max);

#endif  // WC_UTIL_H_
