#include "ftl.h"

int main()
{
  t_ship 		*p_ship;
  t_freight		*p_fr1;
  t_freight		*p_fr2;
  t_freight		*p_fr3;
  t_freight 	*test;

  test = NULL;
  p_fr1 = malloc(sizeof(t_freight));
  p_fr2 = malloc(sizeof(t_freight));  
  p_fr3 = malloc(sizeof(t_freight));
  p_ship = create_ship();
  add_weapon_to_ship(p_ship);
  add_ftl_drive_to_ship(p_ship);
  add_navigation_tools_to_ship(p_ship);
  add_container_to_ship(p_ship);
  p_fr1->item = "p_fr1";
  p_fr2->item = "p_fr2";
  p_fr3->item = "p_fr3";
  add_freight_to_container(p_ship, p_fr1);
  add_freight_to_container(p_ship, p_fr2);
  add_freight_to_container(p_ship, p_fr3);
  del_from_to_container(p_ship, p_fr3);
  test = p_ship->cont->last;
  while (test != NULL)
  {
  	my_putstr(test->item);
  	my_putstr("\n");
  	test = test->prev;
  }
  
  free(p_fr1);
  free(p_fr2);
  free(p_ship);
  return(0);
}