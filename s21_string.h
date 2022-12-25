//
// Created by Oznak Banshee on 11/27/22.
//

#ifndef STRING_S21_STRING_H
#define STRING_S21_STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <math.h>
#include <ctype.h>

#define s21_size_t unsigned long long
#define s21_NULL (void*)
#define s21_buf_size 1000

typedef struct format_token {
    int minus;
    int plus;
    int space;
    int zero;
    int hash;
    int width;
    int prec;
    char length;
    char spec;
}format_token;

int s21_sprintf(char *str, const char *format, ...);
void init_format_token(format_token *tok);
char* parse_length(char *f, format_token *tok);
char* parse_flag(char *f, format_token *tok);
char* parse_prec(char *f, format_token *tok, va_list args);
char* parse_width(char *f, format_token *tok, va_list args);
void parse_spec(char **f, format_token *tok);

#endif //STRING_S21_STRING_H
