#include "card.h"

int Card::randCard(int &sumOfPoints, string *tab, string &cards) {
	number = "";
	static int i = 0;
	ostringstream ss;
	ss << rand() % 2 + 1;
	number += ss.str();
	ss.str("");
	ss << rand() % 4 + 1;
	number += ss.str();

	tmp = rand() % 13 + 1;
	if ((tmp >= 2) && (tmp <= 10)) cardValue = tmp;
	else if (tmp == 1) {
		if (sumOfPoints <= 10) cardValue = 11;
		else cardValue = 1;
	}
	else if (tmp>10) {
		cardValue = 10;
	}
	ss.str("");
	ss << tmp;
	number += ss.str();



	for (int j = 0; j < i - 1; j++) {
		if (number == *(tab + j)) return -1;
	}

	*(tab + i++) = number;

	if (number.substr(2) == "1")
	{
		cards += "|As| ";
	}
	else if (number.substr(2) == "11")
	{
		cards += "|W| ";
	}
	else if (number.substr(2) == "12")
	{
		cards += "|D| ";
	}
	else if (number.substr(2) == "13")
	{
		cards += "|K| ";
	}
	else
	{
		cards += "|";
		cards += number.substr(2);
		cards += "| ";
	}

	number = "";

	return cardValue;

}