#include	"ftl.h"

static const 	t_menu_command	g_menu[] =
{
	{"attack", *attack},
	{"detect", *detect},
	{"jump", *jump},
	{"get_bonus", *get_bonus},
	{NULL, NULL}
};

int				attack(t_ship addr_ship)
{
	return (0);
}

int				detect(t_ship addr_ship)
{
	return (0);
}

int				jump(t_ship addr_ship)
{
	return (0);
}

int				system_command(t_ship *addr_ship, char *entry)
{
	int 		i;

	i = 0;
	if (entry == NULL)
	{
		my_putstr("[SYSTEM FAILURE] : le lecteur de commande est bloque\n");
		return (0);
	}
	while (g_menu[i].name != NULL)
	{
		if (my_strcmp(g_menu[i].name, entry) == 0)
			return(g_menu[i].func(addr_ship));
		++i;
	}
	my_putstr("[SYSTEM FAILURE] : commande inconnue\n");
	return (1);
}