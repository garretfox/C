#include "stdafx.h"
#include "Plane.h"
#include <iostream>
using namespace std;


Plane::Plane() {
	isSet = 0;
}
Plane::Plane(char *c)
{
	PlaneName = c;
	NumberOfParties = 0;
	for (int i = 0; i < 40; i++) {
		PartyArray[i].SetPartyName("NULL");
		PartyArray[i].SetPartySize(0);
	};
	isSet = 0;
}

void Plane::SetPartyAt(int i, char* c, int j)
{
	GetPartyArrayAt(i).SetPartyName(c);
	GetPartyArrayAt(i).SetPartySize(j);
}
bool Plane::NameNull(int i) {
	if (PartyArray[i].GetPartyName() == "NULL")
		return 1;
	else
		return 0;
}

bool Plane::IsSet() {
	return isSet;
}

void Plane::AddSeats(int i)
{
	int j = NumberOfSeats + i;
	NumberOfSeats = j;
}
void Plane::SubtractSeats(int i)
{
	int j = NumberOfSeats - i;
	NumberOfSeats = j;
}
void Plane::SetSeatNumber() {	
	bool valid = 0;
	int i;
	cout << "Enter " << PlaneName << "'s Seating Capacity" << endl;
	cin >> i;
	do {
		if (i > 40 || i < 0) {
			cout << " Invalid Number" << endl;
		}
		else {
			valid = 1;
			NumberOfSeats = i;
			OriginalNumberOfSeats = i;
		}
	} while (!valid);
}
	
		
	
	


void Plane::IncrementNumberOfParties() {
	NumberOfParties++;
}
void Plane::DecrementNumberOfParties() {
	NumberOfParties--;
}

int Plane::GetNumberOfAvailableSeats() {
	return NumberOfSeats;
}

void Plane::DisplayOnboardParties()
{

	cout << "PARTY NAMES" << endl;

	for (int i = 0; i < NumberOfParties; i++)
	{
		if (GetPartyArrayAt(i).GetPartyName() != "NULL") {


			cout << "______________________ PARTY " << i << "_________________________" << endl;
			cout << *(GetPartyArrayAt(i).GetPartyName()) << endl;
			cout << "And Has " << GetPartyArrayAt(i).GetPartySize() << " People." << endl;
			cout << "_________________________________________________________________" << endl;
		}
		else;

	}
}

Party Plane::GetPartyArrayAt(int i) {
	return PartyArray[i];
}

Party * Plane::GetPartyArray() {
	return PartyArray;
}

void Plane::Reset() {
	cout << "Passengers Departing on " << PlaneName << ":" << endl; 
	cout << "__+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+___" << endl;
	DisplayOnboardParties();
	for (int i = 0; i < 40; i++) {
		PartyArray[i].SetPartyName("NULL");
		PartyArray[i].SetPartySize(0);
	};
	NumberOfParties = 0;
	NumberOfSeats = OriginalNumberOfSeats;
}

int Plane::GetNumberofParties() {
	return NumberOfParties;
}