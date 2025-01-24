#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define NAM "Sully_%d"
#define FILE "%s.c"
#define CMD "gcc -Wall -Wextra -Werror %1$s.c -o %1$s"
#define CODE "#include <stdio.h>%1$c#include <stdlib.h>%1$c#include <unistd.h>%1$c#include <fcntl.h>%1$c%1$c#define NAM %2$cSully_%3$cd%2$c%1$c#define FILE %2$c%3$cs.c%2$c%1$c#define CMD %2$cgcc -Wall -Wextra -Werror %3$c1$s.c -o %3$c1$s%2$c%1$c#define CODE %2$c%4$s%2$c%1$c%1$cint main(void)%1$c{%1$c	int		i = %5$d;%1$c	int		fd;%1$c	int		pid;%1$c	char	nam[18];%1$c	char	file[20];%1$c	char	cmd[67];%1$c%1$c	if (i <= 0)%1$c		return (0);%1$c	snprintf(nam, 18, NAM, i - 1);%1$c	snprintf(file, 20, FILE, nam);%1$c	snprintf(cmd, 67, CMD, nam);%1$c	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);%1$c	if (fd == -1)%1$c		return (1);%1$c	dprintf(fd, CODE, 10, 34, 37, CODE, i - 1);%1$c	close(fd);%1$c	if (system(cmd))%1$c		return (1);%1$c	pid = fork();%1$c	if (pid == -1)%1$c		return (1);%1$c	if (pid == 0 && execl(nam, nam, NULL))%1$c		return (1);%1$c	return (0);%1$c}%1$c"

int main(void)
{
	int		i = 5;
	int		fd;
	int		pid;
	char	nam[18];
	char	file[20];
	char	cmd[67];

	if (i <= 0)
		return (0);
	snprintf(nam, 18, NAM, i - 1);
	snprintf(file, 20, FILE, nam);
	snprintf(cmd, 67, CMD, nam);
	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (1);
	dprintf(fd, CODE, 10, 34, 37, CODE, i - 1);
	close(fd);
	if (system(cmd))
		return (1);
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0 && execl(nam, nam, NULL))
		return (1);
	return (0);
}
