/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_exit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/29 21:30:22 by jvan-kra      #+#    #+#                 */
/*   Updated: 2022/03/29 21:30:22 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	perror_exit(char *s)
{
	perror(s);
	exit(EXIT_FAILURE);
}

void	*null_exit(void *p)
{
	if (p == NULL)
		perror_exit("pipex");
	return (p);
}

void	file_error_exit(char *filename, int errnum)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	ft_putstr_fd(strerror(errnum), STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(filename, STDERR_FILENO);
	exit(127);
}

void	cmd_error_exit(char *cmd)
{
	ft_putstr_fd("pipex: command not found: ", STDERR_FILENO);
	ft_putendl_fd(cmd, STDERR_FILENO);
	exit(127);
}
