#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define STRING "#include <unistd.h>%1$c#include <fcntl.h>%1$c#include <stdio.h>%1$c%1$c#define STRING %2$c%3$s%2$c%1$c#define MAIN(str) int main(void) {char *x = str;int fd = open(%2$cGrace_kid.c%2$c, O_WRONLY | O_CREAT | O_TRUNC, 0644);if (fd == -1){return(1);};dprintf(fd, x, 10, 34, str);close(fd);return (0);}%1$c%1$c/*%1$cUSE YOUR BRAIN%1$c*/%1$cMAIN(STRING)%1$c"
#define MAIN(str) int main(void) {char *x = str;int fd = open("Grace_kid.c", O_WRONLY | O_CREAT | O_TRUNC, 0644);if (fd == -1){return(1);};dprintf(fd, x, 10, 34, str);close(fd);return (0);}

/*
USE YOUR BRAIN
*/
MAIN(STRING)
