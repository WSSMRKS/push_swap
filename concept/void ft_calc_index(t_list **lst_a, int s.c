void	ft_calc_index(t_list **lst_a, int size)
{
	int			min;
	long int	min_o;
	int			index;
	t_list		*tmp_a;
	t_list		*tmp_min;

	index = 0;
	min_o = (long)-INT_MAX -2;
	while (index < size)
	{
		tmp_min = NULL;
		min = INT_MAX;
		tmp_a = *lst_a;
		while (tmp_a)
		{
			if ((tmp_a->cont->value <= tmp_min->cont->value || tmp_min == NULL) && (long) tmp_a->cont->value > min_o)
				tmp_min = tmp_a;
			tmp_a = tmp_a->next;
		}
		tmp_min->cont->index = index++;
		ft_assign_chunk(&tmp_min, size, ft_chunks(size));
		min_o = tmp_min->cont->value;
	}
}
