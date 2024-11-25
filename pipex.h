/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:32:14 by tappourc          #+#    #+#             */
/*   Updated: 2024/01/26 08:58:39 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft-printf/ft_libftp.h"
# include <fcntl.h>
# include <unistd.h>
# include <wait.h>
# include <stdlib.h>

//UTILS FONCTION
void	ft_exit_error(char *msg, int status);
void	ft_exit_clean(char *msg);
void	free_tab(char **tab);
void	check_open(char *file1, char *file2);
int		search_path(char **env);

//EXEC PART
char	*build_all_path(char *cmd, char **env);
int		ft_exec(char *cmd, char **env);
int		last_exec(char *cmd, char **env, char *filename);
void	first_exec(char *filename);

//FORK AND PIPE
void	child(int fd[2], char *cmd, char **env);
void	parent(int fd[2]);
void	make_pipe(char *cmd, char **env);

#endif
