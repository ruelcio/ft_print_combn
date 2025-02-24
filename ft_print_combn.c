#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_combination(char current_combination[], int size, char max_combination[])
{
	int	i;

	i = 0;
	while (i < size)
		ft_putchar(current_combination[i++]);
	if (current_combination[0] == max_combination[0])
	{
		ft_putchar('\n');
		return ;
	}
	ft_putchar(',');
	ft_putchar(' ');
}

void	ft_print_combn(int size)
{
	char	current_combination[9];
	char	max_combination[9];
	int	index_to_increment;
	int	new_digit;
	int	i;

	i = 0;
	while (i < size)
	{
		current_combination[i] = i + '0';
		max_combination[i] = (10 - size) + i + '0';
		i++;
	}
	ft_print_combination(current_combination, size, max_combination);

	while (current_combination[0] != max_combination[0])
	{
		index_to_increment = size - 1;
		while (current_combination[index_to_increment] == max_combination[index_to_increment])
			--index_to_increment;

		new_digit = current_combination[index_to_increment] + 1;
		current_combination[index_to_increment] = new_digit;
		while (index_to_increment < size - 1)
		{
			index_to_increment++;
			new_digit++;
			current_combination[index_to_increment] = new_digit;
		}
		ft_print_combination(current_combination, size, max_combination);
	}
}

int	main(void)
{
	ft_print_combn(2);
	return (0);
}
