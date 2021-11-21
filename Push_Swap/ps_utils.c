#include "pushswap.h"

void	just_the_two_of_us(int *input)
{
	int	holder;
	if (input[1] > input[2])
	{
		holder = input[1];
		input[1] = input[2];
		input[2] = holder;
		write(1, "sa\n", 3);
		exit(0);
	}
	else
		exit(0);
}

int *take_arg(int len, char *arg[])
{
	int	i;
	int	j;
	int	*arr;
	int	tmp;

	j = 1;
	i = 0;
	arr = (int *)malloc((len) * sizeof(int));
	if (!arr)
		return (0);
	while (i < len)
	{
		tmp = ft_atoi(arg[j]);
		if (!tmp)
		{
			free (arr);
			write(1,"Error\n", 6);
			exit(-1);
		}
		arr[i] = tmp;
		j++;
		i++;
	}
	check_input(arr, len);
	if (check_if_sorted(arr, len) == 1)
	{
		free (arr);
		return(NULL);
	}
	return (arr);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	if (!str)
		return (0);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (*str < 48 || *str > 57)
		return (0);
	while (*str >= 48 && *str <= 57)
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

void	check_input(int *arr, int len)
{
	int		i;

	i = 0;
	if (check_duplicate(arr) == -1)
	{
		free(arr);
		return;
	}
	while (len > 0)
	{
		if (arr[i] > 2147483647 || arr[i] < -2147483648)
		{
			free (arr);
			write(1, "Error\n", 6);
		}
		len --;
		i++;
	}
}

int	check_if_sorted(int *arr, int length)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (length - 1 > 0)
	{
		if (arr[i] < arr[i + 1])
			i++;
		else
			k++;
		length--;
	}
	if (k == 0)
		return(1);
	else
		return(0);
}

int	*bbsort(int *arr, int len)
{
	int	step;
	int	i;
	int	temp;
	int	flag;
	int	s;

	step = 0;
	i = 0;
	s = 0;
	while (step < len - 1)
	{
		flag = 0;
		i = 0;
		while (i < len - step - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				flag = 1;
			}
			i++;
		}
		step++;
	}
	return (arr);
}

int		*copy(int *arr, int len)
{
	int	*storage;
	int	i;

	i = 0;
	storage = (int *)malloc((len) * sizeof(int));
	if (!storage)
		exit(-1);
	while(i < len)
	{
		storage[i] = arr[i];
		i++;
	}
	return (storage);
}

int		check_duplicate(int *arr)
{
	int	i;
	int	j;
	
	i = 0;
	j = 1;
	while(arr[i] != '\0')
	{
		j = i + 1;
		while (arr[j] != '\0')
		{
			if (arr[i] == arr[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int *get_sorted_indexes(int *before, int *after, int len)
{
    int    *indexes;
    int    i;
    int    j;
    int    k;

	indexes = (int *)malloc((len + 1)* sizeof(int));
	i = 0;
	j = 0;
	k = 0;
	while(i < len)
	{
		j = 0;
		while (j < len)
		{
			if (before[i] == after[j])
				indexes[k] = j;
			j++;
		}
		i++;
		k++;
	}
	// free (before);
	// free (after);
	return (indexes);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list *lst, t_list *new)
{
	t_list	*holder;

	if (lst)
	{
		holder = ft_lstlast((lst));
		holder->next = new;
	}
}

t_list	*ft_lstnew(int value)
{
	t_list	*instance;

	instance = (t_list *)malloc(sizeof(t_list));
	if (!instance)
		return (NULL);
	instance->value = value;
	instance->next = NULL;
	return (instance);
}

void	printlst(t_list *lst)
{
	//printf("Printed %d\n", lst->next->next->value);
	while (lst)
	{
		printf("%d :  %p\n", lst->value, lst);
		lst = lst->next;
	}
}

int		init_struct(int *indexed, int len)
{
	t_list	*major_a;
	t_list	*major_b;
	t_list	*new;
	int		i;

	i = 0;
	major_b = NULL;
	new = ft_lstnew(indexed[i]);
	major_a = new;
	i++;
	while (i < len)
	{
		new = ft_lstnew(indexed[i]);
		ft_lstadd_back(major_a, new);
		i++;
	}
	printlst(major_a);
	sort_stack(major_a, major_b, len);

	return (0);
}

void	sort_stack(t_list *major_a, t_list *major_b, int len)
{
	if (len == 3)
		sort_3(major_a);
}

void	sort_3(t_list *head)
{
	if (head->value < head->next->value && head->next->value > head->next->next->value && head->value < head->next->next->value) // 1 3 2 
	{
		printf("Case: 1 3 2");
		//rra(arr, len);
		//sa(arr);
	}
	else if (head->value < head->next->value && head->next->value > head->next->next->value && head->value > head->next->next->value)
	{
		printf("Case: 2 3 1\n");
		head = rra(head);
		printlst(head);
	} // 2 3 1
	else if (head->value > head->next->value && head->next->value < head->next->next->value && head->next->next->value > head->value) // 2 1 3
		printf("Case: 2 1 3\n");
		//sa(arr);
	else if (head->value > head->next->value && head->next->value > head->next->next->value && head->next->next->value < head->value) // 3 2 1
	{
		printf("Case: 3 2 1\n");
		//ra(arr, len);
		//sa(arr);
	}
	else if (head->value > head->next->value && head->next->value < head->next->next->value && head->value > head->next->next->value) // 3 1 2
		printf("Case: 3 1 2\n");
		//ra(arr, len);
}

t_list	*rra(t_list *head)
{
	t_list	*last;

	last = ft_lstlast(head); //last = address of last node(node_3)
	head->next->next = NULL;
	last->next = head;
	head = last;
	return (head);
}