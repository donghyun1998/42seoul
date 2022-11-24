#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	printf("return: %d", ft_printf("%x", -10));
	printf("\n");
	printf("return: %d", printf("%x", -10));
}
