/*
	This is for the  symbolwe going to add.
	It takes the piece number tetris->tetrimino[count] 
	and adds character + the number;
*/
char	symbol(int symbol_nb)
{
	char c;

	c = 'A' + symbol_nb;
	return (c);
}