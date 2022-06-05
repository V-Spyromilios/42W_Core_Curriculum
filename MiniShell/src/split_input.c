/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:12:58 by espyromi          #+#    #+#             */
/*   Updated: 2022/02/10 22:12:58 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_next_word_col(char **pointer_place)
{
	char	*pointer;
	char	c;
	int		start;
	int		len;

	pointer = *pointer_place;
	start = 0;
	len = 0;
	while (*(pointer + start + len) && *(pointer + start + len) != '|')
	{
		c = *(pointer + start + len++);
		if (c == '"' || c == '\'')
		{
			while (*(pointer + start + len) && *(pointer + start + len) != c)
				len++;
			if (*(pointer + start + len))
				len++;
		}
	}
	if (*(pointer + start + len) == '|')
		*pointer_place = pointer + start + len + 1;
	else
		*pointer_place = pointer + start + len;
	return (ft_substr(pointer, start, len));
}

char	*get_next_if_needed(char *pointer, char **pp, t_data *data)
{
	char	*temp1;
	char	*temp2;
	int		flag;

	if (**pp && **pp != ' ')
	{
		flag = 1;
		temp1 = get_next_word(pp, &flag, data);
		temp2 = ft_strjoin(pointer, temp1);
		free(temp1);
		if (pointer)
			free(pointer);
		pointer = temp2;
	}
	return (pointer);
}

char	*get_next_word(char **pointer_place, int *flag, t_data *data)
{
	char	*pointer;
	char	*sub;
	char	ch;
	int		start;
	int		len;

	pointer = *pointer_place;
	start = 0;
	ch = ' ';
	while (*(pointer + start) == ' ')
		start++;
	len = get_len_next_word(pointer, &start, &ch, flag);
	*pointer_place = pointer + start + len;
	sub = ft_substr(pointer, start, len);
	pointer = create_expand(*flag, sub, data);
	if (*flag && pointer && pointer[0] == '$'
		&& ft_strncmp(pointer, "$?", ft_strlen(pointer))
		&& !ft_strncmp(sub, pointer, ft_strlen(pointer)))
	{
		pointer = ft_strdup("");
		free(sub);
	}
	if (ch != ' ' && **pointer_place == ch)
		*pointer_place += 1;
	return (get_next_if_needed(pointer, pointer_place, data));
}

char	**split_input(char *line, char c, t_data *data)
{
	int		words;
	int		i;
	int		flag;
	char	**argv;
	char	*pointer;

	words = get_word_count_helper(line, c);
	if (c == '|' && words != 1)
		data->pipe_nb = words;
	argv = (char **) malloc((words + 1) * sizeof(char *));
	if (!argv)
		error(data, "Malloc failed for input data argv\n", 0, 'p');
	i = 0;
	pointer = line;
	while (i < words)
	{
		flag = 1;
		if (c == '|')
			*(argv + i) = get_next_word_col(&pointer);
		else
			*(argv + i) = get_next_word(&pointer, &flag, data);
		i++;
	}
	*(argv + i) = NULL;
	return (argv);
}
