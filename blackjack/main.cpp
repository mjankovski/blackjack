#include "card.h"

string cardsOnTable[32];

int main() {
	int click = 1;
	string gamer = "";
	string croupier = "";
	int gamerSum = 0, croupierSum = 0, gamerSumTmp, croupierSumTmp;
	int error;
	int flag = 0;
	srand(time(NULL));
	Card card;
	int choice;
	gamerSum += card.randCard(gamerSum, cardsOnTable, gamer);
	error = card.randCard(gamerSum, cardsOnTable, gamer);
	while (error == -1) error = card.randCard(gamerSum, cardsOnTable, gamer);
	gamerSum += error;

	error = card.randCard(croupierSum, cardsOnTable, croupier);
	while (error == -1) error = card.randCard(croupierSum, cardsOnTable, croupier);
	croupierSum += error;
	int endSum = croupierSum;
	string krupBegin = croupier + "|X|";

	error = card.randCard(croupierSum, cardsOnTable, croupier);
	while (error == -1) error = card.randCard(croupierSum, cardsOnTable, croupier);
	croupierSum += error;
	gamerSumTmp = gamerSum;
	croupierSumTmp = croupierSum;

	while (gamerSumTmp < 21 && croupierSumTmp < 21) {
		system("cls");
		cout << "Twoja suma = " << gamerSum << endl;
		cout << "Twoje karty: \n\n" << gamer << "\n" << endl;
		int x = 16;
		while (x--)
		{
			printf("*");
		}
		printf("\n");
		if (flag == 0)
		{
			cout << "\nSuma krupiera = " << endSum << endl;
			cout << "Karty krupiera: \n\n" << krupBegin << "\n" << endl;
		}
		else
		{
			cout << "Suma krupiera = " << croupierSum << "\n" << endl;
			cout << "Karty krupiera: \n\n" << croupier << "\n" << endl;
		}
		x = 16;
		while (x--)
		{
			printf("*");
		}
		cout << "\nCo chcesz zrobic?\n1-Dobierz karte\n2-Czekaj\n" << endl;
		cin >> choice;
		
		if (choice == 1) {
			click = 1;
			error = card.randCard(gamerSum, cardsOnTable, gamer);
			while (error == -1) error = card.randCard(gamerSum, cardsOnTable, gamer);
			gamerSum += error;
			gamerSumTmp = gamerSum;
			
		}
		else if (choice == 2)
		{
			click = 0;
			flag = 1;
			while (croupierSum <= 16 || (croupierSum >= 17 && croupierSum<gamerSum))
			{
				error = card.randCard(croupierSum, cardsOnTable, croupier);
				while (error == -1) error = card.randCard(croupierSum, cardsOnTable, croupier);
				croupierSum += error;
				croupierSumTmp = croupierSum;
				
				
			}
			if (croupierSum > 17)
			{
				int decyzja = rand() % 4;
				if (decyzja == 0)
				{
					system("cls");
					cout << "Krupier podejmuje ryzyko i dobiera karte..." << endl;
					error = card.randCard(croupierSum, cardsOnTable, croupier);
					while (error == -1) error = card.randCard(croupierSum, cardsOnTable, croupier);
					croupierSum += error;
					croupierSumTmp = croupierSum;
					Sleep(1000);
				}				
			}
			if (croupierSumTmp > gamerSumTmp)gamerSumTmp = 666;
		}
		system("cls");
		
	}
	
	cout << "Twoja suma = " << gamerSum << endl;
	cout << "Twoje karty: \n\n" << gamer << "\n\n" << endl;
	cout << "Suma krupiera = " << croupierSum << endl;
	cout << "Karty krupiera: \n\n" << croupier << "\n" << endl;
	if (gamerSum == 21 || croupierSum > 21) cout << "WYGRALES!";
	else if (gamerSum == croupierSum) cout << "REMIS!";
	else cout << "PRZEGRALES!";

	getchar();
	getchar();
	return 0;
}