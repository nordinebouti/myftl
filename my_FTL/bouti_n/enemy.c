#include	"ftl.h"

int     generate_enemy(t_ship *addr_ship)
{
  my_putstr("ajout des ennemis en cours...\n");
  addr_ship->enemy = malloc(sizeof(t_enemy));
  if (addr_ship->enemy == NULL)
    {
      my_putstr("Vaisseaux ennemis disparus !\n");
      return (0);
    }
  addr_ship->enemy->life = 20;
  addr_ship->enemy->damage = 10;
  addr_ship->enemy->lvl = 0;
  addr_ship->enemy->status = NULL;
  addr_ship->enemy->status = my_strdup("KO");
  my_putstr("Les rebelles sont en place!\n");
  return (1);
}

int 		detect_enemy(t_ship *addr_ship)
{
  int		random;
  
  random = 0;
  srand(time(NULL));
  random = (rand() % 100) + 1;
  if (random <= 30)
    {
      free(addr_ship->enemy->status);
      addr_ship->enemy->status = my_strdup("OK");
      addr_ship->enemy->life = 20 + (addr_ship->enemy->lvl * 10);
      addr_ship->enemy->life = 10 + (addr_ship->enemy->lvl * 5);
      my_putstr("Vaisseau rebel dans votre secteur !\n");
    }
  return (0);
}

int     attack_enemy(t_ship *addr_ship)
{
  int   random;

  if (my_strcmp(addr_ship->enemy->status, "OK") == 0)
  { 
    random = 0;
    srand(time(NULL));
    random = (rand() % 100) + 1;
    addr_ship->life -= addr_ship->enemy->damage;
}
