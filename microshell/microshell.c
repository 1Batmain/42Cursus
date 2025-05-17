#include "microshell.h"

int	count_cmd_block(char **av)
{
	int cnt;

	cnt = 1;
	while (*av)
	{
		if (!strcmp(*av, ";") && *(av + 1))
			cnt++;
		av++;
	}
	return (cnt);
}

int	split_commands(char **av, t_data *water)
{
	int semi_cnt;

	semi_cnt = count_cmd_block(av) + 1;
	water->cmd = malloc(semi_cnt * sizeof (char **));
	if (!water->cmd)
		return (1);
	while (*av)
	{
			
	}
	return (0);
}

int main(int ac, char **av, char **env)
{
	static t_data	water;

	if (split_commands(av, &water))
		return(1);
	return (0);	
}
