/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/29 22:03:50 by jvan-kra      #+#    #+#                 */
/*   Updated: 2022/03/29 22:03:50 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>
#include <fcntl.h>
#include <libft.h>
#include <errno.h>

void	execute_cmd(char *cmd, int input, int output, char *envp[])
{
	char	**cmd_argv;
	char	*file;

	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	if (dup2(input, STDIN_FILENO) < 0 || dup2(output, STDOUT_FILENO) < 0)
		perror_exit("pipex");
	close(input);
	close(output);
	cmd_argv = null_exit(ft_split(cmd, ' '));
	file = lookup_fullcmd(cmd_argv[0], envp);
	execve(file, cmd_argv, envp);
	perror_exit("pipex");
}

void	first_cmd(char *cmd, char *input, int output[2], char *envp[])
{
	int	forkr;
	int	inputfd;

	forkr = fork();
	if (forkr < 0)
		perror_exit("pipex");
	if (forkr == 0)
	{
		inputfd = open(input, O_RDONLY);
		if (inputfd < 0)
			file_error_exit(input, errno);
		close(output[0]);
		execute_cmd(cmd, inputfd, output[1], envp);
	}
	close(output[1]);
}

void	mid_cmd(char *cmd, int input, int output[2], char *envp[])
{
	int	forkr;

	forkr = fork();
	if (forkr < 0)
		perror_exit("pipex");
	if (forkr == 0)
	{
		close(output[0]);
		execute_cmd(cmd, input, output[1], envp);
	}
	close(input);
	close(output[1]);
}

void	last_cmd(char *cmd, int input, char *output, char *envp[])
{
	int	outputfd;

	outputfd = open(output, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outputfd < 0)
		file_error_exit(output, errno);
	execute_cmd(cmd, input, outputfd, envp);
}

void	pipex(t_files files, char **cmds, int total_cmds, char *envp[])
{
	int	i;
	int	j;
	int	pipefd[2][2];

	i = 0;
	j = 0;
	while (i < total_cmds)
	{
		if (i + 1 < total_cmds)
			pipe(pipefd[j]);
		if (i == 0)
			first_cmd(cmds[i], files.input, pipefd[j], envp);
		else if (i + 1 == total_cmds)
			last_cmd(cmds[i], pipefd[!j][0], files.output, envp);
		else
			mid_cmd(cmds[i], pipefd[!j][0], pipefd[j], envp);
		j = !j;
		i++;
	}
}
