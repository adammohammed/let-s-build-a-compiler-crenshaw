#ifndef __CRADLE_H
#define __CRADLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const char TAB = '\t';

char look;

void compiler_get_char() {
  look = getchar();
}

void compiler_output(FILE *fd, char * s) {
  fprintf(fd, "%s", s);
}

void compiler_error(char * err) {
  size_t size = strlen(err) + 9; // 'ERROR: ' = 7 + 1 '\n' + 1 '\0'
  char p[1024];

  if (size > 1024) {
    size = 1024;
  }

  snprintf(p, size, "ERROR: %s\n", err);
  compiler_output(stderr, p);
}

void compiler_abort(char* err){
  compiler_error(err);
  exit(EXIT_FAILURE);
}

void compiler_expected(char* s) {
  size_t size = strlen(s) + 10; // ' Expected' = 9 + 1 for '\0'
  char p[1024];

  if (size >= 1024) {
    size = 1023;
  }

  snprintf(p, size, "%s Expected", s);

  compiler_abort(p);
}

void match(char x) {
  if (look == x) {
    compiler_get_char();
    return;
  }

  char result[512];
  snprintf(result, 511, "'%c'", x);
  compiler_expected(result);
}

int is_alpha(char x) {
  return isalpha(x);
}

int is_digit(char x) {
  return isdigit(x);
}

char compiler_get_name() {
  if (!is_alpha(look)) {
    compiler_expected("name");
    return 0;
  }

  char l = look;
  compiler_get_char();
  return toupper(l);
}


char compiler_get_num() {
  if (!is_digit(look)) {
    compiler_expected("Integer");
    return 0;
  }

  char l = look;
  compiler_get_char();
  return l;
}

void compiler_emit(char* s) {
  size_t s_len = strlen(s) + 2; // TAB + \0
  char out[s_len];

  snprintf(out, s_len, "%c%s", TAB, s);

  compiler_output(stdout, out);
}

void compiler_emit_ln(char* s) {
  compiler_emit(s);
  compiler_emit("\n");
}

void compiler_init() {
  compiler_get_char();
}

#endif // __CRADLE_H
