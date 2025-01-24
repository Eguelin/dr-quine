#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

/*I'm so stupid*/
int	ft_creat(char *x)
{
	int	fd = open("tmp_Colleen", O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if (fd == -1)
		return(1);
	dprintf(fd, x, 10, 34, x);
	close(fd);
	return(0);
}

int	main(void)
{
	/*but really!*/
	char	*x = "#include <unistd.h>%1$c#include <fcntl.h>%1$c#include <stdio.h>%1$c%1$c/*I'm so stupid*/%1$cint	ft_creat(char *x)%1$c{%1$c	int	fd = open(%2$ctmp_Colleen%2$c, O_WRONLY | O_CREAT | O_TRUNC, 0644);%1$c%1$c	if (fd == -1)%1$c		return(1);%1$c	dprintf(fd, x, 10, 34, x);%1$c	close(fd);%1$c	return(0);%1$c}%1$c%1$cint	main(void)%1$c{%1$c	/*but really!*/%1$c	char	*x = %2$c%3$s%2$c;%1$c%1$c	if (ft_creat(x))%1$c		return(1);%1$c	return (0);%1$c}%1$c";

	if (ft_creat(x))
		return(1);
	return (0);
}
