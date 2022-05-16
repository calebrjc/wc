#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "logger.h"
#include "util.h"

// Entry point for the wc_single program
int main(int argc, char **argv) {
    // Argument validation
    if (argc < 2 || 3 < argc) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 0;
    }

    for (int i = 0; i < argc; i++) {
        if (strncmp(argv[i], "-v", strlen(argv[i]))) {
            logger_init(NULL, LOGGER_LOGLEVEL_DEBUG);
            break;
        }
    }

    // Begin runtime measurement
    struct timespec begin, end;
    clock_gettime(CLOCK_REALTIME, &begin);

    long file_size = get_file_size(argv[1]);
    if (file_size < 0) {
        printf("Error getting file size. Does the file exist?\n");
        exit(EXIT_FAILURE);
    }

    // Do the word count
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror_and_exit("Could not open the file");
    }

    WordCountResult result = do_word_count(file, 0, file_size);
    fclose(file);

    // End runtime measurement
    clock_gettime(CLOCK_REALTIME, &end);
    double elapsed_sec = get_elapsed_time(begin, end);

    print_stats(result, elapsed_sec);

    return EXIT_SUCCESS;
}
