#include "includes/fdf.h"

int wopen(const char *path)
{
    int fd;

    fd = open(path, O_RDONLY);
    if (fd < 0)
        perror_exit("open");
    return (fd);
}

void wclose(int fd)
{
    if (close(fd) < 0)
        perror_exit("close");
}
