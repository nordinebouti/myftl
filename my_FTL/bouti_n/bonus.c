#include "ftl.h"

void		add_attack_bonus(t_ship *addr_ship, char *item)
{
  if (my_strcmp(item,"attackbonus") == 0)
    {
      addr_ship->weapons->damage += 5;
      my_putstr("- Une cache d'arme : dégats d'attaque +5\n");
    }
}

void		add_evade_bonus(t_ship *addr_ship, char *item)
{
	
  if (my_strcmp(item,"evadebonus") == 0)
    {
      addr_ship->nav_tools->evade += 3;
      my_putstr("- Une amélioration des leurres : esquive +3\n");
    }
}

void		add_energy_bonus(t_ship *addr_ship, char *item)
{
  if (my_strcmp(item,"energybonus") == 0)
    {
      addr_ship->ftl_drive->energy += 1;
      my_putstr("- Une réserve de deutérium : énergie +1\n");
    }
}

char		*random_bonus()
{
  int		random;

  random = 0;
  srand(time(NULL));
  random = (rand() % 100) + 1;
  if (random < 33)
    return ("attackbonus");
  else if (random >= 33 && random < 66)
    return ("evadebonus");
  else
    return ("energybonus");

}

int		get_bonus(t_ship *addr_ship)
{
  t_freight	*i;

  i = addr_ship->cont->first;
  if (i == NULL)
    return (0);
  my_putstr("Vous explorez les environs et découvrez :\n");
  while (addr_ship->cont->nb_elem != 0)
    {
      del_from_container(addr_ship, i->prev);
      add_attack_bonus(addr_ship, i->item);
      add_evade_bonus(addr_ship, i->item);
      add_energy_bonus(addr_ship, i->item);
      if (i->next == NULL)
	{
	  del_from_container(addr_ship, i);
	  return (1);
	}
      i = i->next;
    }
  return (1);
}

