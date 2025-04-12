#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define CODE "#include <unistd.h>%1$c#include <fcntl.h>%1$c#include <stdio.h>%1$c%1$c#define CODE %2$c%3$s%2$c%1$c#define FILE_NAME %2$cGrace_kid.c%2$c%1$c#define MAIN(code, file_name) int main(void) {char *x = code;int fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);if (fd == -1){return(1);};dprintf(fd, x, 10, 34, code);close(fd);return (0);}%1$c%1$c/*%1$cUSE YOUR BRAIN%1$c*/%1$cMAIN(CODE, FILE_NAME)%1$c"
#define FILE_NAME "Grace_kid.c"
#define MAIN(code, file_name) int main(void) {char *x = code;int fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);if (fd == -1){return(1);};dprintf(fd, x, 10, 34, code);close(fd);return (0);}

/*
USE YOUR BRAIN
*/
MAIN(CODE, FILE_NAME)
