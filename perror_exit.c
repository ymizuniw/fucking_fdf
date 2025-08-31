#include "includes/fdf.h"

void perror_exit(char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}
