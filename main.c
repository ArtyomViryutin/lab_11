#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Header.h"
#include <stdlib.h>	
#include <string.h>
#define A 100


int main() {

	char str[A];

	list *head = NULL, *temp,*new;

	char *s;

	printf("Enter a string(words are separated by spaces, at the end - point:\n");


	gets(str);

	while (check_string(str) == -1) {

		system("cls");

		printf("Enter a string(words are separated by spaces, at the end - point:\n");

		gets(str);
	}

	char sep[] = { ' ','.' };

	s = strtok(str, sep);

	head = create_head(s);

	temp = head;

	char *max = malloc(sizeof(char)*strlen(head->field));

	strcpy(max, head->field);

	// Выделение последующих частей

	while (s != NULL)
	{


		s = strtok(NULL, sep);       // Выделение очередной части строки

		if (s == NULL)
			break;

		temp = add_elem(temp, s);

	}

	print_list(head);

	max = search_max(head, max);

	printf("List!! after modification:\n");

	new=delete_equal(head, max);

	if (new != NULL)
		head = new;

	if (strcmp(max, head->field) == 0) {
		printf("All items of the list were the same and were deleted.\n")
			free(head);
	}


	else 
		print_list(head);


	system("pause");

	free(max);

	return 0;










}
