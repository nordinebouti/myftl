#include	"ftl.h"

static const 	t_menu_command	g_menu[] =
{
	{"attack", *attack},
	{"detect", *detect},
	{"jump", *jump},
	{"get_bonus", *get_bonus},
	{"repair", *system_repair},
	{NULL, NULL}
};

int				attack(t_ship *addr_ship)
{
	if (my_strcmp(addr_ship->enemy->status, "KO") == 0)
	{
		my_putstr("Aucun vaisseau ennemi dans votre secteur\n");
		return (0);
	}
	else if (my_strcmp(addr_ship->weapons->status, "offline") == 0)
	{
		my_putstr("[FATAL ERROR]Armement du vaisseau H.S.\n");
		return (0);
	}
	addr_ship->enemy->life -= addr_ship->weapons->damage;
	my_putstr("Vous avez attaqué les rebels ennemis !\n");
	if (addr_ship->enemy->life <= 0)
	{
		free(addr_ship->enemy->status);
		addr_ship->enemy->status = my_strdup("KO");
		++addr_ship->enemy->lvl;
		my_putstr("Vous avez détruit le vaisseau ennemi du secteur !\n");
	}
	return (1);
}

int				detect(t_ship *addr_ship)
{
	my_putstr(addr_ship->ftl_drive->system_state);
	return (1);
}

int				jump(t_ship *addr_ship)
{
	if (my_strcmp(addr_ship->enemy->status, "OK") == 0)
	{
		my_putstr("Impossible de changer de secteur,");
		my_putstr("les rebels vous en empêche !\n");
		return (0);
	}
	else if (my_strcmp(addr_ship->ftl_drive->status, "offline") == 0)
	{
		my_putstr("[FATAL ERROR]Moteur du vaisseau H.S.\n");
		return (0);
	}
	++addr_ship->nav_tools->sector;
	--addr_ship->ftl_drive->energy;
	my_putstr("Vous venez d'entre dans le secteur ");
	my_putnbr(addr_ship->nav_tools->sector);
	my_putstr(" !\n");
	detect_enemy(addr_ship);
	return (1);
}

int				system_command(t_ship *addr_ship, char *entry)
{
	int 		i;

	i = 0;
	if (entry == NULL)
	{
		my_putstr("[SYSTEM FAILURE] : le lecteur de commande est bloque\n");
		return (0);
	}
	while (g_menu[i].name != NULL)
	{
		if (my_strcmp(g_menu[i].name, entry) == 0)
			return(g_menu[i].func(addr_ship));
		++i;
	}
	my_putstr("[SYSTEM FAILURE] : commande inconnue\n");
	return (1);
}