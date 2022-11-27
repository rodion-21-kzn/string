
#include "s21_string.h"

int main() {
    char buf[200];
    int x = 2;
    sprintf(buf, "%100d", x);
    printf("%s", buf);
    return 0;
}

int s21_sprintf(char *str, const char *format, ...) {
    va_list(ap);
    va_start(ap, format);





    va_end(ap);
}
