#include <stdlib.h>
#include <stdio.h>
#include "polinomial_list.h"

PolynomialList *InitPolynomialList()
{
	PolynomialList *lst = (PolynomialList *)malloc(sizeof(PolynomialList));
	Polynomial *plm = (Polynomial *)malloc(sizeof(Polynomial));

	lst->head = lst->tail = NULL;
	return lst;
}

void Insert(PolynomialList *lst, int variable, int pow)
{
	Polynomial *plm = (Polynomial*)malloc(sizeof(Polynomial));
	plm->next = plm->prev = NULL;
	plm->pow = pow;
	plm->variable = variable;
	Polynomial *iter = lst->head;

	if (!lst->head)
	{
		lst->head = lst->tail = plm;
		return;
	}

	if (plm->pow < iter->pow)//if plm needs to be placed as head
	{
		Polynomial *temp = lst->head;
		lst->head = plm;
		plm->next = temp;
		temp->prev = plm;
		return;
	}

	while (iter)//if plm needs to be placed at the middle of the list
	{
		if (plm->pow == iter->pow)
		{
			if ((plm->variable + iter->variable) == 0)
			{
				(iter->prev)->next = iter->next;	
				(iter->next)->prev = iter->prev;
				free(iter);
				return;
			}

			iter->variable += plm->variable;
			return;
		}

		if ((plm->pow < iter->pow))
		{
			Polynomial *temp = iter->prev;
			(iter->prev) = plm;
			temp->next = plm;
			plm->prev = temp;
			plm->next = iter;
			return;	
		}

		if (!iter->next)//if plm needs to be placed as tail
		{
			plm->prev = iter;
			iter->next = plm;
			lst->tail = plm;
			return;
		}

		iter = iter->next;
	}
}


PolynomialList *Sum(PolynomialList *p1, PolynomialList *p2)
{
	Polynomial *iter1 = p1->head;
	Polynomial *iter2 = p2->head;

	if (iter1->pow > iter2->pow)
	{
		Insert(p1, iter2->variable, iter2->pow);
		return;
	}

	while (iter1)
	{
		if (iter1->pow == iter2->pow)
		{
			iter1->variable += iter2->variable;
			return;
		}
		
		if (!iter1)
		{
			Insert(p1, iter2->variable, iter2->pow);
		}

		iter1 = iter1->next;
	}
}


PolynomialList *Diff(PolynomialList *p1, PolynomialList *p2)
{
	Polynomial *iter1 = p1->head;
	Polynomial *iter2 = p2->head;

	if (iter1->pow > iter2->pow)
	{
		iter2->variable = 0 - iter2->variable;
		Insert(p1, iter2->variable, iter2->pow);
		return;
	}

	while (iter1->next)
	{
		if (iter1->pow == iter2->pow)
		{
			iter1->variable -= iter2->variable;
			return;
		}

		iter1 = iter1->next;
	}
	
	iter2->variable = 0 - iter2->variable;
	Insert(p1, iter2->variable, iter2->pow);
}

PolynomialList *Multiple(PolynomialList *lst, int scalar)
{
	if (scalar == 0)
		return lst = NULL;

	Polynomial *iter = lst->head;

	while (iter)
	{
		iter->variable = (iter->variable)*scalar;
	}

	return lst;
}

void PrintPolList(PolynomialList *lst)
{
	if (!lst->head)
	{
		printf("0");
	}

	else
	{
		Polynomial *iter = lst->head;

		while (iter)
		{
			printf("%dx^%d", iter->variable, iter->pow);
			if (iter->next)
			{
				printf("+");
			}

			iter = iter->next;
		}

		printf("\n");
	}
}