/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anime <anime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 23:40:51 by anime             #+#    #+#             */
/*   Updated: 2020/06/11 02:58:01 by anime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <stdio.h>
# include <sys/types.h>
# include <dirent.h>
# include <sys/stat.h>
# include <unistd.h>
# include <limits.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <errno.h>
# define DEFAULT_BLOCK_SIZE 512
# define DEV_BSIZE 1024

typedef struct stat		t_stat;
typedef struct dirent	t_dirent;
typedef struct timespec	t_timespec;

typedef struct			s_form
{
	int					user;
	int					group;
	long int			size;
	long int			blocks;
	unsigned long		links;
}						t_form;

typedef struct			s_file
{
	blkcnt_t			st_blocks;
	mode_t				mode;
	nlink_t				st_nlink;
	off_t				size;
	time_t				time;
	long				ntime;
	char				*name;
	char				*user;
	char				*group;
	char				type;
	struct s_file		*next;
	struct s_file		*prev;
	struct s_file		*append;
}						t_file;

typedef struct			s_look
{
	char				flags[128];
	t_file				*arg_dirs;
	t_file				*arg_files;
	int					(*cmp)(t_file *, t_file *);
	int					blocks;
	int					err_type;
	char				inv_opt;
	t_form				fm;
	char				exist_args;
	char				show_total;
}						t_look;

void					kill_exe(char *s);
void					show_list_next(t_file *file);
void					show_list_prev(t_file *file);
void					init(t_look *look);
void					parse_args(t_look *look, int argc, char **argv);
void					check_flags(t_look *look);
t_file					*create_file_list(t_look *look);
t_file					*add_new_file(t_file *file_tail, t_stat *stat);
void					show_recursive_dir(t_look *look, t_file *root);

t_file					*create_file(char *name, char type);
void					push_file(t_file **file, t_file *newf,
							int (*cmp)(t_file *, t_file *));
void					push_dir(t_file **file, t_file *newf,
							int (*cmp)(t_file *, t_file *));
void					read_dir(t_look *look, DIR *dir, char *path);
void					join_by(char *s1, char *s2, char del, char *s3);
void					set_file_info(t_file *file, char *path, t_look *look);
void					reset_format_ls(t_form *fm, t_file *f);
void					parse_result(t_look *look, t_file *file, char *path);
int						ft_numcount(int nb);
char					*ft_strup(char *s, char c);
void					ft_put_until(char *s, char c);
int						cmp_name(t_file *f1, t_file *f2);
char					get_file_type_2(int mode);
char					get_file_type(unsigned char type);
void					find_sort_type(t_look *look);
void					reset_format_zero(t_form *fm);
void					print_err(char *s);
void					free_look(t_look *look);
void					free_files(t_file *file);

#endif
