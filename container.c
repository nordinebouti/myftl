#include	"ftl.h"

int			add_container_to_ship(t_ship *addr_ship)
{
  my_putstr("ajout du container en cours...\n");
  addr_ship->cont = malloc(sizeof(t_container));
  if (!addr_ship->cont)
    {
      my_putstr("votre vaisseau a explose lorsque vous avez pose le container\n");
      return (0);
    }
  addr_ship->cont->first = NULL;
  addr_ship->cont->first = malloc(sizeof(t_freight));
  addr_ship->cont->last = NULL;
  addr_ship->cont->last = malloc(sizeof(t_freight));
  addr_ship->cont->nb_elem = 0;
  my_putstr("le container a ete ajoute avec succes!\n");
  return (1);
}

void			add_freight_to_container(t_ship *addr_ship, t_freight *freight)
{
  freight->next = malloc(sizeof(t_freight));
  freight->prev = malloc(sizeof(t_freight));
  if (addr_ship->cont->nb_elem == 0)
    {
      addr_ship->cont->first = freight;
      addr_ship->cont->last = freight;
      freight->prev = NULL;
      freight->next = NULL;
    }
  else
    {
      addr_ship->cont->last->next = freight;
      freight->prev = addr_ship->cont->last;
      addr_ship->cont->last = freight;
      freight->next = NULL;
    }
  ++addr_ship->cont->nb_elem;
}

int			del_from_container(t_ship *addr_ship, t_freight *freight)
{
  t_freight		*i;

  i = NULL;
  i = malloc(sizeof(t_freight));
  i = addr_ship->cont->first;

  if (i == NULL || freight == NULL)
    return (0);
  while (i != freight && i != NULL)
    i = i->next;
  if (i->next != NULL && i->prev != NULL)
    {
      i->prev->next = i->next;
      i->next->prev = i->prev;
    }
  else if (i->prev == NULL && i->next == NULL)
    {
      addr_ship->cont->first = NULL;
      addr_ship->cont->last = NULL;
    }
  else
    {
      del_freight(addr_ship, i);	
    }
  --addr_ship->cont->nb_elem;
  free(freight);
  return (1);
}

int			del_freight(t_ship *addr_ship, t_freight *i)
{
  if (i->prev == NULL)
    {
      i->next->prev = NULL;
      addr_ship->cont->first = i->next;
    }
  else if (i->next == NULL)
    {
      i->prev->next = NULL;
      addr_ship->cont->last = i->prev;
    }
  return (1);
}

int			generate_freight(t_ship *addr_ship)
{
  t_freight		*freight;
  int			random;

  freight = NULL;
  freight = malloc(sizeof(t_freight));
  random = 0;
  srand(time(NULL) * addr_ship->cont->nb_elem);
  random = ((rand()) % 100) + 1;
  if (random > 30)
    {
      freight->item = my_strdup("scrap");
    }
  else
    freight->item = my_strdup(random_bonus());
  add_freight_to_container(addr_ship, freight);
  return (0);
}
