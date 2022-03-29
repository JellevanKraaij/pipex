/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/24 16:52:40 by jvan-kra      #+#    #+#                 */
/*   Updated: 2022/03/24 16:52:40 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

typedef struct s_files
{
	char	*input;
	char	*output;
}	t_files;

void	pipex(t_files files, char **cmds, int total_cmds, char *envp[]);

char	*lookup_fullcmd(char *cmd, char *envp[]);

void	perror_exit(char *s);
void	*null_exit(void *p);
void	file_error_exit(char *filename, int errnum);
void	cmd_error_exit(char *cmd);

#endif
