#include	"ftl.h"

static const t_repair_command	g_repair[] =
{
	{"weapon", *weapon_system_repair},
	{"ftl_drive", *ftl_drive_system_repair},
	{"navigation_tools", *navigation_tools_system_repair},
	{NULL, NULL}
};

int 							ftl_drive_system_repair(t_ship *addr_ship)
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

int 							navigation_tools_system_repair(t_ship *addr_ship)
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
	return(0);
}

int								weapon_system_repair(t_ship *addr_ship)
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

int								system_repair(t_ship *addr_ship)
{
	char						*cmd;
	int 						i;

	cmd = NULL;
	i = 0;
	my_putstr("repair_system~>");
	cmd = readline();
	if (cmd == NULL)
	{
		my_putstr("[SYSTEM FAILURE] : le lecteur de commande est bloque\n");
		return (0);
	}
	while (g_repair[i].name != NULL)
	{
		if (my_strcmp(g_repair[i].name, cmd) == 0)
			return(g_repair[i].func(addr_ship));
		++i;
	}
	my_putstr("[SYSTEM FAILURE] : commande inconnue\n");
	return (1);
}
