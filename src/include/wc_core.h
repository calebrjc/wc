#ifndef WC_WCCORE_H_
#define WC_WCCORE_H_

#include <stdio.h>

// Defines the structure of the data returned from `do_word_count(...)`.
typedef struct {
    // The number of characters counted
    size_t char_count;

    // The number of words counted
    size_t word_count;

    // The number of lines counted
    size_t line_count;
} WordCountResult;

// Returns the result of a "word count" operation on the given file, at the given offset, over
// `num_bytes` bytes.
//
// This function will return its current count if the end-of-file is reached before `num_bytes`
// bytes are processed.
//
// This function will exit the program if an error occurs after a system call.
WordCountResult do_word_count(FILE *file, long offset, long num_bytes);

// Sets the simulated crash rate of the `do_word_count(...)` function.
//
// `rate` should be a positive integer between 0 and 80.
void set_crash_rate(unsigned int rate);

// Returns the simulated crash rate of the `do_word_count(...)` function.
//
// Defaults to 0 if not set by a call to `set_crash_rate(...)`.
unsigned int get_crash_rate();

#endif  // WC_WCCORE_H_
