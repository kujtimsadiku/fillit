#include "fillit.h"

int		check_cordination(t_data *data, int y, int x)
{
	if (data->size > y + data->py[0] && data->size > x + data->px[0] &&
		data->size > y + data->py[1] && data->size > x + data->px[1] &&
		data->size > y + data->py[2] && data->size > x + data->px[2] &&
		data->size > y + data->py[3] && data->size > x + data->px[3])
		return (1);
	else
		return (0);
}