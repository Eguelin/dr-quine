#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

/*I'm so stupid*/
void	ft_creat(char *x)
{
	int fd = open("tmp_Colleen", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return;
	dprintf(fd, x, 10, 10, 10, 10, 10, 9, 10, 10, 9, 34, 34, 10, 9, 10, 9, 9, 10, 9, 10, 9, 10, 10, 10, 9, 10, 10, 9, 10, 9, 34, x, 34, 10, 9, 10, 9, 10, 10);
	close(fd);
}

int	main(void)
{
	/*but really!*/
	char *x = "#include <unistd.h>%c#include <fcntl.h>%c#include <stdio.h>%c%c/*I'm so stupid*/%cvoid%cft_creat(char *x)%c{%c%cint fd = open(%ctmp_Colleen%c, O_WRONLY | O_CREAT | O_TRUNC, 0644);%c%cif (fd == -1)%c%c%creturn;%c%cdprintf(fd, x, 10, 10, 10, 10, 10, 9, 10, 10, 9, 34, 34, 10, 9, 10, 9, 9, 10, 9, 10, 9, 10, 10, 10, 9, 10, 10, 9, 10, 9, 34, x, 34, 10, 9, 10, 9, 10, 10);%c%cclose(fd);%c}%c%cint%cmain(void)%c{%c%c/*but really!*/%c%cchar *x = %c%s%c;%c%cft_creat(x);%c%creturn (0);%c}%c";
	ft_creat(x);
	return (0);
}
