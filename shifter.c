#include "fillit.h"

static void shift_x(t_data *data, int n)
{
	data->px[0] += n;
	data->px[1] += n;
	data->px[2] += n;
	data->px[3] += n;
}

static void shift_y(t_data *data, int n)
{
	data->py[0] += n;
	data->py[1] += n;
	data->py[2] += n;
	data->py[3] += n;
}

void	shifter(t_data *data)
{
	while (data->px[0] != 0 && data->px[1] != 0 &&
		data->px[2] != 0 && data->px[3] != 0)
		{
			shift_x(data, -1);
		}
	while (data->py[0] != 0 && data->py[1] != 0 &&
		data->py[2] != 0 && data->py[3] != 0)
		{
			shift_y(data, -1);
		}
}