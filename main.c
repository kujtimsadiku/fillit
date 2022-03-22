#include "fillit.h"

int main(void)
{
	t_data data;
	t_tetris tetris;

	// if (argc != 2)
	// 	exit(0);
	check_map(&data, "map.txt");
	save_tetrimino(&data, &tetris);
	// solve_map(&data, &tetris);

	return (0);
}