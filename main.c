#include <stdio.h>
#include <float.h>
#include <limits.h>
#include "ft_printf.h"
#include <wchar.h>

int main()
{
	// printf("test1 %lu %lu", sizeof(unsigned long), sizeof(size_t));
	int a , c;
	int b[] = {945, 946, 947, 0};
	int *p;

	p = &b[0];
	// ft_printf("%+#10.5hhd %c %s %p", 123, 'A', "Hello World", b);
	// ft_printf("%% %ld %i %o %u %#x %#X %s %-10c %p\n", -2147483648, 2147483647, 45035996, -2147483644, 1024, 2048, "Hello", 'A', b);
	// printf("%% %ld %i %o %u %#x %#X %s %-10c %p\n", -2147483648, 2147483647, 45035996, -2147483644, 1024, 2048, "Hello", 'A', b);

	ft_printf("% d\n", -9999);
	printf("% d", -9999);

	// int c = ft_printf("1: %jd\n", -9223372036854775808);
	// int d = printf("2: %jd\n", -9223372036854775808);
	// printf("%d %d", c, d);

	// ft_printf("%.5s %+d %i %o %u %x %c %p %%", "Hello World", INT_MAX, INT_MIN, 100, -100, 255, 'A', b);
	// ft_printf("%ld\n", LLONG_MAX);
	// printf("%ld\n", LLONG_MAX);


	// a = ft_printf("1: %s\n", "ααα");
	// c = printf("%ls", L"\u2620");  //printf("2: %ls\n", L"ααα");
	// printf("%d %d\n", a, c);

	ft_printf("1: %e\n", -2.0);
	printf("2: %e\n", -2.0);

	ft_printf("1: %e\n", 0.013);
	printf("2: %e\n", 0.013);

	ft_printf("1: %e\n", 123.786);
	printf("2: %e\n", 123.786);

	ft_printf("1: %e\n", 8.0003432121213);
	printf("2: %e\n", 8.0003432121213);

	// printf("%e\n", 8.76);
	// printf("%a\n", 8.76);

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

	// ft_printf("{%05.s}", 0);
	// printf("{%05.s}", 0);

	// ft_printf("1: %p\n", 0);
	// printf("2: %p\n\n", 0);  Ǳ

	// ft_printf("1: {%f}{%F}\n", -1.42, -1.42);
	// printf("2: {%f}{%F}\n\n", -1.42, -1.42);

	// ft_printf("1: %llx, %llx\n", 0, ULONG_MAX);
	// printf("2: %llx, %llx\n", 0, ULONG_MAX);

	// ft_printf("1: %hhx, %hhx\n", 0, UCHAR_MAX + 42);
	// printf("2: %hhx, %hhx\n", 0, UCHAR_MAX + 42);

	// ft_printf("1: %zx, %zx\n", 0, ULLONG_MAX);
	// printf("2: %zx, %zx\n", 0, ULLONG_MAX);

	// ft_printf("1: {% 03d}\n", 0);
	// printf("2: {% 03d}\n\n", 0);

	// ft_printf("1: % d\n", 0);
	// printf("2: % d\n\n", 0);

	// ft_printf("1: % +d\n", 42);
	// printf("2: % +d\n\n", 42);

	// ft_printf("1: % 10.5d\n", 4242);
	// printf("2: % 10.5d\n\n", 4242);


	// ft_printf("{%5p}\n", 0);
	// printf("{%5p}\n\n", 0);
	
	// for(int i = 0; i < 30; i++)
	// 	printf("%c\n", i);

	// b = ft_printf("ft_printf: %0100llb %n Hello Man\n", 9223372036854775807, &a);
	// printf("%d %d", a, b);
	// ft_printf("ft_printf: %030llb\n", -92233720);
	// printf("printf:    %#030llb\n", 9223372036854775807);

	//printf("%c[1;33mHello, world!\n", 27);
	// ft_printf("{%f}{%F}\n", -1444565444646.6465424242242454654, -1444565444646.6465424242242454654);
	// printf("{%f}{%F}\n", -1444565444646.6465424242242454654, -1444565444646.6465424242242454654);

	return (0);
}