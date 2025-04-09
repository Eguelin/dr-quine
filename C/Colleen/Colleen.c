#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

/*
I'm so stupid
*/
int	ft_print(char *x)
{
	return(printf(x, 10, 34, x));
}

int	main(void)
{
	/*
	but really!
	*/
	char	*x = "#include <unistd.h>%1$c#include <fcntl.h>%1$c#include <stdio.h>%1$c%1$c/*%1$cI'm so stupid%1$c*/%1$cint	ft_print(char *x)%1$c{%1$c	return(printf(x, 10, 34, x));%1$c}%1$c%1$cint	main(void)%1$c{%1$c	/*%1$c	but really!%1$c	*/%1$c	char	*x = %2$c%3$s%2$c;%1$c%1$c	if (ft_print(x) == -1)%1$c		return(1);%1$c	return (0);%1$c}%1$c";

	if (ft_print(x) == -1)
		return(1);
	return (0);
}
