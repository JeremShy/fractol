#include <fractol.h>

double conv_rep_to_win(double x, double min, double max)
{
	double	diff;
	double	ret;
	double	prop;

	diff = 0 - min;
	min += diff;
	max += diff;
	prop = WIN_SIZE / max;
	ret = (x + diff) * prop;
	return (ret);
}
