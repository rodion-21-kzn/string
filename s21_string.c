
#include "s21_string.h"

void print_token(format_token tok) {
    printf("minus %d\n", tok.minus);
    printf("plus %d\n", tok.plus);
    printf("space %d\n", tok.space);
    printf("zero %d\n", tok.zero);
    printf("hash %d\n", tok.hash);
    printf("length %c\n", tok.length);
    printf("spec %c\n", tok.spec);
    printf("prec %d\n", tok.prec);
    printf("width %d\n", tok.width);
}

int main() {
    char buf[100];
    int x = 2;
    s21_sprintf(buf, "AbaG%+012d", x);
    printf("%s\n", buf);
    return 0;
}
// -0 не работаю вместе. Пробел и + не работают.

// %[flags][width][.precision][length]specifier
// flags (space, -, +, #, 0)
// width ((number), *)
// .precision (.number, .*)
//https://www.tutorialspoint.com/c_standard_library/c_function_sprintf.htm

int s21_sprintf(char *str, const char *format, ...) {
    int err = 0;
    format_token tok;
    char *f = (char *)format;
    init_format_token(&tok);
    if (format == NULL || *format == '\0') {  // в настоящем вроде сега
        err = -1;
    } else {
        va_list(ap);
        va_start(ap, format);
        for (;*f; f++) {
            if (*f != '%') { // если не процент, то сразу кидаем в массив
                *str = *f;
                str++;
                *str = '\0';
            } else if (*f == '%') {
                f++;
                f = parse_flag(f, &tok);
                f = parse_width(f, &tok, ap);
            } else {
                return err;
            }
        }
        va_end(ap);
    }
    print_token(tok);
    return err;
}

char* parse_width(char *f, format_token *tok, va_list ap) {
    if (isdigit(*f)) {
        char temp_buf[s21_buf_size];
        int i = 0;
        while (isdigit(*f)) {
            temp_buf[i] = *f;
            i++;
            temp_buf[i] = '\0';
            f++;
        }
        tok->width = atoi(temp_buf);
    } else if (*f == '*') {
        tok->width = va_arg(ap, int);
        f++;
    }
    return f;
}

char* parse_flag(char *f, format_token *tok) {
    while (*f == ' ' || *f == '+' || *f == '-' || *f == '0' || *f == '#') {
        if (*f == ' ') tok->space = 1;
        if (*f == '+') tok->plus = 1;
        if (*f == '-') tok->minus = 1;
        if (*f == '0') tok->zero = 1;
        if (*f == '#') tok->hash = 1;
        f++;
    }
    return f;
}

void init_format_token(format_token *tok) {
    tok->minus = 0;
    tok->plus = 0;
    tok->space = 0;
    tok->zero = 0;
    tok->hash = 0;
    tok->length = 'n';
    tok->spec = 'n';
    tok->prec = -1;
    tok->width = -1;
}
