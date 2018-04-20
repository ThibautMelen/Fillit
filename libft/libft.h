/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 20:18:28 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/12 10:47:18 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef unsigned char	t_byte;
typedef struct			s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}						t_list;

/*
** Memory
*/
void					*ft_memset(void *mem, int byte, size_t size);
void					ft_bzero(void *mem, size_t size);
void					*ft_memcpy(void *dest, const void *src, size_t size);
void					*ft_memccpy(void *dest, const void *src, int chr,
									size_t size);
void					*ft_memmove(void *dest, const void *src, size_t size);
void					*ft_memchr(const void *mem, int chr, size_t size);
int						ft_memcmp(const void *mem1, const void *mem2,
									size_t size);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ptr);

/*
** String
*/
size_t					ft_strlen(const char *str);
char					*ft_strdup(const char *str);
char					*ft_strcpy(char *dest, const char *src);
char					*ft_strncpy(char *dest, const char *src, size_t size);
char					*ft_strcat(char *str1, const char *str2);
char					*ft_strncat(char *str1, const char *str2, size_t size);
size_t					ft_strlcat(char *dest, const char *src, size_t size);
char					*ft_strchr(const char *str, int chr);
char					*ft_strrchr(const char *str, int chr);
char					*ft_strstr(const char *str, const char *search);
char					*ft_strnstr(const char *str, const char *search,
									size_t size);
int						ft_strcmp(const char *str1, const char *str2);
int						ft_strncmp(const char *str1, const char *str2,
									size_t size);
char					*ft_strnew(size_t size);
void					ft_strdel(char **ptr);
void					ft_strclr(char *str);
void					ft_striter(char *str, void (*f)(char *));
void					ft_striteri(char *str,
									void (*f)(unsigned int, char *));
char					*ft_strmap(const char *str, char (*f)(char));
char					*ft_strmapi(const char *str,
									char (*f)(unsigned int, char));
int						ft_strequ(const char *str1, const char *str2);
int						ft_strnequ(const char *str1, const char *str2,
									size_t size);
char					*ft_strsub(const char *str, unsigned int start,
									size_t size);
char					*ft_strjoin(const char *str1, const char *str2);
char					*ft_strjoinch(const char *str, char chr);
char					*ft_strtrim(const char *str);
char					**ft_strsplit(const char *str, char c);
char					*ft_strupper(const char *str);
char					*ft_strlower(const char *str);
char					*ft_strcapitalize(const char *str);

/*
** List
*/
t_list					*ft_lstnew(const void *content, size_t size);
void					ft_lstdelone(t_list **plist,
										void (*del)(void *, size_t));
void					ft_lstdel(t_list **plist, void (*del)(void *, size_t));
void					ft_lstclear(t_list **plist);
size_t					ft_lstlen(t_list *list);
void					ft_lstadd(t_list **plist, t_list *new);
void					ft_lstaddi(t_list **plist, t_list *new, int index);
void					ft_lstpush(t_list **plist, t_list *new);
void					ft_lstremove(t_list **plist, t_list *elem);
t_list					*ft_lstget(t_list *list, int index);
void					ft_lstiter(t_list *list, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *list, t_list *(*f)(t_list *elem));

/*
** Writers
*/
void					ft_putchar(char c);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr(const char *str);
void					ft_putstr_fd(const char *str, int fd);
void					ft_putendl(const char *str);
void					ft_putendl_fd(const char *str, int fd);
void					ft_putnbr(int nbr);
void					ft_putnbr_fd(int nbr, int fd);

/*
** Testers
*/
int						ft_isblank(int chr);
int						ft_islower(int chr);
int						ft_isupper(int chr);
int						ft_isalpha(int chr);
int						ft_isdigit(int chr);
int						ft_isalnum(int chr);
int						ft_isascii(int chr);
int						ft_isprint(int chr);

/*
** Converters
*/
int						ft_atoi(const char *str);
char					*ft_itoa(int nbr);
int						ft_toupper(int chr);
int						ft_tolower(int chr);

#endif
