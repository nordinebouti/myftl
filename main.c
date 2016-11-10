#include "ftl.h"

int main()
{
  t_ship 		*p_ship;

  p_ship = create_ship();
  add_weapon_to_ship(p_ship);
  add_ftl_drive_to_ship(p_ship);
  add_navigation_tools_to_ship(p_ship);
  add_container_to_ship(p_ship);
  free(p_ship);
  return(0);
}