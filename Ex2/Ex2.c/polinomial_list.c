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
				if (!(iter->prev))//head
				{
					Polynomial *temp = lst->head;
					iter = lst->head = iter->next;
					iter->prev = NULL;
					free(temp);
				}
				
				else if (!(iter->next))//tail
				{
					Polynomial *temp = lst->tail;
					iter = lst->tail = iter->prev;
					iter->next = NULL;
					free(temp);
					return;
				}

				else
				{
					(iter->prev)->next = iter->next;
					(iter->next)->prev = iter->prev;
					free(iter);
				}

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
	PolynomialList *lst = InitPolynomialList();
	Polynomial *iter1 = p1->head;
	Polynomial *iter2 = p2->head;

	while (iter1)
	{
		Insert(lst, iter1->variable, iter1->pow);
		iter1 = iter1->next;
	}

	while (iter2)
	{
		Insert(lst, iter2->variable, iter2->pow);
		iter2 = iter2->next;
	}
		
	return lst;
}


PolynomialList *Diff(PolynomialList *p1, PolynomialList *p2)
{
	PolynomialList *lst = InitPolynomialList();
	Polynomial *iter1 = p1->head;
	Polynomial *iter2 = p2->head;

	while (iter1)
	{
		Insert(lst, iter1->variable, iter1->pow);
		iter1 = iter1->next;
	}

	while (iter2)
	{
		Insert(lst, -(iter2->variable), iter2->pow);
		iter2 = iter2->next;
	}

	return lst;
}

PolynomialList *Multiple(PolynomialList *lst, int scalar)
{
	if (scalar == 0)
		return lst = NULL;

	Polynomial *iter = lst->head;

	while (iter)
	{
		iter->variable = (iter->variable)*scalar;
		iter = iter->next;
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
			printf("(%d)x^%d", iter->variable, iter->pow);
			if (iter->next)
			{
				printf(" + ");
			}

			iter = iter->next;
		}

		printf("\n");
	}
}

PolynomialList *emptyPol(PolynomialList *list)
{
	Polynomial *head = list->head;
	
	if (head == NULL)
	{
		return list;
	}
	Polynomial *ptr = list->head->next;
	Polynomial *temp = (Polynomial*)malloc(sizeof(Polynomial));
	if (temp == NULL)
	{
		printf("Alloc failed\n");
		return list;
	}
	
	while (ptr)
	{
		temp = ptr;
		ptr = ptr->next;
		free(temp);
	}

	head = InitPolynomialList();
	head->pow = head->variable = 0;
	return head;
}
