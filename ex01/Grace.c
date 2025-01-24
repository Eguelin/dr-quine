#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define STRING "#include <unistd.h>%c#include <fcntl.h>%c#include <stdio.h>%c%c#define STRING %c%s%c%c#define MAIN(str) int main(void) {char *x = str;int fd = open(%cGrace_kid.c%c, O_WRONLY | O_CREAT | O_TRUNC, 0644);if (fd == -1){return(1);};dprintf(fd, x, 10, 10, 10, 10, 34, str, 34, 10, 34, 34, 10, 10, 10, 10);close(fd);return (0);}%c%c/*USE YOUR BRAIN*/%cMAIN(STRING)%c"
#define MAIN(str) int main(void) {char *x = str;int fd = open("Grace_kid.c", O_WRONLY | O_CREAT | O_TRUNC, 0644);if (fd == -1){return(1);};dprintf(fd, x, 10, 10, 10, 10, 34, str, 34, 10, 34, 34, 10, 10, 10, 10);close(fd);return (0);}

/*USE YOUR BRAIN*/
MAIN(STRING)
