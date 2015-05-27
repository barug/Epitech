/*
** my.h for my.h in /home/barthe_g/rendu/Piscine_C_J11/lib/my
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Mon Oct 20 21:55:23 2014 barthelemy gouby
** Last update Tue Feb  3 15:19:33 2015 barthelemy gouby
*/

#ifndef MY_H_
# define MY_H_

char	*my_numbr_to_str(int nb);
void	my_putchar(char c);
int	my_isneg(int nb);
int	my_put_nbr(int nb);
int	my_swap(int *a, int *b);
int	my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
int	my_power_rec(int nb, int power);
int	my_square_root(int nb);
int	my_is_prime(int nombre);
int	my_find_prime_sup(int nb);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int nb);
char	*my_revstr(char *str);
char	*my_strstr(char *str, char *to_find);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int nb);
char	*my_strupcase(char *str);
char	*my_strlowcase(char *str);
char	*my_strcapitalize(char *str);
int	my_str_isalpha(char *str);
char	*my_strdup(char *src);
int	my_isnum(char *str);
int	my_str_islower(char *str);
int	my_str_isupper(char *str);
int	my_str_isprintable(char *str);
int	my_showstr(char *str);
int	my_showmem(char *str, int size);
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src);
int	my_strlcat(char *dest, char *src, int size);
int     my_putnbr_base_uns(unsigned int nbr, char *base);
int     my_printf(const char *fmt, ...);
char    *get_next_line(const int fd);
char	**my_str_to_wordtab(char *str);
char    **add_array_entry(char **tab, char *array_entry);

#endif /* MY_H_ */
