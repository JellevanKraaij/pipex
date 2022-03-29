/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path_parsing.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/29 21:59:25 by jvan-kra      #+#    #+#                 */
/*   Updated: 2022/03/29 21:59:25 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>
#include <unistd.h>
#include <stddef.h>
#include <libft.h>
#include <errno.h>

char	**parse_path(char *envp[])
{
	char	**split;
	size_t	i;

	i = 0;
	while (1)
	{
		if (envp[i] == NULL)
			return (NULL);
		if (!ft_strncmp(envp[i], "PATH=", 5))
			break ;
		i++;
	}
	split = null_exit(ft_split(&envp[i][5], ':'));
	return (split);
}

char	*check_paths(char *test_cmd, char **path)
{
	char	*join;
	size_t	i;

	i = 0;
	while (path[i] != NULL)
	{
		join = null_exit(ft_strjoin(path[i], test_cmd));
		if (access(join, X_OK) == 0)
		{
			free(test_cmd);
			ft_split_free(path);
			return (join);
		}
		free(join);
		i++;
	}
	return (NULL);
}

char	*lookup_fullcmd(char *cmd, char *envp[])
{
	char	*full_cmd;
	char	**path;

	if (cmd[0] == '/' || cmd[0] == '.')
	{
		if (access(cmd, X_OK) == 0)
			file_error_exit(cmd, errno);
		return (cmd);
	}
	path = parse_path(envp);
	if (path == NULL)
		cmd_error_exit(cmd);
	full_cmd = check_paths(null_exit(ft_strjoin("/", cmd)), path);
	if (full_cmd == NULL)
		cmd_error_exit(cmd);
	return (full_cmd);
}
