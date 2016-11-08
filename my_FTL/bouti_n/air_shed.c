#include "ftl.h"

t_ship	           *create_ship()
{
  t_ship           *addr_ship;
  t_ship           ship;

  my_putstr("construction du vaisseau en cours...\n");
  addr_ship = malloc(sizeof(t_ship*));
  if (!addr_ship)
    {
      my_putstr("le vaisseau n'a pas pu etre construit par manque de materiaux\n");
      return(addr_ship);
    }
  addr_ship = &ship;
  addr_ship->hull = 50;
  addr_ship->weapons = NULL; 
  my_putstr("amelioration du vaisseau termine!\n");
  return (addr_ship);
}


int                add_weapon_to_ship(t_ship *addr_ship)
{
  t_weapon         weapon;

  my_putstr("ajout des armes en cours...\n");
  weapon.damage = 10;
  weapon.system_state = my_strdup("online");
  addr_ship->weapons = &weapon;
  if (!addr_ship->weapons)
  {
    my_putstr("votre vaisseau a explose quand vous avez tente d'ajouter les armes\n");
    return (0);
  }
  my_putstr("les armes ont ete ajoutees avec succes\n");
  return (1);
}