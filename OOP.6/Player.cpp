#include<iostream>
#include<vector>
#include<ostream>
using namespace std;
#define face_down "Face of the card is down"
#define face_up "Face of the card is up"

class Card {

private:
	bool positC; //position of the card

public:
	
	enum suit { spades, hearts, diamonds, clubs };
	enum valueC { Ace = 1, Two = 2, Three = 3, Four = 4, Five = 5, Six = 6, Seven = 7, Eight = 8, Nine = 9, Ten = 10, Jack = 11, Queen = 12, King = 13 };
	int flip() {
		if (positC)
			cout << face_down << endl;
		return 0;

		if (!positC)
			cout << face_up << endl;
		return 1;
	}

	int get_valueC()
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

class Hand {
protected:

	vector<Card*> Han{};

public:
	Hand();
	virtual ~Hand();
	
	void add(Card* newCard)
	{
		Han.push_back(newCard);
	}

	void Clear()
	{
		vector<Card*>::iterator iter = Han.begin();
		for (iter = Han.begin(); iter != Han.end(); ++iter)
		{
			delete* iter;
			*iter = 0;
		}
		Han.clear();
	}

	int GetValue() const
	{
		if (Han.empty())
			return 0;

		if (Han[0]->get_valueC() == 0)
			return 0;

		int totalV = 0;

		vector<Card*>::const_iterator iter;
		for (iter = Han.begin();iter !=Han.end(); iter++)
		{
			totalV += (*iter)->get_valueC();
		}
		
		bool containsAce = false;
		for (iter = Han.begin(); iter != Han.end(); ++iter)
		{
			if ((*iter)->get_valueC() == Card::Ace)
				containsAce = true;
		}
		
		if (containsAce && totalV <= 11)
		{
			totalV += 10;
		}
		
		return totalV;
	}


};

class GenericPlayer : public Hand
{
	friend ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);

public:
	GenericPlayer(const string& name = "");

	virtual ~GenericPlayer();


	virtual bool IsHitting() const = 0;


	bool IsBusted() const;


	void Bust() const;

protected:
	string name;
};

GenericPlayer::GenericPlayer(const string& m_name) :
	name(m_name)
{}
GenericPlayer::~GenericPlayer()
{}

bool GenericPlayer::IsBusted() const
{
	return (GetValue() > 21);
}

void GenericPlayer::Bust() const
{
	cout << name << " busts.\n";
}

ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer)
{
	os << aGenericPlayer.name << ":\t";

	vector<Card*>::const_iterator pCard;
	if (!aGenericPlayer.Han.empty())
	{
		for (pCard = aGenericPlayer.Han.begin();
			pCard != aGenericPlayer.Han.end();
			++pCard)
		{
			os << *(*pCard) << "\t";
		}


		if (aGenericPlayer.GetValue() != 0)
		{
			cout << "(" << aGenericPlayer.GetValue() << ")";
		}
	}
	else
	{
		os << "<empty>";
	}

	return os;
}

class Player : public GenericPlayer
{
public:
	Player(const string& name = "");

	virtual ~Player();

	virtual bool IsHitting() const;

	void Win() const;

	void Lose() const;

	void Push() const;
};

bool Player::IsHitting() const
{
	cout << name << ", do you want a hit? (Y/N): ";
	char response;
	cin >> response;
	return (response == 'y' || response == 'Y');
}
void Player::Win() const
{
	cout << name << " wins.\n";
}

void Player::Lose() const
{
	cout << name << " loses.\n";
}

void Player::Push() const
{
	cout << name << " pushes.\n";
}
class House : public GenericPlayer
{
public:
	House(const string& name = "House");

	virtual ~House();
	
	virtual bool IsHitting() const;

	void FlipFirstCard();
};
bool House::IsHitting() const
{
	return (GetValue() <= 16);
}
bool House::IsHitting() const
{
	return (GetValue() <= 16);
}
void House::FlipFirstCard()
{
	if (!(Han.empty()))
	{
		Han[0]->flip();
	}
	else
	{
		cout << "No card to flip!\n";
	}
}

int main_cards()
{

	return 0;
}