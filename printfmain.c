#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	printf("return: %d", ft_printf("%p", ""));
	printf("\n");
	printf("return: %d", printf("%p", ""));
}
