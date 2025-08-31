#include "includes/fdf.h"

void	prepare_map(char *argv, t_app *app)
{
    parse_map((const char *)argv, app);
    convert_map(app);
}
