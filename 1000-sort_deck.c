#include "deck.h"

int card_value(deck_node_t *node);
int _strcmp(const char *s1, const char *s2);
size_t list_len_deck(deck_node_t *list);

/**
 * sort_deck - Sorts a deck of cards in ascending order.
 * @deck: Pointer to the head of the deck (pointer to a pointer)
 *
 * Return: void
 */
void sort_deck(deck_node_t **deck)
{
	size_t length;
	deck_node_t *current, *one, *two, *three, *four;

	length = list_len_deck(*deck);

	if (!deck || !*deck || length < 2)
		return;

	current = *deck;
	while (current)
	{
		if (current->prev && card_value(current) < card_value(current->prev))
		{
			one = current->prev->prev;
			two = current->prev;
			three = current;
			four = current->next;

			two->next = four;
			if (four)
				four->prev = two;
			three->next = two;
			three->prev = one;
			if (one)
				one->next = three;
			else
				*deck = three;
			two->prev = three;
			current = *deck;
			continue;
		}
		else
			current = current->next;
	}
}

/**
 * card_value - Calculates the value of a card based on its face value and suit
 * @node: Pointer to the node representing the card in the deck
 *
 * Return: Integer value representing the card (face value + suit value)
 */
int card_value(deck_node_t *node)
{
	char *val[13] = {"Ace", "2", "3", "4", "5", "6",
		"7", "8", "9", "10", "Jack", "Queen", "King"};
	char *kinds[4] = {"SPADE", "HEART", "CLUB", "DIAMOND"};
	int i, kind_val = 0;

	for (i = 1; i <= 13; i++)
	{
		if (!_strcmp(node->card->value, val[i - 1]))
			kind_val = i;
	}

	for (i = 1; i <= 4; i++)
	{
		if (!_strcmp(kinds[node->card->kind], kinds[i - 1]))
			kind_val = kind_val + (13 * i);
	}

	return (kind_val);
}

/**
 * _strcmp - Compares two strings.
 *
 * @s1: Pointer to the first string to be compared
 * @s2: Pointer to the second string to be compared
 *
 * Return: Integer value representing the comparison result
 *   0: If both strings are equal
 *  <0: If the first character that does not match has a lower value in s1 than
 *      in s2
 *  >0: If the first character that does not match has a greater value in s1
 *      than in s2
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * list_len_deck - Calculates the number of nodes in a doubly linked list.
 * @list: Pointer to the head of the doubly linked list
 *
 * Return: Size_t value representing the number of nodes in the list
 */
size_t list_len_deck(deck_node_t *list)
{
	size_t len = 0;

	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}
