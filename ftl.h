
#ifndef		__MY_FTL_H__
# define	__MY_FTL_H__

#include	<stdlib.h>
#include	<unistd.h>

typedef struct 				s_freight t_freight;	

struct 						s_freight
{
	char					*item;
	t_freight				*prev;
	t_freight				*next;
};

typedef	struct 				s_container
{
	t_freight				*first;
	t_freight				*last;
	int						nb_elem;
}							t_container;

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
  	t_container				*cont;
}							t_ship;

typedef struct    			s_repair_command
{
	char					*name;
	int						(*func)(t_ship *addr_ship);
}							t_repair_command;

char						*readline(void);
void						my_putchar(const char c);
int							my_strlen(const char *str);
void						my_putstr(const char *str);
int							my_strcmp(const char *s1, const char *s2);
char						*my_strdup(const char *str);
void						my_putstr_color(const char *color, const char *str);
int    						my_putnbr(int nb);
t_ship						*create_ship();
int             			add_weapon_to_ship(t_ship *addr_ship);
int             			add_ftl_drive_to_ship(t_ship *addr_ship);
int                        	add_navigation_tools_to_ship(t_ship *addr_ship);
int							add_container_to_ship(t_ship *addr_ship);
void						add_freight_to_container(t_ship *addr_ship, t_freight *freight);
void						del_from_to_container(t_ship *addr_ship, t_freight *freight);
void						get_bonus(t_ship *addr_ship);
void 						ftl_drive_system_check(t_ship *addr_ship);
void 						navigation_tools_system_check(t_ship *addr_ship);
void						weapon_system_check(t_ship *addr_ship);
void						system_control(t_ship *addr_ship);
int 						navigation_tools_system_repair(t_ship *addr_ship);
int							weapon_system_repair(t_ship *addr_ship);
int							ftl_drive_system_repair(t_ship *addr_ship);
int							system_repair(t_ship *addr_ship);

#endif
