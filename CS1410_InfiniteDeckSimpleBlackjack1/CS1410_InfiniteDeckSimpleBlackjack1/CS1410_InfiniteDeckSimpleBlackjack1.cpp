#include <iostream>
#include <string>
using namespace std;
// Enumeration and Structures
enum Suit {HEARTS, DIAMONDS, CLUBS, SPADES};

struct Card {
	int value;
	Suit suit;
};
// Functions with Structures
Card GetRandomCard();
void ShowCard(Card card);
void DealCardAndTotalPlayer(int, int);
void DealCardAndTotalDealer(int, int);

Card card, player1, player2, dealer1, dealer2;
int acecount = 0;
int playertotal = 0;
int dealertotal = 0;
char choice = 'C';

int main()
{
	// Game Logic
	for (int i = 0; i < 16; i++) {
		Card card = GetRandomCard();
		ShowCard(card);
	}

	// Dealer Actions
	cout << "Dealer: ";
	DealCardAndTotalDealer(acecount, dealertotal);
	DealCardAndTotalDealer(acecount, dealertotal);
	cout << "[?]" << endl << endl;

	// Player Actions
	cout << "Player: ";
	DealCardAndTotalPlayer(acecount, playertotal);
	DealCardAndTotalPlayer(acecount, playertotal);
	cout << "Total: " << playertotal << endl << endl;

	while (playertotal < 22 && toupper(choice) != 'S') {
		cout << "(H)it or (S)tand?";
		cin >> choice;
		if (toupper(choice) == 'H') {
			DealCardAndTotalPlayer(acecount, playertotal);
			cout << "Total: " << playertotal << endl << endl;
			choice = 'C';
		}
	}
	
	if (playertotal > 21) {
		cout << "Player BUST!";
	}
	
	cout << "Total: ";
	while (dealertotal < 17) {
		DealCardAndTotalDealer(acecount, dealertotal);
		cout << dealertotal;
	}

	if (dealertotal > 21) {
		cout << "Dealer BUST!";
	}
	else if (playertotal > dealertotal) {
		cout << "Player WINS!";
	}
	else if (dealertotal > playertotal) {
		cout << "Player LOST!";
	}
	else {
		cout << "PUSH!";
	}
}

Card GetRandomCard() { // Function for generating cards in the deck
	Card card;
	card.value = rand() % 13 + 2;
	int group = rand() % 4 + 0;
	switch (group) {
	case 0:
		card.suit = HEARTS;
		return card;
		break;
	case 1:
		card.suit = DIAMONDS;
		return card;
		break;
	case 2:
		card.suit = CLUBS;
		return card;
		break;
	case 3:
		card.suit = SPADES;
		return card;
		break;
	}
}

void ShowCard(Card card) { // Function for displaying a card
	switch (card.value) { // Displays the Value of the card
	case 2:
		cout << "[2";
		break;
	case 3:
		cout << "[3";
		break;
	case 4:
		cout << "[4";
		break;
	case 5:
		cout << "[5";
		break;
	case 6:
		cout << "[6";
		break;
	case 7:
		cout << "[7";
		break;
	case 8:
		cout << "[8";
		break;
	case 9:
		cout << "[9";
		break;
	case 10:
		cout << "[10";
		break;
	case 11:
		cout << "[J";
		break;
	case 12:
		cout << "[Q";
		break;
	case 13:
		cout << "[K";
		break;
	case 14:
		cout << "[A";
		break;
	}
	switch (card.suit) { // Displays the Suit of the card
	case 0:
		cout << char(3) << "]";
		break;
	case 1:
		cout << char(4) << "]";
		break;
	case 2:
		cout << char(5) << "]";
		break;
	case 3:
		cout << char(6) << "]";
		break;
	}
}

void DealCardAndTotalPlayer(int acecount, int playertotal) { // Function for tracking totals used for game logic
	Card card = GetRandomCard();
	ShowCard(card);
	if (card.value == 14) {
		acecount++;
		playertotal += 11;
	}
	else if (card.value > 10) {
		playertotal += 10;
	}
	else {
		playertotal += card.value;
	}
	while (acecount > 0 && playertotal > 21) {
		acecount -= 1;
		playertotal -= 10;
	}
}

void DealCardAndTotalDealer(int acecount, int dealertotal) { // Function for tracking totals used for game logic
	Card card = GetRandomCard();
	ShowCard(card);
	if (card.value == 14) {
		acecount++;
		dealertotal += 11;
	}
	else if (card.value > 10) {
		dealertotal += 10;
	}
	else {
		dealertotal += card.value;
	}
	while (acecount > 0 && dealertotal > 21) {
		acecount -= 1;
		dealertotal -= 10;
	}
}