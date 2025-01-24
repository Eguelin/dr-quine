#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define NAM "Sully_%d"
#define FILE "%s.c"
#define CMD "gcc -Wall -Wextra -Werror %s.c -o %s"
#define CODE "#include <stdio.h>%c#include <stdlib.h>%c#include <unistd.h>%c#include <fcntl.h>%c%c#define NAM %cSully_%cd%c%c#define FILE %c%cs.c%c%c#define CMD %cgcc -Wall -Wextra -Werror %cs.c -o %cs%c%c#define CODE %c%s%c%c%cint main(void)%c{%c	int		i = %d;%c	int		fd;%c	int		pid;%c	char	nam[18];%c	char	file[20];%c	char	cmd[67];%c%c	if (i <= 0)%c		return (0);%c	snprintf(nam, 18, NAM, i - 1);%c	snprintf(file, 20, FILE, nam);%c	snprintf(cmd, 67, CMD, nam, nam);%c	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);%c	if (fd == -1)%c		return (1);%c	dprintf(fd, CODE, 10, 10, 10, 10, 10, 34, 37, 34, 10, 34, 37, 34, 10, 34, 37, 37, 34, 10, 34, CODE, 34, 10, 10, 10, 10, i - 1, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10);%c	close(fd);%c	if (system(cmd))%c		return (1);%c	pid = fork();%c	if (pid == -1)%c		return (1);%c	if (pid == 0 && execl(nam, nam, NULL))%c		return (1);%c	return (0);%c}%c"

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
	snprintf(cmd, 67, CMD, nam, nam);
	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (1);
	dprintf(fd, CODE, 10, 10, 10, 10, 10, 34, 37, 34, 10, 34, 37, 34, 10, 34, 37, 37, 34, 10, 34, CODE, 34, 10, 10, 10, 10, i - 1, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10);
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
