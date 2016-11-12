#include "ftl.h"

int		check_ship(t_ship	*addr_ship)
{
	if (addr_ship->health <= 0)
	{
		my_putstr("Vous êtes mort !\n");
		return (0);
	}
	else if (addr_ship->ftl_drive->energy <= 0 && addr_ship->nav_tools->sector < 10)
	{
		my_putstr("Vous êtes à court d'énergie !\n");
		return (0);
	}
	else
		return win(addr_ship->nav_tools->sector);
}

int		get_stats(t_ship *addr_ship)
{
		my_putstr("Santé du vaisseau : ");
		my_putnbr(addr_ship->health);
		my_putstr("\nDégats d'attaque : ");
		my_putnbr(addr_ship->weapons->damage);
		my_putstr("\nChance d'esquive (en %) : ");
		my_putnbr(addr_ship->nav_tools->evade);
		my_putstr("\n");
		return (1);
}

int		win(int	sector)
{
	if (sector == 10)
	{
		my_putstr("Vous avez gagné !\n");
		return (0);
	}
	return (1);
}