#include <stdio.h>
#include "libasm.h"

static char	*ft_append_char(char *str, char c)
{
	int		i;
	char	*str_new;

	i = 0;
	if ((str_new = malloc(sizeof(char) * (ft_strlen(str) + 2))) == NULL)
		return (NULL);
	while (str[i])
	{
		str_new[i] = str[i];
		i++;
	}
	str_new[i] = c;
	str_new[i + 1] = '\0';
	free(str);
	return (str_new);
}

static int	get_next_line(char **line)
{
	char	c;
	int		ret;
	char	*str;
	
	c = '\0';
	ret = 1;
	if ((str = malloc(sizeof(char) * 1)) == NULL)
		return (-1);
	str[0] = '\0';
	while (c != '\n' && ret != 0)
	{
		if ((ret = ft_read(0, &c, 1)) == -1)
			return (-1);
		else if (c != '\n' && ret != 0)
			if ((str = ft_append_char(str, c)) == NULL)
				return (-1);
	}
	*line = str;
	return (ret == 0 ? 0 : 1);
}

int	main()
{
	int ret;
	char src[] = "salut";
	char dest[6];
	char *line;

	printf("len=%d\n", ft_strlen(src));
	printf("copy=%s\n", ft_strcpy(dest, src));
	printf("cmp=%d\n", ft_strcmp(src, "salou"));
	printf("cmp=%d\n", ft_strcmp(src, "salut"));
	printf("cmp=%d\n", ft_strcmp(src, "saluti"));
	printf("cmp=%d\n", ft_strcmp(src, "salu"));
	ret = ft_write(1, src, ft_strlen(src));
	if (ft_write(1, NULL, 1) < 0)
		perror("\nft_write errno");
	printf("ret=%d\n", ret);
	get_next_line(&line);
	printf("line=%s\n", line);
	free(line);
	line = ft_strdup(src);
	ft_write(1, line, ft_strlen(line));
	free(line);
	return (0);
}