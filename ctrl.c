#include "4inrow.h"

int	control(void)
{
	char	hit;

	hit = waitkb();
	switch(hit)
	{
		case 'a':
			return(0);
		case 's':
			return(1);
		case 'd':
			return(2);
		case 'f':
			return(3);
		case 'j':
			return(4);
		case 'k':
			return(5);
		case 'l':
			return(6);
		case 'q':
			return(-9);
		case 'z':
			return(-2);
	}
	return (-1);
}
