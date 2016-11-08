#include "ftl.h"

t_ship	*create_ship()
{
  t_ship *addr_ship;
  t_ship ship;

  my_putstr("construction du vaisseau en cours...\n");
  addr_ship = malloc(sizeof(t_ship*));
  if (!addr_ship)
    {
      my_putstr("le vaisseau n'a pas pu etre construit par manque de materiaux\n");
      return(addr_ship);
    }
  addr_ship = &ship;
  addr_ship->hull = 50;
  my_putstr("amelioration du vaisseau termine!\n");
  return (addr_ship);
}
