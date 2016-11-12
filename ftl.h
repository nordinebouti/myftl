
#ifndef		__MY_FTL_H__
# define	__MY_FTL_H__

#include	<stdlib.h>
#include	<unistd.h>
#include	<time.h>

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

typedef struct 				s_enemy
{
	int						life;
	int						damage;
	int						lvl;
	char					*status;
}							t_enemy;

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
  	int						health;
  	int						explore;
  	t_weapon				*weapons;
  	t_ftl_drive				*ftl_drive;
  	t_navigation_tools		*nav_tools;
  	t_container				*cont;
  	t_enemy					*enemy;
}							t_ship;

typedef struct    			s_repair_command
{
	char					*name;
	int						(*func)(t_ship *addr_ship);
}							t_repair_command;

typedef struct    			s_menu_command
{
	char					*name;
	int						(*func)(t_ship *addr_ship);
}							t_menu_command;

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
int							del_from_container(t_ship *addr_ship, t_freight *freight);
int							get_bonus(t_ship *addr_ship);
void 						ftl_drive_system_check(t_ship *addr_ship);
void 						navigation_tools_system_check(t_ship *addr_ship);
void						weapon_system_check(t_ship *addr_ship);
int							system_control(t_ship *addr_ship);
int 						navigation_tools_system_repair(t_ship *addr_ship);
int							weapon_system_repair(t_ship *addr_ship);
int							ftl_drive_system_repair(t_ship *addr_ship);
int							system_repair(t_ship *addr_ship);
int							system_command(t_ship *addr_ship, char *entry);
int							jump(t_ship *addr_ship);
int							explore(t_ship *addr_ship);
int							attack(t_ship *addr_ship);
int 						set_enemy(t_ship *addr_ship);
int							generate_enemy(t_ship *addr_ship);
int     					attack_enemy(t_ship *addr_ship);
void						random_disable(t_ship *addr_ship);
void						random_energy(t_ship *addr_ship);
int							get_stats(t_ship *addr_ship);
void						add_attack_bonus(t_ship *addr_ship, char *item);
void						add_evade_bonus(t_ship *addr_ship, char *item);
void						add_energy_bonus(t_ship *addr_ship, char *item);
void 						welcome(t_ship *p_ship);
char						*random_bonus();
int							generate_freight(t_ship *addr_ship);
char						*random_bonus();
int							win(int	sector);
int							check_ship(t_ship *addr_ship);
int							help();
int							del_freight(t_ship *addr_ship, t_freight *i);
#endif
