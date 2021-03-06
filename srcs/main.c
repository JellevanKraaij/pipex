/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/24 17:00:21 by jvan-kra      #+#    #+#                 */
/*   Updated: 2022/03/24 17:00:21 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <libft.h>

int	main(int argc, char *argv[], char *envp[])
{
	t_files		files;
	t_env		env;

	if (argc < 5)
	{
		ft_putendl_fd("input error\n", 2);
		exit(1);
	}
	files.input = argv[1];
	files.output = argv[argc - 1];
	env.envp = envp;
	env.parsed_path = parse_path(envp);
	return (pipex(files, &argv[2], argc - 3, env));
}
