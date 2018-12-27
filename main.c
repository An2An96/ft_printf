#include <stdio.h>
#include <float.h>
#include "ft_printf.h"

int main()
{
	// printf("test1 %lu %lu", sizeof(unsigned long), sizeof(size_t));
	// int a = 5;
	// int *b = &a;
	// ft_printf("%+#10.5hhd %c %s %p", 123, 'A', "Hello World", b);
	// ft_printf("%% %ld %i %o %u %#x %#X %s %-10c %p\n", -2147483648, 2147483647, 45035996, -2147483644, 1024, 2048, "Hello", 'A', b);
	// printf("%% %ld %i %o %u %#x %#X %s %-10c %p\n", -2147483648, 2147483647, 45035996, -2147483644, 1024, 2048, "Hello", 'A', b);

	// ft_printf("%u\n", -9223372036854775808);
	// printf("%u\n", -9223372036854775808);

	// if (ft_printf("%#x %#llX\n", 42, 9223372036854775807) == printf("%#x %#llX\n", 42, 9223372036854775807))
	// {
	// 	ft_putstr("return error");
	// }

	// printf("%f %lu", DBL_MAX, sizeof(double));

	// ft_printf("{%}");
	// printf("{%105}\n");
	// ft_printf("%#.25llx|\n", 9223372036854775807);
	// printf("%.10ll#.25x\n%.25ll#.10x|\n", 9223372036854775807, 9223372036854775807);

	// ft_printf("%030.20lld\n", 9223372036854775807);

	int a;
	int b;

	// for(int i = 0; i < 30; i++)
	// 	printf("%c\n", i);

	// b = ft_printf("ft_printf: %0100llb %n Hello Man\n", 9223372036854775807, &a);
	// printf("%d %d", a, b);
	ft_printf("ft_printf: %030llb\n", -92233720);
	printf("printf:    %#030llb\n", 9223372036854775807);

	//printf("%c[1;33mHello, world!\n", 27);
	// ft_printf("{%f}{%F}\n", -1444565444646.6465424242242454654, -1444565444646.6465424242242454654);
	// printf("{%f}{%F}\n", -1444565444646.6465424242242454654, -1444565444646.6465424242242454654);

	return (0);
}