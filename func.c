#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Header.h"
#include <stdlib.h>	
#include <string.h>
#define A 100


int check_string(char *str) {



	for (int i = 0; i < strlen(str) - 1; i++) {

		if (!(str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z' || str[i] == ' ' || str[i] == '\n'))
		{

			printf("Entered unacceptable string.Try again.\n");

			system("pause");

			return -1;

		}

	}
	if (str[strlen(str) - 1] != '.')

	{

		printf("Entered unacceptable string.At the end of the string must be point.Try again.\n");

		system("pause");

		return -1;

	}



	return 0;
}

list *create_head(char *field) {

	list *head;

	head = (struct list*)malloc(sizeof(struct list));  		// выделение памяти под корень списка

	head->field = field;

	head->next = NULL; // указатель на следующий узел

	head->prev = NULL; // указатель на предыдущий узел

	return head;
}


list * add_elem(list *lst, char *s)
{
	list *temp, *p;
	temp = (struct list*)malloc(sizeof(list));
	p = lst->next; // сохранение указателя на следующий узел
	lst->next = temp; // предыдущий узел указывает на создаваемый
	temp->field = s; // сохранение поля данных добавляемого узла
	temp->next = p; // созданный узел указывает на следующий узел
	temp->prev = lst; // созданный узел указывает на предыдущий узел
	if (p != NULL)
		p->prev = temp;
	return temp;
}

void print_list(list *head) {

	list *p;
	p = head;
	do {
		printf("%s\n", p->field); // вывод значения элемента p
		p = p->next; // переход к следующему узлу
	} while (p != NULL); // условие окончания обхода
}


char *search_max(list *head, char *max) {

	list *p;
	p = head;
	do {
		if (strcmp(max, p->field) > 0)
			strcpy(max, p->field);
		p = p->next; // переход к следующему узлу
	} while (p != NULL); // условие окончания обхода

	return max;

}

list *delete_elem(list *lst) {

	list *prev, *next;
	prev = lst->prev; // узел, предшествующий lst
	next = lst->next; // узел, следующий за lst
	if (prev != NULL)
		prev->next = lst->next; // переставляем указатель
	if (next != NULL)
		next->prev = lst->prev; // переставляем указатель
	free(lst); // освобождаем память удаляемого элемента
	return(prev);

}


list *delete_head(list *head) {

	struct list *temp;
	temp = head->next;	
	if (head->next == NULL) {
		printf("All items of the list were the same and were deleted.\n");
		system("pause");
		exit(0);
	}
	temp->prev = NULL;
	free(head);   // освобождение памяти текущего корня
	return(temp); // новый корень списка
}


list *delete_equal(list *head, char *max) {

	list *p, *new = NULL;
	p = head;
	do {
		if (p == NULL)
			break;

		if (strcmp(max, p->field) == 0) {
			if (p->prev == NULL) {
				p = delete_head(p);
				new = p;
			}
			else 
				p = delete_elem(p);
				

		}

		else 
			p = p->next; // переход к следующему узлу
		
	} while (p != NULL); // условие окончания обхода


	return new;
}


void print_back(list *lst) {


	
		list *p;
		p = lst;
		while (p->next != NULL)
			p = p->next;  // переход к концу списка
		do {
			printf("%s\n", p->field); // вывод значения элемента p
			p = p->prev; // переход к предыдущему узлу
		} while (p != NULL); // условие окончания обхода
	
}
