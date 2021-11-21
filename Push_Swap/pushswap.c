#include "pushswap.h"

int main(int argc, char *argv[])
{
	int *input;
	int	*sorted;
	int	*unsorted;
	int	*indexed;
	//int k = 0;

	if (argc == 2)
		return (0);
	input = take_arg(argc - 1, argv);
	unsorted = copy(input, argc - 1);
	sorted = bbsort(input, argc - 1);
	indexed = get_sorted_indexes(unsorted, sorted, argc - 1);
	if (argc == 3)
		just_the_two_of_us(indexed);
	init_struct(indexed, argc - 1);
	// while (k < argc - 1)
	// {
	// 	printf("%d\n", indexed[k]);
	// 	k++;
	// }
	// return (0);
}




/*
**	Already Sorted
**	Errong Handling / No Arguments
**	Establish the rules
**
**	sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
**	sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
**	ss : sa and sb at the same time.
**	pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
**	pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
**	ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
**	rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
**	rr : ra and rb at the same time.
**	rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
**	rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
**	rrr : rra and rrb at the same time.
**
*/
