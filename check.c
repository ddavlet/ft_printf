#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"


int	main()
{
	// char *ptr;

	// ptr = malloc (2);
	ft_printf("test:%4s\n", "txt");
	printf ("test:%4s\n\n", "txt");

	ft_printf("test:%-5i\n", 5);
	printf ("test:%-5i\n\n", 5);
}


