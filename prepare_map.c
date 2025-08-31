#include "includes/fdf.h"

void	prepare_map(char *argv, t_app *app)
{
    parse_map((const char *)argv, app);
    fprintf(stderr, "parse map passed\n");
    convert_map(app);
    fprintf(stderr, "convert map passed\n");
}
