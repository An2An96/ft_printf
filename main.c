#include <stdio.h>
#include "ft_printf.h"

int main()
{
	// printf("test1 %lu %lu", sizeof(unsigned long), sizeof(size_t));
	int a = 5;
	int *b = &a;
	// ft_printf("%+#10.5hhd %c %s %p", 123, 'A', "Hello World", b);
	// ft_printf("%% %ld %i %o %u %#x %#X %s %-10c %p\n", -2147483648, 2147483647, 45035996, -2147483644, 1024, 2048, "Hello", 'A', b);
	// printf("%% %ld %i %o %u %#x %#X %s %-10c %p\n", -2147483648, 2147483647, 45035996, -2147483644, 1024, 2048, "Hello", 'A', b);

	// ft_printf("%u\n", -9223372036854775808);
	// printf("%u\n", -9223372036854775808);


	if (ft_printf("%#x %#llX\n", 42, 9223372036854775807) == printf("%#x %#llX\n", 42, 9223372036854775807))
	{
		ft_putstr("return error\n");
	}

	ft_printf("%10s world!\n", "Hello");
	printf("%10s world!\n", "Hello");

	// ft_printf("%d\n", 9123372036854775807);
	// printf("%d\n", 9123372036854775807);

	ft_printf("1: %+5.10Lx %X\n", 1024, 2048);
	printf("2: %+5.10Lx %X\n", 1024, 2048);
	ft_printf("%ld\n", -2147483648);
	ft_printf("%i\n", 2147483647);
	ft_printf("%o\n", 45035996);

	ft_printf("%s\n", "Hello");

	ft_printf("ft_printf: %c\n", 'A');
	printf("printf: %c\n", 'A');

	ft_printf("3 %-20Lf-\n", (long double)1024.2048);
	printf("4 %-20Lf-\n", (long double)1024.2048);
	// printf("% 10c\n", 'A');
	// printf("%#10c\n", 'A');
	// printf("%010c\n", 'A');
	return (0);
}