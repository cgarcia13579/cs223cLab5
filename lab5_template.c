/*
  CPSC 223C
  Spring 2015
  CSU Fullerton

  Lab 5: word frequencies

  Authors: Kevin Wortman (kwortman@csu.fullerton.edu) (REPLACE THIS
  WITH YOUR NAMES AND CSUF EMAIL ADDRESSES)

*/ 

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOT_FOUND -1

/* Safe estimate of the length of the longest English word. */
#define MAX_WORD_LENGTH 200

/* Read the contents of the text file path, count how many times each
   whitespace-separated word appears, then for each distinct word, print one line

   <WORD> <COUNT>

   to standard output, where <WORD> is the non-whitespace characters
   of the word, and <COUNT> is the number of times it appears, which
   must be a positive integer.

   Return true on success, or false on any kind of error. */
bool print_word_frequencies(char* path);

/* Opaque data type for a data structure that tracks the number of
   occurrences of strings. */
struct WordCounts {
  /* TODO: add fields */
};

/* Allocate a new word count object, or return NULL on memory
   error. */
struct WordCounts* word_counts_make();

/* Free a WordCounts object. */
void word_counts_free(struct WordCounts* wc);

/* If word is already in wc, increment its count by 1. If word is not
   present, add it with a count of 1. Return true on success and false
   on memory error. */
bool word_counts_increment(struct WordCounts* wc, char* word);

/* If word is in wc, return its frequency count. If word is not in wc,
   return NOT_FOUND. */
int word_counts_lookup(struct WordCounts* wc, char* word);

/* Print out all the words and counts in wc, using the same format as
   print_word_frequences. */
void word_counts_print(struct WordCounts* wc);

int main(int argc, char** argv) {
  if (argc != 2) {
    fputs("error: you must supply a filename as an argument\n", stderr);
    return 1;
  }

  if (!print_word_frequencies(argv[1]))
    return 1;

  return 0;
}

bool print_word_frequencies(char* path) {
  /* TODO: finish this function definition */

  FILE* f;
  struct WordCounts* wc;
  char str[MAX_WORD_LENGTH + 1];

  f = fopen(path, "r");
  if (f == NULL) {
    fprintf(stderr, "error: could not open '%s'", path);
    return false;
  }

  wc = word_counts_make();
  if (wc == NULL) {
    fprintf(stderr, "error: out of memory");
    fclose(f);
    return false;
  }

  fprintf(stderr, "processing '%s'...", path);

  while ( /* TODO: read one word from f into str using fscanf */ ) {
    if (!word_counts_increment(wc, str)) {
      fprintf(stderr, "\nerror: out of memory");
      fclose(f);
      word_counts_free(wc);
      return false;
    }
  }

  fclose(f);

  fprintf(stderr, "done\n");

  word_counts_print(wc);
  
  word_counts_free(wc);

  return true;
}

struct WordCounts* word_counts_make() {
  struct WordCounts* it = malloc(sizeof(struct WordCounts));
  if (it == NULL)
    return NULL;

  /* TODO: initialize all fields */

  return it;
}

void word_counts_free(struct WordCounts* wc) {
  /* TODO */
}

int word_counts_lookup(struct WordCounts* wc, char* word) {
  /* TODO */
}

bool word_counts_increment(struct WordCounts* wc, char* word) {
  /* TODO */
}

void word_counts_print(struct WordCounts* wc) {
  /* TODO */
}
