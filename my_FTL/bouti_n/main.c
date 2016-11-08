#include "ftl.h"

int main()
{
  t_ship *p_ship;

  p_ship = create_ship();
  p_ship->hull = 1245;
  
  return(0);
}