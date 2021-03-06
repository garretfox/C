// FoxAirlines.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Party.h"
#include "Plane.h"
#include <iostream>
#include <string> 

using namespace std;

void DepartPlane();
void CreateNewParty();
void FillFromLounge();

bool Exit(0);

Plane   ALFA("Alfa");
Plane  BRAVO("Bravo");
Plane LOUNGE("Lounge");

void main()
{
	
	cout << "______________________________" << endl
		<< " Welcome to Tree Top Airways! " << endl
		<< ".-.-.-.-.-.-.-.-.-.-.-.-.-.-.-" << endl;

	cout << endl;
	cout << ".-.-.-.-.-.-.-.-.-.-.-.-.-.-.-" << endl;
	cout << endl;
	cout << "PLEASE SET UP SEATING CAPACITIES" << endl;
	cout << endl;
	cout << ".-.-.-.-.-.-.-.-.-.-.-.-.-.-.-" << endl;
	cout << endl;
	
	
		ALFA.SetSeatNumber();
		BRAVO.SetSeatNumber();
		LOUNGE.SetSeatNumber();
	
	
	
		do {
			cout << "       .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-        " << endl
				<< "------------------MAIN MENU------------------" << endl
				<< "       .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-        " << endl
				<< endl;
			cout << "COMMANDS" << endl;
			cout << "A - Display Alfa's Information" << endl;
			cout << "B - Display Bravo's Information" << endl;
			cout << "C - Create an Arriving Party" << endl;
			cout << "D - Depart an Aircraft  " << endl;
			cout << "E - Exit the Program" << endl;
			cout << "L - Display Lounge's Information" << endl;

			char SwitchChar;

			cin >> SwitchChar;
			switch (SwitchChar)
			{
			case 'A':
				cout << "Alfa has " << ALFA.GetNumberOfAvailableSeats() << " Seats Remaining and " << ALFA.GetNumberofParties() << " Party(s) Onboard." << endl;
				ALFA.DisplayOnboardParties();
			
				break;
			case 'B':
				cout << "Bravo has " << BRAVO.GetNumberOfAvailableSeats() << " Seats Remaining and " << BRAVO.GetNumberofParties() << " Party(s) Onboard." << endl;
				BRAVO.DisplayOnboardParties();
				
				break;
			case 'C':
				CreateNewParty();
			
				break;
			case 'D':
				DepartPlane();
				FillFromLounge();
				break;
			case 'E':
				Exit = 1;
				do {
					FillFromLounge();
					ALFA.Reset();
					BRAVO.Reset();
				} while (ALFA.GetNumberOfAvailableSeats() != 0 &&
					BRAVO.GetNumberOfAvailableSeats() != 0 &&
					LOUNGE.GetNumberOfAvailableSeats() != 0);
				break;
			case 'L':
				cout << "Lounge has " << LOUNGE.GetNumberOfAvailableSeats() << " Seats Remaining and " << LOUNGE.GetNumberofParties() << " Party(s) Waiting" << endl;
				LOUNGE.DisplayOnboardParties();
				break;
			default:
				cout << '\a';
				break;
			}
		} while (!Exit);
	};






void DepartPlane() {
	char c;
	cout << "Please Enter the Plane to Depart (A for Alfa, B for Bravo)" << endl;
	cin >> c;
	if (c == 'A')
	{
		ALFA.DisplayOnboardParties();
		ALFA.Reset();
	}
	else if (c == 'B')
	{
		BRAVO.DisplayOnboardParties();
		BRAVO.Reset();
	}
	else
	{
		cout << endl;
		cout << "Invalid" << endl;
	}
}

void CreateNewParty()
{
	
	int PartySize;
	char * PartyName;
	char DesiredPlane;
	PartyName = new char;
	cout << " PARTY NAME: ";
	cin >> PartyName;
	cout << " PARTY SIZE: ";
	cin >> PartySize;
	cout << " DESIRED PLANE ('A' for 'ALFA', 'B' for 'BRAVO') " << endl;
	cin >> DesiredPlane;


	
		switch (DesiredPlane) {
		case 'A':
			if (PartySize <= ALFA.GetNumberOfAvailableSeats()) {
				cout << "The " << PartyName << " Party has boarded Alpha." << endl;
				ALFA.SubtractSeats(PartySize);
				ALFA.IncrementNumberOfParties();
				for (int j = 0; j < ALFA.GetNumberofParties(); j++) {
					if (ALFA.GetPartyArrayAt(j).GetPartyName() == "NULL") {
						ALFA.SetPartyAt(j,PartyName,PartySize);						
					}
				}
			}
			else {
				cout << "Not Enough Room on Alfa " << endl;
			}
			break;
		case 'B':
			if (PartySize <= BRAVO.GetNumberOfAvailableSeats()) {
				cout << " The " << PartyName << " Party has boarded Bravo." << endl;
				BRAVO.SubtractSeats(PartySize);
				BRAVO.IncrementNumberOfParties();
				for (int j = 0; j < BRAVO.GetNumberofParties(); j++) {
					if (BRAVO.GetPartyArrayAt(j).GetPartyName() == "NULL") {
						BRAVO.SetPartyAt(j, PartyName, PartySize);
					}
				}
			}
			else {
				cout << "Not Enough Room on Bravo " << endl;
			}
			break;
	
			
		default:		
				break;			
			
		}
	
}

void FillFromLounge() {
	for (int i = 0; i <= LOUNGE.GetNumberofParties(); i++)
	{
		if (LOUNGE.GetPartyArrayAt(i).GetPartySize() <= ALFA.GetNumberOfAvailableSeats() && LOUNGE.GetPartyArrayAt(i).GetPartyName() != "NULL") {
			cout << " The " << LOUNGE.GetPartyArrayAt(i).GetPartyName() << " Party has boarded Alpha from the Lounge." << endl;
			LOUNGE.AddSeats(LOUNGE.GetPartyArrayAt(i).GetPartySize());
			LOUNGE.DecrementNumberOfParties();
			ALFA.SubtractSeats(LOUNGE.GetPartyArrayAt(i).GetPartySize());
			ALFA.IncrementNumberOfParties();
			for (int j = 0; j < ALFA.GetNumberofParties(); j++) {
				if (ALFA.GetPartyArrayAt(j).GetPartyName() == "NULL") {
					ALFA.GetPartyArrayAt(j) = LOUNGE.GetPartyArrayAt(i);
					LOUNGE.GetPartyArrayAt(i).SetPartyName("NULL");
					LOUNGE.GetPartyArrayAt(i).SetPartySize(0);
				}
			}
		}
   else if (LOUNGE.GetPartyArrayAt(i).GetPartySize() <= BRAVO.GetNumberOfAvailableSeats() && LOUNGE.GetPartyArrayAt(i).GetPartyName() != "NULL") {
			cout << " The " << LOUNGE.GetPartyArrayAt(i).GetPartyName() << " Party has boarded Bravo from the Lounge." << endl;
			LOUNGE.AddSeats(LOUNGE.GetPartyArrayAt(i).GetPartySize());
			LOUNGE.DecrementNumberOfParties();
			BRAVO.SubtractSeats(LOUNGE.GetPartyArrayAt(i).GetPartySize());
			BRAVO.IncrementNumberOfParties();
		}
			for (int j = 0; j < BRAVO.GetNumberofParties(); j++) {
				if (BRAVO.GetPartyArrayAt(j).GetPartyName() == "NULL") {
				BRAVO.GetPartyArrayAt(j) = LOUNGE.GetPartyArrayAt(i);
				LOUNGE.GetPartyArrayAt(i).SetPartyName("NULL");
				LOUNGE.GetPartyArrayAt(i).SetPartySize(0);
				}
			}
		}
}



