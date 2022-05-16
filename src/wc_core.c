#include "wc_core.h"

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#include "logger.h"
#include "util.h"

// The simulated crash rate for the `do_word_count(...) function`
static unsigned int crash_rate = 0;

WordCountResult do_word_count(FILE *file, long offset, long num_bytes) {
    pid_t pid = getpid();

    // Initialize the result struct
    WordCountResult result;
    result.char_count = 0;
    result.word_count = 0;
    result.line_count = 0;

    log_debug("Process %d - Reading %ld bytes from offset %ld\n", pid, num_bytes, offset);

    // Seek to the inputted offset
    if (fseek(file, offset, SEEK_SET) != 0) {
        perror_and_exit("fseek error");
    }

    // Should we simulate a crash?
    srand(pid);
    if (crash_rate > 0 && (rand() % 100) < crash_rate) {
        log_debug("Process %d crashed.", pid);
        abort();
    }

    // Do the word count
    char c;
    long bytes_read = 0;
    while ((c = fgetc(file)) != EOF && bytes_read <= num_bytes) {
        bool is_space   = c == ' ';
        bool is_newline = c == '\n';

        if (!is_space && !is_newline) result.char_count++;
        if (is_space || is_newline) result.word_count++;
        if (is_newline) result.line_count++;

        bytes_read++;
    }

    return result;
}

void set_crash_rate(unsigned int rate) { crash_rate = clamp(rate, 0, 80); }

unsigned int get_crash_rate() { return crash_rate; }
