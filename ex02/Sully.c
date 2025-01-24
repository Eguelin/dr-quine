#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define NAM "Sully_%d"
#define FILE "%s.c"
#define EXE "./%s"
#define CMD "gcc -Wall -Wextra -Werror %s.c -o %s"
#define CODE "#include <stdio.h>%c#include <stdlib.h>%c#include <unistd.h>%c#include <fcntl.h>%c%c#define NAM %cSully_%cd%c%c#define FILE %c%cs.c%c%c#define EXE %c./%cs%c%c#define CMD %cgcc -Wall -Wextra -Werror %cs.c -o %cs%c%c#define CODE %c%s%c%c#define IF(test, ret) if (test) return (ret)%c%cint main(void)%c{%c	int		i = %d;%c	int		fd;%c	char	nam[17];%c	char	file[19];%c	char	exe[19];%c	char	cmd[67];%c%c	IF(i <= 0, 0);%c	snprintf(nam, 17, NAM, i - 1);%c	snprintf(file, 19, FILE, nam);%c	snprintf(exe, 19, EXE, nam);%c	snprintf(cmd, 67, CMD, nam, nam);%c	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);%c	IF(fd == -1, 1);%c	dprintf(fd, CODE, 10, 10, 10, 10, 10, 34, 37, 34, 10, 34, 37, 34, 10, 34, 37, 34, 10, 34, 37, 37, 34, 10, 34, CODE, 34, 10, 10, 10, 10, 10, i - 1, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10);%c	close(fd);%c	IF(system(cmd), 1);%c	IF(execl(exe, exe, NULL), 1);%c	return (0);%c}%c"
#define IF(test, ret) if (test) return (ret)

int main(void)
{
	int		i = 20;
	int		fd;
	char	nam[17];
	char	file[19];
	char	exe[19];
	char	cmd[67];

	IF(i <= 0, 0);
	snprintf(nam, 17, NAM, i - 1);
	snprintf(file, 19, FILE, nam);
	snprintf(exe, 19, EXE, nam);
	snprintf(cmd, 67, CMD, nam, nam);
	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	IF(fd == -1, 1);
	dprintf(fd, CODE, 10, 10, 10, 10, 10, 34, 37, 34, 10, 34, 37, 34, 10, 34, 37, 34, 10, 34, 37, 37, 34, 10, 34, CODE, 34, 10, 10, 10, 10, 10, i - 1, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10);
	close(fd);
	IF(system(cmd), 1);
	IF(execl(exe, exe, NULL), 1);
	return (0);
}

