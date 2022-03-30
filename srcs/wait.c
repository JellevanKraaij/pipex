/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wait.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/30 12:20:49 by jvan-kra      #+#    #+#                 */
/*   Updated: 2022/03/30 12:20:49 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include "pipex.h"

int	wait_for_all_childs(int child_count, int lastpid)
{
	int	i;
	int	exit_code;
	int	status;

	i = 0;
	exit_code = 1;
	while (i < child_count)
	{
		if (waitpid(-1, &status, 0) == lastpid && WIFEXITED(status))
				exit_code = WEXITSTATUS(status);
		if (WIFEXITED(status) || WIFSIGNALED(status))
		i++;
	}
	return (exit_code);
}
