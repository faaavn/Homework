#include <iostream>
using namespace std;
#define face_down "Face of the card is down"
#define face_up "Face of the card is up"

class Card {

private:
	enum suit{spades,hearts,diamonds,clubs};
	enum valueC { Ace = 1, Two = 2, Three = 3, Four = 4, Five = 5, Six = 6, Seven = 7, Eight = 8, Nine = 9, Ten = 10, Jack = 11, Queen = 12, King = 13 };
	bool positC; //position of the card

public:
	
	int flip() {
		if (positC)
			cout << face_down << endl;
			return 0;
		
		if (!positC)
			cout << face_up << endl;
			return 1;
	}

	int get_ValueC()
	{
		valueC chosen_value;
		
		switch (chosen_value)
		{
		case Ace:
			return 1;
		case Two:
			return 2;
		case Three:
			return 3;
		case Four:
			return 4;
		case Five:
			return 5;
		case Six:
			return 6;
		case Seven:
			return 7;
		case Eight:
			return 8;
		case Nine:
			return 9;
		case Ten:
			return 10;
		case Jack:
			return 11;
		case Queen:
			return 12;
		case King:
			return 13;
		}
	}

};

int main_cards()
{

	return 0;
}