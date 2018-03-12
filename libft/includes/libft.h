/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 09:47:49 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/12 08:44:04 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>
# include <limits.h>
# include "ft_printf.h"
# define BUFF_SIZE 32
# define MAX(a, b) ((a > b) ? a : b)
# define MIN(a, b) ((a < b) ? a : b)

typedef	struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

/*
** Str
*/
char			**ft_strsplit(const char *s, char c);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_str_multi_chr(char *str, char *characters);
char			*ft_strcpy(char *s1, const char *s2);
char			*ft_strdup (const char *str);
char			*ft_strndup(const char *str, size_t n);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t max);
char			*ft_strncpy(char *s1, const char *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strnstr(const char *s1, const char *s2, size_t len);
char			*ft_strmap(const char *s, char (*f)(char));
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strsub(const char *s, unsigned int start, size_t len);
char			*ft_strsub_to(char *str, char c);
char			*ft_strtrim(const char *s);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strequ(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t max);
int				ft_strnequ(const char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlen(const char *str);
void			ft_putendl(const char *s);
void			ft_putendl_fd(const char *s, int fd);
void			ft_putstr(const char *str);
void			ft_putnstr(const char *str, size_t n);
void			ft_putstr_fd(const char *s, int fd);
void			ft_strclr(char *s);
void			ft_strdel(char **as);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (f)(unsigned int, char *));
void			ft_puterror(char *str);
void			ft_exit_error(char *str);
char			*ft_strrev(char *str);
char			*ft_skip_whitespace(char *str);
void			ft_print_ptr(size_t nb);
size_t			ft_ptr_len_base(size_t ptr, unsigned int base);
void			ft_putwstr(wchar_t *str);
void			ft_putnwstr(wchar_t *str, int n);
int				ft_wstrlen(wchar_t *str);
int				ft_wstrnlen(wchar_t *str, int len);
int				get_next_line(const int fd, char **line);
void			ft_free_array(char ***array, int size);
int				ft_isnumber(char *str);

/*
** Hex
*/
void			ft_print_u_hex(unsigned long long int nb, const char *str);
void			ft_print_hex(long long int nb, const char *str);
int				ft_hex_len(unsigned long long int nb);

/*
** Char
*/
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
bool			ft_is_space(char c);
int				ft_toupper(int c);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putnchar(char c, size_t n);
int				ft_wcharlen(wchar_t c);

/*
** Mem
*/
void			ft_bzero(void *pointer, size_t length);
int				ft_memcmp(const void *s1, const void *s2, size_t num);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memchr(const void *str, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			ft_memdel(void **ap);
void			*ft_memalloc(size_t size);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *buffer, int c, size_t n);

/*
** Lst
*/
t_list			*ft_lstnew(const void *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *n);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** Nbr
*/
long long		ft_atoi(const char *str);
int				ft_atoi_base(const char *str, int base);
int				ft_abs(int a);
size_t			ft_longlong_len(long long int nbr);
size_t			ft_len_base(long long int nb, char base);
size_t			ft_u_longlong_len(unsigned long long nb);
size_t			ft_u_len_base(unsigned long long nb, char base);
void			ft_putnbr(int nbr);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbrendl(int nbr);
void			ft_put_longlong_base(long long int nbr, char base);
void			ft_put_u_longlong_base(unsigned long long int nb, char base);
int				ft_putwchar(wchar_t c);
char			*ft_itoa(int n);
char			*ft_itoa_longlong_base(long long n, char base);

#endif
