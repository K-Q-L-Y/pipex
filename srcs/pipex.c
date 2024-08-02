/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 22:32:08 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/08/02 10:42:01 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	redirect_io(int i, int n, int fd[2], int pipes[2])
{
	if (i > 0)
		dup2(pipes[0], STDIN_FILENO);
	else if (fd[0] != STDIN_FILENO)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
	if (i < n - 1)
		dup2(pipes[1], STDOUT_FILENO);
	else if (fd[1] != STDOUT_FILENO)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
	}
	close(pipes[0]);
	close(pipes[1]);
}

static void	sh_execute(char *cmd)
{
	char	*args[4];

	args[0] = "/bin/sh";
	args[1] = "-c";
	args[2] = cmd;
	args[3] = NULL;
	execve("/bin/sh", args, NULL);
	perror("execve");
}

static void	close_pipes(int pipes[2])
{
	close(pipes[1]);
}

static void	multi_execute(int n, char **cmds, int fd[2], char **paths)
{
	static int	i = -1;
	int			pipes[2];
	pid_t		pid;

	if (pipe(pipes) == -1)
		exit_perror("pipe", 1);
	while (++i < n)
	{
		if (check_command(cmds[i], paths, (i == n - 1)))
		{
			pid = fork();
			if (pid == 0)
			{
				if (i == 0 && fd[0] < 0)
					exit(1);
				redirect_io(i, n, fd, pipes);
				sh_execute(cmds[i]);
				exit(1);
			}
			else
				close_pipes(pipes);
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	char	**paths;

	if (argc < 4 || argc > 5)
		return (1);
	fd[1] = get_outfile(argv[argc - 1]);
	fd[0] = get_infile(argv[1]);
	paths = get_paths(envp);
	multi_execute(argc - 3, argv + 2, fd, paths);
	exit(0);
}
