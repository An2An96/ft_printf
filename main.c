#include <stdio.h>
#include "ft_printf.h"

int main()
{
	// printf("test1 %lu %lu", sizeof(unsigned long), sizeof(size_t));
	int a = 5;
	int *b = &a;
	// ft_printf("%+#10.5hhd %c %s %p", 123, 'A', "Hello World", b);
	ft_printf("%% %ld %i %o %u %x %X %s %c %p\n", -2147483648, 2147483647, 45035996, -2147483644, 1024, 2048, "Hello", 'A', b);
	printf("%% %ld %i %o %u %x %X %s %c %p\n", -2147483648, 2147483647, 45035996, -2147483644, 1024, 2048, "Hello", 'A', b);
	// printf("% 10c\n", 'A');
	// printf("%#10c\n", 'A');
	// printf("%010c\n", 'A');
	return (0);
}