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
  addr_ship->enemy->life = 0;
  addr_ship->enemy->damage = 0;
  addr_ship->enemy->lvl = 0;
  addr_ship->enemy->status = NULL;
  addr_ship->enemy->status = my_strdup("KO");
  my_putstr("Les rebelles sont en place!\n");
  return (1);
}

int 		set_enemy(t_ship *addr_ship)
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
      addr_ship->enemy->damage = 10 + (addr_ship->enemy->lvl * 5);
      my_putstr("Vaisseau rebel dans votre secteur !\n");
    }
  return (0);
}

int     attack_enemy(t_ship *addr_ship)
{
  int   random;

  if (my_strcmp(addr_ship->enemy->status, "OK") != 0)
    return (0);
  random = 0;
  srand(time(NULL));
  random = (rand() % 100) + 1;
  if (random > addr_ship->nav_tools->evade)
  {
    addr_ship->health -= addr_ship->enemy->damage;
    my_putstr("Un vaisseau ennemi vous attaque\n");
    random_disable(addr_ship);
    my_putstr("et vous enlève ");
    my_putnbr(addr_ship->enemy->damage);
    my_putstr(" points de vie.\n");
    random_disable(addr_ship);
    return (1);
  }
  else
  {
    my_putstr("Vous avez evite une attaque ennemi !\n");
    return (1);
  }
}

void    random_disable(t_ship *addr_ship)
{
  int random;

  random = 0;
  srand(time(NULL));
  random = (rand() % 10) + 1;
  if (random == 1)
  {
    addr_ship->nav_tools->system_state = NULL;
    free(addr_ship->nav_tools->system_state);
    addr_ship->nav_tools->system_state = my_strdup("offline");
    my_putstr("Outils de navigation H.S\n");
  }
  else if (random == 2)
  {
    addr_ship->weapons->system_state = NULL;
    free(addr_ship->weapons->system_state);
    addr_ship->weapons->system_state = my_strdup("offline");
    my_putstr("Système d'armement H.S\n");
  }
}

void      random_energy(t_ship *addr_ship)
{
  int   random;
  
  random = 0;
  srand(time(NULL));
  random = (rand() % 2);
  if (random == 1)
    {
      --addr_ship->ftl_drive->energy;
      my_putstr("Ce combat vous a couté 1 energie\n");
    }
}