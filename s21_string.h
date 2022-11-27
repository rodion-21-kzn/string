//
// Created by Oznak Banshee on 11/27/22.
//

#ifndef STRING_S21_STRING_H
#define STRING_S21_STRING_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define s21_size_t unsigned long long
#define s21_NULL (void*)0


int s21_sprintf(char *str, const char *format, ...);

#endif //STRING_S21_STRING_H
