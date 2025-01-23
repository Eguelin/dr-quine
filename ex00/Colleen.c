#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
/*I'm so stupid*/void ft_creat(char *x){int fd = open("tmp_Colleen", O_WRONLY | O_CREAT | O_TRUNC, 0644);if (fd == -1){return;};dprintf(fd, x, 10, 10, 10, 34, 34, 34, x, 34, 10);close(fd);}int main(void){char *x = "#include <unistd.h>%c#include <fcntl.h>%c#include <stdio.h>%c/*I'm so stupid*/void ft_creat(char *x){int fd = open(%ctmp_Colleen%c, O_WRONLY | O_CREAT | O_TRUNC, 0644);if (fd == -1){return;};dprintf(fd, x, 10, 10, 10, 34, 34, 34, x, 34, 10);close(fd);}int main(void){char *x = %c%s%c;ft_creat(x);return (0);/*but really!*/}%c";ft_creat(x);return (0);/*but really!*/}
