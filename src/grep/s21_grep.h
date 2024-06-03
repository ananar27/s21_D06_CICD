#ifndef S21_GREP_H
#define S21_GREP_H
#define _GNU_SOURCE
#define MAX_SIZE 2000
#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct flags {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
} flags;

typedef struct variables {
  int str_counter;
  int total_files;
  int patterns_cnt;
  int files_cnt;
  int index;
  int str_number;
  int regex_error;
  char reg_pattern[MAX_SIZE];
} Variables;

int parsing_args(int argc, char *argv[], flags *flags, char *patterns[],
                 char *files[], Variables *vars);
void first_pattern(Variables *vars, char *patterns[], int cnt);
int check_files(Variables *vars, char *files[]);
void reading_from_file(int argc, char *argv[], flags flags, Variables *vars,
                       char *patterns[], char *files[]);
void file_parcing(char *argv[], FILE *file, flags flags, char pattern[],
                  Variables *vars);
void printing_data(char *argv[], int match, flags flags, char str[],
                   int str_number, Variables *vars, int *stop);
void closing_file(FILE *file);
void usage();
#endif
