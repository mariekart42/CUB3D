/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:47:25 by mmensing          #+#    #+#             */
/*   Updated: 2023/04/02 21:14:42 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# include <strings.h>
# include <stddef.h>
# include <unistd.h>
# include <string.h>

typedef struct s_list
{	
	void			*content;
	struct s_list	*next;
}					t_list;

// PART 1
void	ft_bzero(void *str, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memchr(const void *str, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *str1, const void *str2, size_t n);
void	*ft_memset(void *str, int c, size_t n);

int		ft_atoi(const char *str);
int		ft_isalnum(int val);
int		ft_isalpha(int val);
int		ft_isascii(int val);
int		ft_isdigit(int val);
int		ft_isprint(int val);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_tolower(int c);
int		ft_toupper(int c);

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strnstr(const char *str1, const char *str2, size_t len);
char	*ft_strdup(char *src);

// PART 2
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		count_strings(char const *s, char c);
int		count_chars(char const *s, char c);
void	transfercleanstring(char *copy, char const *s, char c);
char	**makearray(const char *s, char c, char *copy, int j);
char	**ft_split(char const *s, char c);

void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

//BONUS
int		ft_lstsize(t_list *lst);

t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);

void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
#endif