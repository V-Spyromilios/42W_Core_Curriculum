#include <stdio.h> //for printf
#include <stdlib.h> //for free
#include <unistd.h> // for write

typedef struct s_list
{
	int value;
	struct s_list	*next;
}			t_list;

// Functions for input handling
void	just_the_two_of_us(int *input);
int 	*take_arg(int len, char *arg[]);
void	argument_handling(char **argv);
int		ft_atoi(const char *str);
int		check_if_sorted(int *arr, int length);
void	check_input(int *arr, int len);
int		*copy(int *arr, int len);
int		*bbsort(int *arr, int len);
int		check_duplicate(int *arr);
int 	*get_sorted_indexes(int *before, int *after, int len);

// Functions for struct management
int		init_struct(int *indexed, int len);
void	ft_lstadd_back(t_list *lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	printlst(t_list *lst);
void	sort_stack(t_list *major_a, t_list *major_b, int len);
void	sort_3(t_list *head);
// void	error_handling(void); //error handler Already Sorted/Errong Handling / No Arguments
// void	sa(void);  //swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
// void	sb(void);  //swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
// void	ss(void);  //sa and sb at the same time.
// void	pa(void);  //push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
// void	pb(void);  //push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
// void	ra(void);  //rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
// void	rb(void);  //rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
// void	rr(void);  //ra and rb at the same time.
t_list	*rra(t_list *head);
// void	rrb(void);  //reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
// void	rrr(void); //rra and rrb at the same time.