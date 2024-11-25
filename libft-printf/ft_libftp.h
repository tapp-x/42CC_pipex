/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libftp.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:01:24 by tappourc          #+#    #+#             */
/*   Updated: 2024/01/20 09:46:36 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFTP_H
# define FT_LIBFTP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include "stdarg.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define OPEN_MAX 1024

int		ft_printf(const char *s, ...);
int		print_hex_up(unsigned int nb);
int		print_hex_low(unsigned int nb);
int		print_hex_ptr(unsigned long int nb);
int		print_hex(unsigned long int nb, char choice);
int		ft_putchar(int c);
int		ft_putnbr(int n);
int		ft_putstr(char *s);
int		ft_putnbr_unsigned(unsigned int n);
int		ft_match_format(va_list ap, char c);

typedef struct s_char_list
{
	char				c;
	struct s_char_list	*next;
}				t_char_list;

char	*get_next_line(int fd);
void	ft_lstadd_back_gnl(t_char_list **lst, t_char_list *new);
char	*ft_lstiter_gnl(t_char_list *lst, char const *s1);
char	*ft_strjoin_char(char *s1, char const c);
void	ft_lstclear_line(t_char_list **lst, void (*del)(void*));

#endif
