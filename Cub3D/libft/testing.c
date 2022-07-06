
#include "libft.h"

char	*ft_shift(char *s)
{
	int	counter;

	counter = 0;
	while (s[counter] != '\0')
	{
		s[counter] = s[counter + 1];
		counter++;
	}
	return (s);
}

static int	ft_words(char *temp, char c)
{
	int	counter;
	int	words;	

	counter = 1;
	words = 1;
	if (temp[0] == '\0')
		return (0);
	while (temp[counter] != '\0')
	{
		if (temp[counter] == c)
			words++;
		counter++;
	}
	return (words);
}

static char	*ft_cut(char *temp, char c)
{
	int		counter;

	while (temp[0] == c && temp[0] != '\0')
		temp = ft_shift(temp);
	if (temp[0] == '\0')
		return (temp);
	counter = ft_strlen(temp);
	while ((counter != 0) && (temp[counter] == c))
	{
		temp[counter] = '\0';
		counter--;
	}
	return (temp);
}

static char	*ft_fill_word(char *temp, char c)
{
	char	*result;
	int		counter;

	counter = 0;
	result = ft_calloc(ft_strlen(temp) + 1, 1);
	if (!result)
		return (NULL);
	while ((temp[counter] != c) && (temp[counter] != '\0'))
	{
		result[counter] = temp[counter];
		counter++;
	}
	result[counter] = '\0';
	return (result);
}

static char	*ft_cut_used(char *temp, char c)
{
	while ((temp[0] != c) && (temp[0] != '\0'))
		temp = ft_shift(temp);
	temp = ft_cut(temp, c);
	return (temp);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		counter;
	int		words;
	char	*temp;

	if (!s)
		return (NULL);
	counter = 0;
	temp = ft_strdup(s);
	temp = ft_cut(temp, c);
	words = ft_words(temp, c);
	result = (char **)ft_calloc((words + 1), sizeof(temp));
	if (!result)
		return ((char **)s);
	if (s[0] == '\0')
	{	
		free (result);
		result = (char **)ft_calloc(2, sizeof(temp));
		result[0][0] = '\0';
		result[1] = NULL;
		return (result);
	}	
	while (temp[0] != '\0')
	{
		result[counter] = ft_fill_word(temp, c);
		temp = ft_cut_used(temp, c);
		counter++;
	}
	free(temp);
	return (result);
}

int main()
{
	char	**res;
	char	*str;

	str = "";

	res = ft_split(str, 'z');
	return (0);
}