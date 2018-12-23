#include <stdio.h>
#include "ft_printf.h"

int main()
{
	// printf("test1 %lu %lu", sizeof(unsigned long), sizeof(size_t));
	int a = 5;
	int *b = &a;
	// ft_printf("%+#10.5hhd %c %s %p", 123, 'A', "Hello World", b);
	ft_printf("%-10c %p %lX\n", 'A', b, 4503599627370495);
	printf("%-10c %p %lX\n", 'A', b, 4503599627370495);
	// printf("% 10c\n", 'A');
	// printf("%#10c\n", 'A');
	// printf("%010c\n", 'A');
	return (0);
}