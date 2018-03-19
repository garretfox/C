#include "NameAddress.h"
////////////////////////////////NAME FUNCTIONS/////////////////////////////////////////////////////////
Name::Name()
{
}
Name::Name(const Name & N) : First(N.First), Middle(N.Middle), Last(N.Last)
{
}
Name::Name(const WCS_String & L, const WCS_String & F, const WCS_String & M) : Last(L), First(F), Middle(M)
{
}
Name::~Name()
{
}
Name & Name::operator = (const Name & N)
{
	First = N.First;
	Middle = N.Middle;
	Last = N.Last;
	return *this;
}
bool Name::operator != (const Name & N)
{
	if (((*this) == N) == false)
		return true;
	else
		return false;
}
bool Name::operator < (const Name & N)
{
	bool pos;
	pos = (*this).Last > (N.Last);
	if (pos == 1)
	{
		return true;
	}
	else if (pos != 1)
	{
		pos = (*this).First > (N.First);
		if (pos == 1)
		{
			return true;
		}
		else if (pos != 1)
		{
			pos = (*this).Middle > (N.Middle);
			if (pos == 1)
			{
				return true;
			}
			else
				return false;
		}
	}
}
bool Name::operator <= (const Name & N)
{
	if (((*this) < N) == true)
		return true;
	else if (((*this) == N) == true)
		return true;
	else
		return false;
}
bool Name::operator == (const Name & N)
{
	if ((*this).Last == N.Last)
		if ((*this).First == N.First)
			if ((*this).Middle == N.Middle)
			{
		return true;
			}
			else
				return false;
}
bool Name::operator > (const Name & N)
{
	bool pos;
	pos = (*this).Last > (N.Last);
	if (pos == 1)
	{
		return false;
	}
	else if (pos != 1)
	{
		pos = (*this).First > (N.First);
		if (pos == 1)
		{
			return false;
		}
		else if (pos != 1)
		{
			pos = (*this).Middle > (N.Middle);
			if (pos == 1)
			{
				return false;
			}
			else
				return false;
		}

	}
}
bool Name::operator >= (const Name & N)
{
	if (((*this) > N) == true)
		return true;
	else if (((*this) == N) == true)
		return true;
	else
		return false;
}
/////////////////////////////////////ADDRESS FUNCTIONS//////////////////////////////////////////////
Address::Address()
{
}
Address::Address(const Address & A) : Street(A.Street), City(A.City), State(A.State), Zip(A.Zip)
{
}
Address::Address(const WCS_String & S, const WCS_String & C, const WCS_String & ST, const WCS_String Z) : Street(S), City(C), State(ST), Zip(Z)
{
}
Address::~Address()
{
}
void Address::DisplayAddress()
{
	cout << Street << endl;
	cout << City <<   endl;
	cout << State <<  endl;
	cout   << Zip <<  endl;
}
void Address::WriteAddress()
{
	cout << "****Street: ****" << endl;
	Street.Read();
	cout << "****City: ****" << endl;
	City.Read();
	cout << "****State: ****" << endl;
	State.Read();
	cout << "****ZIP: ****" << endl;
	Zip.Read();
	cout << "ADDRESS SAVED" << endl;
}
