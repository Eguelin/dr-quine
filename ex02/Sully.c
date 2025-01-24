#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define NAM "Sully_%d"
#define FILE "%s.c"
#define EXE "./%s"
#define CMD "gcc -Wall -Wextra -Werror %s.c -o %s"
#define CODE "#include <stdio.h>%c#include <stdlib.h>%c#include <unistd.h>%c#include <fcntl.h>%c%c#define NAM %cSully_%cd%c%c#define FILE %c%cs.c%c%c#define EXE %c./%cs%c%c#define CMD %cgcc -Wall -Wextra -Werror %cs.c -o %cs%c%c#define CODE %c%s%c%c%cint main(void) {int	i = %d;int	fd;char	nam[17];char	file[19];char	exe[19];char	cmd[67];if (i <= 0) {return (0);}snprintf(nam, 17, NAM, i - 1);snprintf(file, 19, FILE, nam);snprintf(exe, 19, EXE, nam);snprintf(cmd, 67, CMD, nam, nam);fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);dprintf(fd, CODE, 10, 10, 10, 10, 10, 34, 37, 34, 10, 34, 37, 34, 10, 34, 37, 34, 10, 34, 37, 37, 34, 10, 34, CODE, 34, 10, 10, i - 1, 10);close(fd);system(cmd);execl(exe, exe, NULL);return (0);}%c"

int main(void) {int	i = 5;int	fd;char	nam[17];char	file[19];char	exe[19];char	cmd[67];if (i <= 0) {return (0);}snprintf(nam, 17, NAM, i - 1);snprintf(file, 19, FILE, nam);snprintf(exe, 19, EXE, nam);snprintf(cmd, 67, CMD, nam, nam);fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);dprintf(fd, CODE, 10, 10, 10, 10, 10, 34, 37, 34, 10, 34, 37, 34, 10, 34, 37, 34, 10, 34, 37, 37, 34, 10, 34, CODE, 34, 10, 10, i - 1, 10);close(fd);system(cmd);execl(exe, exe, NULL);return (0);}

