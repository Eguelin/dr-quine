#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

/*I'm so stupid*/
int	ft_creat(char *x)
{
	int	fd = open("tmp_Colleen", O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if (fd == -1)
		return(1);
	dprintf(fd, x, 10, 10, 10, 10, 10, 10, 10, 34, 34, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 34, x, 34, 10, 10, 10, 10, 10, 10);
	close(fd);
	return(0);
}

int	main(void)
{
	/*but really!*/
	char	*x = "#include <unistd.h>%c#include <fcntl.h>%c#include <stdio.h>%c%c/*I'm so stupid*/%cint	ft_creat(char *x)%c{%c	int	fd = open(%ctmp_Colleen%c, O_WRONLY | O_CREAT | O_TRUNC, 0644);%c%c	if (fd == -1)%c		return(1);%c	dprintf(fd, x, 10, 10, 10, 10, 10, 10, 10, 34, 34, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 34, x, 34, 10, 10, 10, 10, 10, 10);%c	close(fd);%c	return(0);%c}%c%cint	main(void)%c{%c	/*but really!*/%c	char	*x = %c%s%c;%c%c	if (ft_creat(x))%c		return(1);%c	return (0);%c}%c";

	if (ft_creat(x))
		return(1);
	return (0);
}
