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
  addr_ship->ftl_drive = NULL;
  my_putstr("amelioration du vaisseau termine!\n");
  return (addr_ship);
}


int                add_weapon_to_ship(t_ship *addr_ship)
{
  t_weapon         *weapon;

  my_putstr("ajout des armes en cours...\n");
  weapon = malloc(sizeof(t_weapon*));
  if (!weapon)
  {
    my_putstr("votre vaisseau a explose quand vous avez tente d'ajouter les armes\n");
    return (0);
  }
  my_putstr("ok 1");
  addr_ship->weapons = weapon;
  my_putstr("ok 1");
  addr_ship->weapons->damage = 10;
  my_putstr("ok 1");
  addr_ship->weapons->system_state = my_strdup("online");
  my_putstr("ok 1");
  my_putstr("les armes ont ete ajoutees avec succes\n");
  return (1);
}

int                add_ftl_drive_to_ship(t_ship *addr_ship)
{
  t_ftl_drive      *ftl_drive;

  my_putstr("ajout du reacteur en cours...\n");
  ftl_drive = malloc(sizeof(t_ftl_drive*));
  if (!ftl_drive)
  {
    my_putstr("votre vaisseau a explose lorsque vous avez pose le reacteur !\n");
    return(0);
  }
  addr_ship->ftl_drive = ftl_drive;
  addr_ship->ftl_drive->energy = 10;
  addr_ship->ftl_drive->system_state = my_strdup("online");
  my_putstr("Reacteur ajoute avec succes!\n");
  return(1);
}