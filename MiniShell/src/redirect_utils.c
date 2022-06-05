/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:12:39 by espyromi          #+#    #+#             */
/*   Updated: 2022/02/10 22:12:39 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	if_to_trim(t_data *data, int *i, int *flag, char *to_trim)
{
	size_t	j;

	j = 0;
	while (data->line[*i] == to_trim[j])
	{
		++*i;
		++j;
		if (j == ft_strlen(to_trim))
		{
			*flag = 1;
			break ;
		}
	}
}

void	trim_line(t_data *data, char *to_trim)
{
	char	*temp;
	int		i;
	int		k;
	int		flag;
	int		n;

	i = -1;
	k = 0;
	n = -1;
	flag = 0;
	temp = ft_calloc(ft_strlen(data->line), 1);
	if (!temp)
		error(data, "Malloc failed for new line", 0, 'p');
	while (data->line[++i])
	{
		k = i;
		if_to_trim(data, &i, &flag, to_trim);
		if (!flag)
			i = k;
		else
			flag = 0;
		temp[++n] = data->line[i];
	}
	free(data->line);
	data->line = temp;
}

int	is_it_inquote(char *line, char *str)
{
	char	*p;
	int		inqoute;
	char	c;

	p = line;
	inqoute = 0;
	c = '"';
	while (p != str)
	{
		if (!inqoute && (*p == '\'' || *p == '"'))
		{
			inqoute = 1;
			c = *p;
		}
		else if (inqoute && *p == c)
			inqoute = 0;
		p++;
	}
	return (inqoute);
}

char	*is_redir(char *line, char *str)
{
	char	*p;
	char	*pp;
	int		end;

	pp = line;
	end = 0;
	while (*pp && !end)
	{
		p = ft_strnstr(pp, str, ft_strlen(pp));
		if (p != 0 && is_it_inquote(line, p))
			pp = p + ft_strlen(str);
		else
			end = 1;
	}
	return (p);
}

char	**get_redir(t_data *data, char *c)
{
	int		i;
	int		start_len[2];
	char	**ret;
	char	*p;

	i = -1;
	start_len[1] = 0;
	p = is_redir(data->line, c);
	while ((data->line + ++i) != p)
		continue ;
	start_len[0] = i;
	while (data->line[i] == *c || data->line[i] == ' ')
		++i;
	while (data->line[i + start_len[1]] && data->line[i + start_len[1]] != ' ')
	{
		start_len[1]++;
		if (data->line[i + start_len[1]] == '>'
			|| data->line[i + start_len[1]] == '<')
			break ;
	}
	ret = NULL;
	ret = create_redir_string(data, ret, i, start_len);
	if (ret)
		trim_line(data, ret[1]);
	return (ret);
}
