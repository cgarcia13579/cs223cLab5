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
  int maxCount;
  int count;
  int *keys;
  char **words;
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
    fputs("USAGE: ./a.out <filePath>\n", stderr);
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

  fprintf(stderr, "processing '%s'...\n", path);

  char endFile;
  int num = 0;

  /* TODO: read one word from f into str using fscanf */
  while (  fscanf(f,"%s",str) != EOF ) {
 
    //printf("%s\n",str);
    if(wc->maxCount < num){
      wc->maxCount += 10; 
    }
    if (!word_counts_increment(wc, str)) {
      fprintf(stderr, "\nerror: out of memory");
      fclose(f);
      word_counts_free(wc);
      return false;
    }
    num++;
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

  it->maxCount = MAX_WORD_LENGTH;
  it->count = 0;
  it->keys = calloc(it->maxCount, sizeof(int));
  it->words = (char **)malloc(it->maxCount * sizeof(char *));

  for(int i = 0; i < it->maxCount; i++){
    *(it->keys + i) = 0;
    *(it->words + i) = "[   ]";
    
  }
  
  return it;
}

void word_counts_free(struct WordCounts* wc) {

  free(wc);
  
  /* TODO */
}

int word_counts_lookup(struct WordCounts* wc, char* word) {
   //printf("%d\n", wc->count);
  
  int returnValue = -2;

  for(int i = 0; i < wc->count; i++){
      
      //printf("%d :: %s :: %s!!!\n",i, *(wc->words+i), word);
      if(strcmp(*(wc->words+i),word) == 0){
      returnValue = *(wc->keys+i);
       // printf("BREAK!\n");
        break;
      }     
    }

  if(returnValue < 0){
    returnValue = NOT_FOUND;
   // printf("Not found!\n");
  }

  //printf("done!\n");
  return returnValue;
  /* TODO */
}

bool word_counts_increment(struct WordCounts* wc, char* word) {
  
  bool returnValue = false;

    int freq =  word_counts_lookup(wc, word);
   // printf("%d\n", pos);
    if(freq == -1){
      char* newWord = strdup(word);
      *(wc->words +  wc->count) = newWord;
      *(wc->keys +  wc->count)  += 1;
      wc->count += 1;
      //printf("DIFF!\n\n");
        returnValue = true;
    }
    else if(freq != -1){
      for(int i = 0; i < wc->count; i++){
      //printf("%d :: %s :: %s!!!\n",i, *(wc->words+i), word);
        if(strcmp(*(wc->words+i),word) == 0){
          *(wc->keys+ i) += 1;
          //returnValue = true;
       // printf("BREAK!\n");
        break;
      }     
    }
      //*(wc->keys+ pos) += 1;
      returnValue = true;
     //printf("SAME!\n\n");
    }

    //returnValue = true;

  
 
  return returnValue;
  /* TODO */
}

void word_counts_print(struct WordCounts* wc) {
  /* TODO */
  
  for(int i = 0; i < wc->count; i++){
     printf("%s %d\n", *(wc->words+i), *(wc->keys+i));
  }
}
