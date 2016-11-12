#include "ftl.h"

int			main()
{
  t_ship		*p_ship;
  char			*entry;

  entry = NULL;
  p_ship = create_ship();
  welcome(p_ship);
  while ((my_strcmp(entry, "exit") != 0) && (check_ship(p_ship) == 1))
    {
      my_putstr("<-Waiting For Orders-> :");
      entry = readline();
      system_command(p_ship, entry);
    }
  free(entry);
  free(p_ship);
  my_putstr("Merci d'avoir joué !\n");
  return(0);
}

void 			welcome(t_ship *p_ship)
{
  my_putstr("Bienvenue, nous allons créer votre vaisseau\n");
  add_weapon_to_ship(p_ship);
  add_ftl_drive_to_ship(p_ship);
  add_navigation_tools_to_ship(p_ship);
  add_container_to_ship(p_ship);
  generate_enemy(p_ship);
  set_enemy(p_ship);
}
