/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:20:36 by maweiss           #+#    #+#             */
/*   Updated: 2024/04/08 16:15:49 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stddef.h>

typedef struct s_cont
{
	int	dist_b;
	int	dist_a;
	int	index;
	int	target;
	int	chunk;
	int	value;
}			t_cont;

typedef struct s_list
{
	t_cont			*cont;
	struct s_list	*next;
}					t_list;

t_list		*ft_lst2ndlast(t_list *lst);
int			ft_pa(t_list **lst_a, t_list **lst_b, int silent);
int			ft_pb(t_list **lst_a, t_list **lst_b, int silent);
int			ft_sa(t_list **lst_a, int silent);
int			ft_sb(t_list **lst_b, int silent);
int			ft_ss(t_list **lst_a, t_list **lst_b, int silent);
int			ft_ra(t_list **lst_a, int silent);
int			ft_rb(t_list **lst_b, int silent);
int			ft_rr(t_list **lst_a, t_list **lst_b, int silent);
int			ft_rra(t_list **lst_a, int silent);
int			ft_rrb(t_list **lst_b, int silent);
int			ft_rrr(t_list **lst_a, t_list **lst_b, int silent);
void		ft_free(void **tofree, int index);
void		ft_lstfree(t_list **lst);
int			ft_dup_sorted(t_list *lst_a);
// int		ft_sorted(t_list *lst_a);
int			**ft_parse_several(int argc, char **argv);
int			**ft_parse_one(char *input, int *size);
int			ft_validate_args(char *str, int *valid);
t_list		*ft_fill_lst(int **stack_a, int *size);
void		ft_solve(int **stack_a, int *size);
void		ft_solve_3_l(t_list **lst_a);
void		ft_solve_3_r(t_list **lst_b);
void		ft_solve_5(t_list **lst_a, t_list **lst_b, int *size, int chunks);
void		ft_solve_10(t_list **lst_a, t_list **lst_b, int *size, int chunks);
void		ft_solve_big(t_list **lst_a, t_list **lst_b, int *size, int chunks);
t_cont		*ft_create_cont(int *val);
void		ft_calc_index(t_list **lst_a, int size);
void		ft_assign_chunk(t_list **lst_a, int size, int chunks);
int			ft_chunks(int size);
int			ft_find_chunk(t_list **lst, int chunk, int size);
void		ft_find_chunk_init(int *dist_b, int *dist_t, int *i, int *ch_done);
int			ft_find_index(t_list **lst_1, int index);
void		ft_push_val(t_list **lst_1, t_list **lst_2, int size_1, int size_2);
void		ft_push_b(t_list **lst_a, t_list **lst_b, int size_a, int chunks);
void		ft_push_a(t_list **lst_1, t_list **lst_2, int size_2);
void		ft_0_top(t_list **lst_a);
int			ft_calc_dist(t_list **lst_a, int index, int *dist_t, int *dist_b);
int			ft_turn_a(t_list **lst, int dist);
int			ft_turn_b(t_list **lst, int dist);
int			ft_cheapest(t_list **lst_b);
void		ft_dist(t_list **lst_b, int size_b, t_list **lst_a);
int			ft_finish_b(t_list **lst_a, t_list **lst_b);
int			ft_find_target(t_list **lst_a, int index);
// libft content:
int			ft_atoi(const char *nptr);
long		ft_atol(const char *nptr);
int			ft_countwords(char const *str, char c);
void		*ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
char		*ft_itoa(int nb);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(char *src);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *str);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strrchr(const char *s, int c);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_tolower(int c);
int			ft_toupper(int c);
t_list		*ft_lstnew(void *cont);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int			ft_printf(const char *s, ...);
int			ft_pnb_b_fd(long nbr, char *base, int fd, int negp);
int			ft_pnb_b_fd_s(int nbr, char *base, int fd, int negp);
int			ft_putstr_fd_ret(char *s, int fd);
int			ft_putchar_fd_ret(char c, int fd);
char		*ft_get_next_line(int fd);
void		ft_putstr_non_printable(char *str, size_t n);
int			ft_abs(int a);

#endif
