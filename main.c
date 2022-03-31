#include "fillit.h"

int main(int argc, char **argv)
{
	t_data data;
	t_tetris tetris;

	if (argc != 2)
		exit(0);
	check_map(&data, argv[1]);
	save_tetrimino(&data, &tetris);
	solve_map(&data, &tetris);

	return (0);
}