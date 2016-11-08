
#ifndef		__MY_FTL_H__
# define	__MY_FTL_H__

#include	<stdlib.h>

typedef struct 	s_weapon
{
	char		*system_state;
	int			damage;		
}				t_weapon;

typedef	struct	s_ship
{
  	int			hull;
  	t_weapon	*weapon;
}				t_ship;

char			*readline(void);
void			my_putchar(const char c);
int				my_strlen(const char *str);
void			my_putstr(const char *str);
int				my_strcmp(const char *s1, const char *s2);
char			*my_strdup(const char *str);
void			my_putstr_color(const char *color, const char *str);
t_ship			*create_ship();

#endif
