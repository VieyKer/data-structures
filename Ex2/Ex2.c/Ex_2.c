#include <stdlib.h>
#include "doubly_list.h"
#include "polinomial_list.h"

void Ex_2();

void main()
{
	PolynomialList *lst1 = InitPolynomialList();
	Insert(lst1, 4, 2,0);
	Insert(lst1, 6, 4,0);
	Insert(lst1, 4, 3,0);
	Insert(lst1, -4, 3,0);
	Insert(lst1, 1, 1,0);
	PrintPolList(lst1);

	PolynomialList *lst2 = InitPolynomialList();
	Insert(lst2, 5, 2,0);
	Insert(lst2, 6, 8,0);
	Insert(lst2, 4, 3,0);
	Insert(lst2, -4, 3,0);
	Insert(lst2, 1, 1,0);
	PrintPolList(lst2);

	PolynomialList *lst3 = Sum(lst1, lst2);
	//PolynomialList *lst3 = Diff(lst1, lst2);
	//PolynomialList *lst3 = Multiple(lst3, 3);
	PrintPolList(lst3);
	system("PAUSE");
}

void Ex_2()
{
	mhbhhvkjhv
}