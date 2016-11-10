#include	"ftl.h"

int 						ftl_drive_system_repair(t_ship *addr_ship)
{
	my_putstr("reparation du reacteur en cours...\n");
	addr_ship->ftl_drive->system_state = NULL;
	free(addr_ship->ftl_drive->system_state);
	addr_ship->ftl_drive->system_state = my_strdup("online");
	if (my_strcmp(addr_ship->ftl_drive->system_state, "online") == 0)
	{
		my_putstr("reparation termine! systeme reacteur OK!\n");
		return(1);
	}
	else
		my_putstr("les reparations du reacteur ont echoue\n");
	return(0);
} 	

int 						navigation_tools_system_repair(t_ship *addr_ship)
{
	my_putstr("reparation du systeme de navigation en cours...\n");
	addr_ship->nav_tools->system_state = NULL;
	free(addr_ship->nav_tools->system_state);
	addr_ship->nav_tools->system_state = my_strdup("online");
	if (my_strcmp(addr_ship->nav_tools->system_state, "online") == 0)
	{
		my_putstr("reparation termine! systeme de navigation OK!\n");
		return(1);
	}
	else
		my_putstr("les reparations du systeme de navigation ont echoue\n");
	return(0);;
}

int							weapon_system_repair(t_ship *addr_ship)
{
	my_putstr("reparation du systeme d'armement en cours...\n");
	addr_ship->weapons->system_state = NULL;
	free(addr_ship->weapons->system_state);
	addr_ship->weapons->system_state = my_strdup("online");
	if (my_strcmp(addr_ship->weapons->system_state, "online") == 0)
	{
		my_putstr("reparation termine! systeme d'armement OK!\n");
		return(1);
	}
	else
		my_putstr("les reparations du systeme d'armement ont echoue\n");
	return(0);
}