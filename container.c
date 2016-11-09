#include	"ftl.h"

int						  	add_container_to_ship(t_ship *addr_ship)
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

void						add_freight_to_container(t_ship *addr_ship, t_freight *freight)
{
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
	}
	++addr_ship->cont->nb_elem;
}

void						del_from_to_container(t_ship *addr_ship, t_freight *freight)
{
	t_freight				*i;
	i = NULL;
	i = malloc(sizeof(t_freight));

	i = addr_ship->cont->first;
	while (i != freight)
		i = i->next;
	if (i != NULL)
	{
		if (i->next != NULL && i->prev != NULL)
		{
			i->prev->next = i->next;
			i->next->prev = i->prev;
		}
		else if (i->prev == NULL)
		{
			i->next->prev = NULL;
			addr_ship->cont->first = i->next;
		}
		else
		{
			i->prev->next = NULL;
			addr_ship->cont->last = i->prev;
		}
		free(freight);
	}
}

void						get_bonus(t_ship *addr_ship)
{
	t_freight				*i;

	i = addr_ship->cont->first;
	while (i != NULL)
	{
		if (my_strcmp(i->item,"attackbonus") == 0)
			addr_ship->weapons->damage += 5;
		else if (my_strcmp(i->item,"evadebonus") == 0)
			addr_ship->nav_tools->evade += 3;
		else if (my_strcmp(i->item,"energy") == 0)
			addr_ship->ftl_drive->energy += 1;
		i = i->next;
	}
	free(i);
}