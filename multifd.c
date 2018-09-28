#include "header.h"
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>

t_bool	is_valid_arg(const char *arg)
{
	intmax_t	tmp;
	size_t		len;

	len = ft_strsplen(arg);
	if (len > 11)
		return (false);
	tmp = ft_atoi(arg);
	if ((intmax_t)INT_MAX < (intmax_t)tmp || (intmax_t)tmp < (intmax_t)INT_MIN)
		return (false);
	if (*arg == '+' || *arg == '-')
		arg++;
	if (!ft_isdigit(*arg))
		return (false);
	while (*arg && !ft_isspace(*arg))
	{
		if (!ft_isdigit(*arg))
			return (false);
		arg++;
	}
	return (true);
}

static int	count_numbers_in_string(const char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && ft_isspace(*str))
			str++;
		if (is_valid_arg(str))
			count++;
		else
			if (*str)
				return (-1);
		str += ft_strsplen(str);
	}
	return (count);
}

static int	count_numbers_in_arg(const char *arg)
{
	int	fd;
	char	*line;
	int	acc;
	int	count;

	fd = open(arg, O_RDONLY);
	acc = 0;
	if (fd != -1)
	{
		while (ft_gnl(fd, &line))
		{
			count = count_numbers_in_string(line);
			if (count == -1)
				return (-1);
			acc += count;
		}
		if ((close(fd) == -1))
			ft_exit("Something went wrong while closing file descriptor.");
		return (acc);
	}
	else
		return (count_numbers_in_string(arg));
}
		
int	get_number_entries(char **argv)
{
	int	acc;
	int	count;

	acc = 0;
	while (*argv)
	{
		count = count_numbers_in_arg(*argv);
		if (count == -1)
			ft_exit("Error: invalid entry.");
		acc += count;
		argv++;
	}
	return (acc);
}
