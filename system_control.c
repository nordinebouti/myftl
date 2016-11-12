#include	"ftl.h"

void 						ftl_drive_system_check(t_ship *addr_ship)
{
	my_putstr("verification du reacteur en cours...\n");
	if (my_strcmp(addr_ship->ftl_drive->system_state, "online") == 0)
		my_putstr("reacteur OK!\n");
	else
		my_putstr("reacteur hors service!\n");
} 

void 						navigation_tools_system_check(t_ship *addr_ship)
{
	my_putstr("verification du systeme de navigation en cours...\n");
	if (my_strcmp(addr_ship->nav_tools->system_state, "online") == 0)
		my_putstr("systeme de navigation OK!\n");
	else
		my_putstr("systeme de navigation hors service!\n");
}

void						weapon_system_check(t_ship *addr_ship)
{
	my_putstr("verification du systeme d'armement en cours...\n");
	if (my_strcmp(addr_ship->weapons->system_state, "online") == 0)
		my_putstr("systeme d'armement OK!\n");
	else
		my_putstr("systeme d'armement hors service!\n");
}

int							system_control(t_ship *addr_ship)
{
	weapon_system_check(addr_ship);
	navigation_tools_system_check(addr_ship);
	weapon_system_check(addr_ship);
	return(0);
}