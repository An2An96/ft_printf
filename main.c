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

	// if (ft_printf("%#x %#llX\n", 42, 9223372036854775807) == printf("%#x %#llX\n", 42, 9223372036854775807))
	// {
	// 	ft_putstr("return error");
	// }


	ft_printf("%#O", 1);
	printf("%#O", 1)

	return (0);
}