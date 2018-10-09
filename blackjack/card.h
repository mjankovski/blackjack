#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <ctime>
#include <windows.h>


using namespace std;

class Card {
public:
	int randCard(int &sumOfPoints, string *tab, string &cards);

private:
	string number;
	int tmp;
	int cardValue;
};