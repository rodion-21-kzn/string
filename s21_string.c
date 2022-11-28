
#include "s21_string.h"

int main() {
    char buf[10];
    char *huk = NULL;
    int i = s21_sprintf(buf, "Hello");
    printf("error - %d\n", i);
    printf("string - %s\n", buf);
    return 0;
}

// %[flags][width][.precision][length]specifier
// flags (space, -, +, #, 0)
// width ((number), *)
// .precision (.number, .*)
//https://www.tutorialspoint.com/c_standard_library/c_function_sprintf.htm

int s21_sprintf(char *str, const char *format, ...) {
    int err = 0;
    if (format == NULL || *format == '\0') {  // в настоящем вроде сега
        err = -1;
    } else {
        va_list(ap);
        va_start(ap, format);
        for (;*format; format++) {
            if (*format != '%') { // если не процент, то сразу кидаем в массив
                *str = *format;
                str++;
            } else {
                return err;
            }
        }
        va_end(ap);
    }
    return err;
}
