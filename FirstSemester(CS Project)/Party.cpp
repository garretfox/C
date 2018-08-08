#include "stdafx.h"
#include "Party.h"
#include <iostream>
#include "Plane.h"
using namespace std;

Party::Party()
{
	Party_Size = 0;
}
Party::~Party() {
	
}

char* Party::GetPartyName()
{
	return PartyName;
}
int Party::GetPartySize()
{
	return Party_Size;
}
void Party::SetPartyName()
{
	cin >> PartyName;
}

void Party::SetPartyName(char * c) {
	PartyName = c;
}

void Party::SetPartySize(int i)
{
	Party_Size = i;
}
void Party::SetPartySize()
{
	bool valid(1);
	int i;
	cout << " **Please Enter Party's Size** " << endl
		 << "     ---MAX 40 per Party---    " << endl;
	do {
		cin >> i;
		if (i > 40) {
			valid = 0;
			cout << "Invalid Party Size" << endl;
		}
		
	} while (!valid);
}

