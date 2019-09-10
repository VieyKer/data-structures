typedef int list_type1;

typedef struct polynomial {
	struct polynomial *next;
	struct polynomial *prev;
	list_type1 variable;
	list_type1 pow;
}Polynomial;

typedef struct polynomialList
{
	Polynomial *head;
	Polynomial *tail;
}PolynomialList;

PolynomialList *InitPolynomialList();

void Insert(PolynomialList *lst, int variable, int pow);

PolynomialList *Sum(PolynomialList *p1, PolynomialList *p2);

PolynomialList *Diff(PolynomialList *lst1, PolynomialList *lst2);

PolynomialList *Multiple(PolynomialList *lst, int scalar);

PolynomialList *emptyPol(PolynomialList *list);

void PrintPolList(PolynomialList *lst);
