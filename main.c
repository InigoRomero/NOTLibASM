/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iromero- <iromero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 16:56:42 by estina            #+#    #+#             */
/*   Updated: 2020/01/16 16:10:58 by iromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define BGREEN	"\033[1;32m"
#define YELLOW	"\033[0;33m"
#define MAGENTA	"\033[0;36m"
#define WHITE	"\033[0m"

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

char	*ft_strcpy(char *src, char *dst);
int		ft_strlen(char *str);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_write(int fildes, const void *buf, int nbyte);
int		ft_read(int fildes, const void *buf, int nbyte);
char	*ft_strdup(const char *s1);
/*void	ft_list_push_front(t_list **begin_list, void *data);
int		ft_list_size(t_list *begin_list);
void	ft_list_sort(t_list **begin_list,int (*cmp)());*/

static void	check_strlen(char *str)
{
	int		i, j;

	printf("%s	FT:	", MAGENTA);
	printf(WHITE);
	printf("%d", (i = ft_strlen(str)));
	printf("%s	OR:	", MAGENTA);
	printf(WHITE);
	printf("%d", (j = (int)strlen(str)));
	if (i == j)
		printf("		🍏\n");
	else
		printf("		🍎\n");
}

static void	check_strcpy(char *s1, char *s2)
{
	char	*a, *b, *c, *d;

	a = strdup(s1);
	c = strdup(s1);
	b = strdup(s2);
	d = strdup(s2);
	printf("%s	FT:	", MAGENTA);
	printf(WHITE);
	printf("%s	", ft_strcpy(a, b));
	printf("%sOR:	", MAGENTA);
	printf(WHITE);
	printf("%s", strcpy(c, d));
	if (!ft_strcmp(a, c))
		printf("		🍏\n");
	else
		printf("		🍎\n");
}

static void	check_strcmp(char *s1, char *s2)
{
	int		i, j;

	printf("%s	FT:	", MAGENTA);
	printf(WHITE);
	printf("%d	", (i = ft_strcmp(s1, s2)));
	printf("%sOR:	", MAGENTA);
	printf(WHITE);
	printf("%d", (j = strcmp(s1, s2)));
	if (i == j)
		printf("		🍏\n");
	else
		printf("		🍎\n");
}

static void	check_write(char *s1)
{
	int		i, j;

	printf("%s	FT: ", MAGENTA);
	printf("%s	", WHITE);
	fflush(stdout);
	i = ft_write(1, s1, ft_strlen(s1));
	printf("	%d ", i);
	printf("%sOR:", MAGENTA);
	printf("%s	", WHITE);
	fflush(stdout);
	j = write(1, s1, strlen(s1));
	printf("	%d ", j);
	if (i == j)
		printf("	🍏\n");
	else
		printf("	🍎\n");
}

static void	check_read()
{
	int		i, j, fd;
	char	*buf;
	fd = open("text.txt", O_RDONLY);
	buf = calloc(10, 1);
	printf("%s	FT: ", MAGENTA);
	printf(WHITE);
	i = ft_read(fd, buf, 10);
	printf("%d %s", i, buf);
	printf("%s OR: ", MAGENTA);
	printf(WHITE);
	j = read(fd, buf, 10);
	printf("%d %s", j, buf);
	if (i == j)
		printf("	🍏\n");
	else
		printf("	🍎\n");
}

static void	check_strdup(char *s1)
{
	char	*a;

	a = ft_strdup(s1);
	printf("%s	FT:	", MAGENTA);
	printf(WHITE);
	printf("%s	", s1);
	printf("%sOR:	", MAGENTA);
	printf(WHITE);
	printf("%s", a);
	if (!ft_strcmp(a, s1))
		printf("		🍏\n");
	else
		printf("		🍎\n");
}
/*
static void	check_list_push_front()
{
	t_list	*lst = NULL;
	ft_list_push_front(&lst, "ARBOL");
	ft_list_push_front(&lst, "BINGO");
	ft_list_push_front(&lst, "CUCHILLO");
	printf(WHITE);
	t_list	*aux;
	int		i = 0;
	while (lst)
	{
		i++;
		printf("	%s ", lst->data);
		aux = lst;
		lst = lst->next;
		free(aux);
	}
	if (i == 3)
		printf("		🍏\n");
	else
		printf("		🍎\n");
}

static void	check_list_size()
{
	t_list	*lst = NULL;
	ft_list_push_front(&lst, "123");
	ft_list_push_front(&lst, "456");
	ft_list_push_front(&lst, "789");
	printf(WHITE);
	t_list	*aux;
	int		i = ft_list_size(lst);
	printf("	%sSIZE:	%s%d", MAGENTA, WHITE, i);
	if (i == 3)
		printf("				🍏\n");
	else
		printf("				🍎\n");
	while (lst)
	{
		aux = lst;
		lst = lst->next;
		free(aux);
	}
}
*/
int			main()
{
	printf("%s~~~~    MANDATORY PART    ~~~~\n", BGREEN);

	printf("%sFT_STRLEN:\n", YELLOW);
	check_strlen("");
	check_strlen("HOLA");
	check_strlen("H O L A");
	check_strlen("\t\t");

	printf("%sFT_STRCPY:\n", YELLOW);
	check_strcpy("", "Hola");
	check_strcpy("HOLA", "MUNDO");
	check_strcpy("H O ", "M U N ");
	check_strcpy("\t", "\a\a");

	printf("%sFT_STRCMP:\n", YELLOW);
	check_strcmp("HOMA", "HOMA");
	check_strcmp("HOLA", "MUNDO");
	check_strcmp("1 O  ", "M U N  ");
	check_strcmp("\t", "\a\a");

	printf("%sFT_WRITE:\n", YELLOW);
	check_write("HOLA");
	check_write(" \1MUNDO");
	check_write("");
	check_write("%2%");

	printf("%sFT_READ:\n", YELLOW);
	check_read();

	printf("%sFT_STRDUP:\n", YELLOW);
	check_strdup("HOLA");
	check_strdup("M\1\1M");
	check_strdup("1 O  \\");
	check_strdup("/\\\"2");

/*	printf("%s~~~~    BONUS PART    ~~~~\n", BGREEN);
	printf("%sFT_LIST_PUSH_FRONT:\n", YELLOW);
	check_list_push_front();

	printf("%sFT_LIST_SIZE:\n", YELLOW);
	check_list_size();

	printf("%sFT_LIST_SORT:\n", YELLOW);
	printf(WHITE);
	t_list	*lst = NULL;
	ft_list_push_front(&lst, "123");
	ft_list_push_front(&lst, "456");
	ft_list_push_front(&lst, "789");
	t_list	*sorted = NULL;
	ft_list_push_front(&sorted, "789");
	ft_list_push_front(&sorted, "456");
	ft_list_push_front(&sorted, "123");
	t_list *aux = lst;
	printf("	%sOR:%s	", MAGENTA, WHITE);
	while (aux)
	{
		printf("%s	", aux->data);
		aux = aux->next;
	}
	printf("\n");
	ft_list_sort(&lst, &strcmp);
	int		i = 0;
	printf("	%sSR:%s	", MAGENTA, WHITE);
	while (lst)
	{
		printf("%s	", lst->data);
		if (ft_strcmp(lst->data, sorted->data))
			i = 1;
		aux = lst;
		lst = lst->next;
		free(aux);
		aux = sorted;
		sorted = sorted->next;
		free(aux);
	}
	if (i == 0)
		printf("	🍏\n");
	else
		printf("	🍎\n");
	printf("\n");*/
	return (0);
}
