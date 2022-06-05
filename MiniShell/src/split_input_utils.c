/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:12:52 by espyromi          #+#    #+#             */
/*   Updated: 2022/02/10 22:12:53 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	word_count_col(char *line, char c)
{
	int	i;
	int	inquote;
	int	words;

	i = 0;
	words = 0;
	inquote = 0;
	while (*(line + i) == ' ')
		i++;
	while (*(line + i))
	{
		if (!inquote && *(line + i) == c)
		{
			words++;
			while (*(line + i + 1) == c)
				i++;
		}
		else if (inquote < 2 && *(line + i) == '"')
			inquote = (inquote + 1) % 2;
		else if (inquote % 2 == 0 && *(line + i) == '\'')
			inquote = (inquote + 2) % 4;
		if (ft_strchr(line + ++i, c) == NULL)
			return (words + 1);
	}
	return (words);
}

int	word_count(char *line, char c)
{
	int	i;
	int	inquote;
	int	words;

	i = 0;
	words = 0;
	inquote = 0;
	while (*(line + i) == ' ')
		i++;
	while (*(line + i))
	{
		if (!inquote && *(line + i) == c)
		{
			words++;
			while (c == ' ' && !inquote && *(line + i + 1) == c)
				i++;
		}
		else if (*(line + i) == '"')
			inquote = (inquote + 1) % 2;
		i++;
		if (*(line + i) && ft_strchr(line + i, c) == NULL)
			return (words + 1);
	}
	return (words);
}

int	get_len_next_word(char *pointer, int *start, char *ch, int *flag)
{
	int	len;
	int	inquote;

	len = 0;
	inquote = 0;
	if (*(pointer + *start) == '"' || *(pointer + *start) == '\'')
	{
		if (*(pointer + *start) == '\'' && *(pointer + *start + 1) == '$')
			*flag = 0;
		*ch = *(pointer + *start);
		inquote = 1;
		*start += 1;
	}
	if (*(pointer + *start) == '$')
		len++;
	while (*(pointer + *start + len) && (*(pointer + *start + len) != *ch
			&& (inquote || (*(pointer + *start + len) != '"'
					&& *(pointer + *start + len) != '\''
					&& *(pointer + *start + len) != '$'))))
		len++;
	return (len);
}

int	get_word_count_helper(char *line, char c)
{
	int	words;

	if (c == '|')
		words = word_count_col(line, c);
	else
		words = word_count(line, c);
	return (words);
}
