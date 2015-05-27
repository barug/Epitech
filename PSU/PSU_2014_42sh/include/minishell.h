/*
** minishell.h for minishell in /home/barthe_g/rendu/PSU/PSU_2014_minishell/include
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Wed Jan 21 15:42:20 2015 barthelemy gouby
** Last update Sun May 24 18:36:51 2015 Barthelemy Gouby
*/

#ifndef MINISHELL_H_
# define MINISHELL_H_

# define EXIT_FAILED (-1)
# define TERMINATE_PROCESS (1)
# define BUILTIN_FAILED (2)
# define EXIT_EXIT (4)
# define CMD_FAILED (3)

int		g_spid;
int		g_malloc;
char		**g_env;

typedef struct	s_command
{
  char		**args;
  int		pipein;
  int		pipeout;
  char		*input;
  char		*output;
  char		*append;
  char		*endread;
}		t_command;

typedef int	(*builtin)(char **inptab, char **pathtab);

typedef struct	s_builtin
{
  char		*name;
  builtin	f;
}		t_builtin;

typedef struct	s_parser
{
  t_command	**cmd_tab;
  char		*sep;
}		t_parser;

int		search_builtins(t_command command, char **pathtab);
char		**alloc_pathtab( char *pathstr);
int		make_pathentry(char *pathstr, char **pathtab,
			       int *i, int tabpos);
char		**get_pathtab();
char		*make_path(char *directory, char *filename);
int		search_exec(t_command *command, char **pathtab);
void		free_tab(char **tab);
int		command_parser(char *input, t_parser *pars);
int		cmd_cd(char **inptab, char **pathtab);
int		make_newenv(char *name, char *value, int *i);
int		execute_cmd_sequence(t_command *cmd_sequence,
				     char **pathtab, int *i);
int		cmd_cd(char **inptab, char **pathtab);
int		cmd_echo(char **inptab, char **pathtab);
int		cmd_exit(char **inptab, char **pathtab);
int		cmd_env(char **inptab, char **pathtab);
int		make_newenv(char *name, char *value, int *i);
void		copy_variable(char *name, char *value, int i);
int		make_newvariable(char *name, char *value);
int		overwrite_value(char *name, char *value);
int		my_setenv(char *name, char *value);
int		cmd_setenv(char **inptab, char **pathtab);
int		fork_and_pipe(t_command *cmd_sequence, char **pathtab, int *i);
int		execute_cmd_sequence(t_command *cmd_sequence,
				     char **pathtab, int *i);
int		execute_cmd_tab(t_parser *pars, char **pathtab);
int		execute_prog(t_command *command, char **pathtab);
int		do_redirections(t_command *command);
void		free_tab(char **tab);
char		**make_env(char **envp);
void		ctr_c(int sig);
void		ctr_z(int sig);
int		my_realloc_env();
int		do_redirections(t_command *command);
void		free_all(t_parser *pars, char **pathtab);
int		make_args(char **input_tab, int *n, t_command *command_node);
void		find_redirections(char **input_tab,
				  t_command **command_sequence, int *n, int i);
t_command	*make_command_sequence(char **input_tab, int *n, int i);
int		search_exec(t_command *command,  char **pathtab);
int		verify_exec(char *path);
int		fork_and_wait(t_command *command, char *path);

#endif /* !MINISHELL_H_ */
