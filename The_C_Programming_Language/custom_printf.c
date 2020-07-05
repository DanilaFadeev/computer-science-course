#include <stdarg.h>
#include <math.h>

void custom_printf(char* template, ...) {
  va_list ap;
  va_start(ap, template);

  char* ptr;
  for (ptr = template; *ptr; ptr++) {
    if (*ptr != '%') {
      putchar(*ptr);
      continue;
    }

    ptr++;

    switch (*ptr) {
      case 'd':
        printf("%d", va_arg(ap, int));
        break;
      case 'f':
        printf("%f", va_arg(ap, double));
        break;
      case 'c':
        putchar(va_arg(ap, char));
        break;  
      case 's':
        for (char* p = va_arg(ap, char*); *p; p++)
          putchar(*p);    
      default:
        break;
    }
  }

  va_end(ap);
}

int main(int argc, char* argv[]) {
  custom_printf("Simple number - %d, float pi - %f\n", 999, M_PI);
  custom_printf("Char - %c, string \"%s\"\n", 'B', "Sample string");
}
