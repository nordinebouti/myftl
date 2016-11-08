
#ifndef		__MY_FTL_H__
# define	__MY_FTL_H__

#include	<stdlib.h>

typedef struct 				s_navigation_tools
{
	char					*system_state;
	int						sector;
	int						evade;		
}							t_navigation_tools;

typedef struct 				s_weapon
{
	char					*system_state;
	int						damage;		
}							t_weapon;

typedef struct  			s_ftl_drive
{
	int						energy;
	char					*system_state;
}							t_ftl_drive;

typedef	struct				s_ship
{
  	int						hull;
  	t_weapon				*weapons;
  	t_ftl_drive				*ftl_drive;
  	t_navigation_tools		*nav_tools;
}				t_ship;

char			*readline(void);
void			my_putchar(const char c);
int				my_strlen(const char *str);
void			my_putstr(const char *str);
int				my_strcmp(const char *s1, const char *s2);
char			*my_strdup(const char *str);
void			my_putstr_color(const char *color, const char *str);
t_ship			*create_ship();
int             add_weapon_to_ship(t_ship *addr_ship);
int             add_ftl_drive_to_ship(t_ship *addr_ship);

#endif
