#pragma once
#include "Party.h"





class Plane {
public:
	Plane();
	Plane(char*c);
	bool IsSet();
	void AddSeats(int);
	void SubtractSeats(int);
	void SetSeatNumber();
	void SetPartyAt(int, char*, int);
	void DisplayOnboardParties();
	void IncrementNumberOfParties();
	void DecrementNumberOfParties();
	
	void Reset();
	bool NameNull(int);
	int  GetNumberofParties();
	int GetNumberOfAvailableSeats();
	Party GetPartyArrayAt(int i);
	Party * GetPartyArray();
	
private:
	bool isSet;
	int NumberOfSeats;
	int OriginalNumberOfSeats;
	int NumberOfParties;
	Party PartyArray[40];
	char *PlaneName;

};



