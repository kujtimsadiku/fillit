#include "fillit.h"

static void shift_x(t_data *data, int p, int n)
{
	data->px[p][0] += n;
	data->px[p][1] += n;
	data->px[p][2] += n;
	data->px[p][3] += n;
}

static void shift_y(t_data *data, int p, int n)
{
	data->py[p][0] += n;
	data->py[p][1] += n;
	data->py[p][2] += n;
	data->py[p][3] += n;
}

void	shifter(t_data *data, int p)
{
	while (data->px[p][0] != 0 && data->px[p][1] != 0 &&
		data->px[p][2] != 0 && data->px[p][3] != 0)
		{
			shift_x(data, p, -1);
		}
	while (data->py[p][0] != 0 && data->py[p][1] != 0 &&
		data->py[p][2] != 0 && data->py[p][3] != 0)
		{
			shift_y(data, p, -1);
		}
	while (data->px[p][0] != 0 && data->py[p][0] == 0)
		shift_x(data, p, -1);
}

/*shifter for all direction??*/
