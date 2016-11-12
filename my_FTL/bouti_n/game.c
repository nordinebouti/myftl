#include	"ftl.h"

static const 	t_menu_command	g_menu[] =
{
	{"attack", *attack},
	{"explore", *explore},
	{"jump", *jump},
	{"get_stats", *get_stats},
	{"system_control", *system_control},
	{"repair", *system_repair},
	{"help", *help},
	{NULL, NULL}
};

int				attack(t_ship *addr_ship)
{
	if (my_strcmp(addr_ship->enemy->status, "KO") == 0)
	{
		my_putstr("Aucun vaisseau ennemi dans votre secteur\n");
		return (0);
	}
	else if (my_strcmp(addr_ship->weapons->system_state, "offline") == 0)
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
		random_energy(addr_ship);
	}
	else
		attack_enemy(addr_ship);
	return (1);
}

int				explore(t_ship *addr_ship)
{
	my_putnbr(addr_ship->cont->nb_elem);
	while (addr_ship->cont->nb_elem < 10)
		generate_freight(addr_ship);
	get_bonus(addr_ship);
	my_putnbr(addr_ship->cont->nb_elem);
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
	else if (my_strcmp(addr_ship->ftl_drive->system_state, "offline") == 0)
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
	if (my_strcmp(entry, "exit") != 0)
		my_putstr("[SYSTEM FAILURE] : commande inconnue\n");
	return (1);
}

int 	help()
{
	int i;

	my_putstr("Les commandes disponibles sont :\n");
	i = 0;
	while (g_menu[i].name != NULL)
	{
		my_putstr(" - ");
		my_putstr(g_menu[i].name);
		my_putstr("\n");
		++i;
	}
	return (0);
}