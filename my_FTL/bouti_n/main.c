#include "ftl.h"

int main()
{
  t_ship 		*p_ship;
  t_freight		*p_fr1;
  t_freight		*p_fr2;
  t_freight		*p_fr3;
 
  p_fr1 = malloc(sizeof(t_freight));
  p_fr2 = malloc(sizeof(t_freight));  
  p_fr3 = malloc(sizeof(t_freight));
  p_ship = create_ship();
  add_weapon_to_ship(p_ship);
  add_ftl_drive_to_ship(p_ship);
  add_navigation_tools_to_ship(p_ship);
  add_container_to_ship(p_ship);
  p_fr1->item = "attackbonus";
  p_fr2->item = "evadebonus";
  p_fr3->item = "energy";
  add_freight_to_container(p_ship, p_fr1);
  add_freight_to_container(p_ship, p_fr2);
  add_freight_to_container(p_ship, p_fr3);
  
  get_bonus(p_ship);
  my_putnbr(p_ship->weapons->damage);
  my_putnbr(p_ship->nav_tools->evade);
  my_putnbr(p_ship->ftl_drive->energy);
  system_control(p_ship);
  p_ship->nav_tools->system_state = "toz";
  p_ship->ftl_drive->system_state = "toz";
  p_ship->weapons->system_state = "toz";
  system_control(p_ship);
  ftl_drive_system_repair(p_ship);
  navigation_tools_system_repair(p_ship);
  weapon_system_repair(p_ship);
  system_control(p_ship);
  free(p_fr1);
  free(p_fr2);
  free(p_ship);
  return(0);
}