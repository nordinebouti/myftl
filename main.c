#include "ftl.h"

int main()
{
  t_ship *p_ship;
  p_ship = create_ship();
  add_weapon_to_ship(p_ship);
  my_putstr(p_ship->weapons->system_state);
  my_putstr("\n");
  add_ftl_drive_to_ship(p_ship);
  my_putstr(p_ship->ftl_drive->system_state);
  my_putstr("\n");
  add_navigation_tools_to_ship(p_ship);
  my_putstr(p_ship->nav_tools->system_state);
  my_putstr("\n");
  add_container_to_ship(p_ship);
  return(0);
}