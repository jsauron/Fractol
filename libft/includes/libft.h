/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 19:26:38 by jrobin            #+#    #+#             */
/*   Updated: 2018/08/03 00:23:08 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memmove(void *dest, const void *src, unsigned long n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, unsigned long n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memchr(const void *s, int c, unsigned long n);
int					ft_memcmp(const void *s1, const void *s2, unsigned long n);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *str);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strstr(const char *phrase, const char *mot);
char				*ft_strnstr(const char *phrase, const char *mot, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int i);
int					ft_isdigit(int i);
int					ft_isalnum(int i);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int i);
int					ft_tolower(int i);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src,
					unsigned long size);
unsigned long		ft_strlcat(char *dest, const char *src, size_t size);
void				*ft_memalloc(size_t size);
char				**ft_strsplit(char const *s, char c);
void				ft_putchar(char c);
void				ft_putstr(char const *str);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_itoa(int n);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char const *str, int fd);
void				ft_putnbr(int n);
int					ft_islower(int c);
int					ft_isupper(int c);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *newi);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				*ft_strupcase(char *str);
char				*ft_strlowcase(char *str);
void				ft_strswap(char *s1, char *s2);
void				ft_swap(int *a, int *b);
void				ft_sort_integer_table(int *tab, int size);
char				*ft_strrev(char *str);
int					ft_is_neg(int n);
int					*ft_range(int min, int max);
void				ft_foreach(int *tab, int lenght, void (*f)(int));
int					s_word(char const *s, char c);
int					ft_count(char const *s, char c);
int					ft_isspace(int c);
int					get_next_line(const int fd, char **line);

#endif
