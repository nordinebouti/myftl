#include "ftl.h"

int 			main()
{
  t_ship 		*p_ship;
  char			*entry;

  entry = NULL;
  p_ship = create_ship();
  my_putstr("Bienvenue, nous allons créer votre vaisseau\n");
  add_weapon_to_ship(p_ship);
  add_ftl_drive_to_ship(p_ship);
  add_navigation_tools_to_ship(p_ship);
  add_container_to_ship(p_ship);
  generate_enemy(p_ship);
  my_putstr("<-Waiting For Orders-> :");
  entry = readline();
  while (my_strcmp(entry, "exit") != 0)
  {
  	system_command(p_ship, entry);
  	free(entry);
  	my_putstr("<-Waiting For Orders-> :");
  	entry = readline();
  }
  free(p_ship);
  return(0);
}