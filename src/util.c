#include "util.h"

#include <stdlib.h>
#include <sys/stat.h>

void print_stats(const WordCountResult result, const double elapsed_sec) {
    printf("Total chars: %ld\n", result.char_count);
    printf("Total words: %ld\n", result.word_count);
    printf("Total lines: %ld\n", result.line_count);
    printf("Runtime: %0.3f seconds\n", elapsed_sec);
}

void perror_and_exit(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

long get_file_size(const char *file_name) {
    // Get the file's size
    struct stat file_status;
    if (stat(file_name, &file_status) < 0) {
        return -1;
    }
    long file_size = file_status.st_size;

    return file_size;
}

double get_elapsed_time(const struct timespec begin, const struct timespec end) {
    long seconds     = end.tv_sec - begin.tv_sec;
    long nanoseconds = end.tv_nsec - begin.tv_nsec;

    return seconds + nanoseconds * 1e-9;
}

int clamp(int value, int min, int max) {
    const int x = (value < min) ? min : value;
    return (x > max) ? max : x;
}
