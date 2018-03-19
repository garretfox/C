#ifndef NAME_H
#define NAME_H

#include "WCS_String.h"
////////////////                                NAME CLASS       ///////////////////////////////
class Name
{
public:
	Name();
	Name(const Name &);
	Name(const WCS_String &, const WCS_String &, const WCS_String &);
	~Name();
	WCS_String          GetFirst();
	void                SetFirst(char[81]);
	WCS_String          GetMid();
	void                SetMid(char[81]);
	WCS_String          GetLast();
	void DisplayLast();
	void DisplayFirst();
	void DisplayMid();
	void          SetLast(char[81]);
	void        WriteName();
	void         ReadName();
	bool  operator    >   (const Name &);
	bool  operator    !=  (const Name &);
	bool  operator    >=  (const Name &);
	bool  operator    <   (const Name &);
	bool  operator    <=  (const Name &);
	bool  operator    ==  (const Name &);
	Name &	operator  =	  (const Name &);
	void	Copy(const Name &);
private:
	WCS_String		First;
	WCS_String		Middle;
	WCS_String		Last;
};
///////////////////////                    ADDRESS CLASS                         //////////////////////////////
class Address
{
public:
	Address();
	~Address();
	Address(const WCS_String &, const WCS_String &, const WCS_String &, const WCS_String);
	Address(const Address & A);
	void         DisplayAddress();
	void        WriteAddress();
	void           SetStreet(char [81]);
	void             SetCity(char [81]);
	void            SetState(char [81]);
	void              SetZip(char [81]);
	WCS_String      GetStreet();
	WCS_String      GetCity();
	WCS_String      GetState();
	WCS_String      GetZip();
	void	     SameAddress();
	void      operator =	(const Address &);
	bool      operator ==	(const Address &);
	void	Copy(const Address &);
private:
	WCS_String		Street;
	WCS_String		City;
	WCS_String      State;
	WCS_String        Zip;
};

//////////////////////////                 NAME METHODS                              //////////////////////////////
inline void Name::DisplayFirst()
{
	cout << First << endl;
}
inline void Name::DisplayMid()
{
	cout << Middle << endl;
}
inline void Name::DisplayLast()
{
	cout << Last << endl;
}
inline void Name::Copy(const Name & N)
{
	*this = N;
}
//--------------------------------------------------------------------------------------------//
inline void Name::ReadName()
{
	cout << (*this).Last << ", " << (*this).First << " " << (*this).Middle << "." << endl;
}
//--------------------------------------------------------------------------------------------//
inline void Name::WriteName()
{

	cout << "FIRST" << endl;
	First.Read();
	cout << "MIDDLE" << endl;
	Middle.Read();
	cout << "LAST" << endl;
	Last.Read();
	cout << "NAME SAVED" << endl;

}
//--------------------------------------------------------------------------------------------//
inline void Name::SetFirst(char Line[81])
{
	First = Line;
}
//--------------------------------------------------------------------------------------------//
inline void Name::SetMid(char Line[81])
{
	Middle = Line;
}
//--------------------------------------------------------------------------------------------//
inline void Name::SetLast(char Line[81])
{
	Last = Line;
}
//--------------------------------------------------------------------------------------------//
inline WCS_String  Name::GetFirst()
{
	return (*this).First;
}
//--------------------------------------------------------------------------------------------//
inline WCS_String Name::GetMid()
{
	return (*this).Middle;
}
//--------------------------------------------------------------------------------------------//
inline WCS_String Name::GetLast()
{
	return (*this).Last;
}
/////////////////////////                 ADDRESS METHODS                      ////////////////////////////
inline WCS_String Address::GetCity()
{
	return City;
}
inline WCS_String Address::GetStreet()
{
	return Street;
}inline WCS_String Address::GetZip()
{
	return Zip;
}inline WCS_String Address::GetState()
{
	return State;
}
inline bool Address::operator ==	(const Address & OtherAddress)
{
	return (((*this).Street == OtherAddress.Street) && ((*this).City == OtherAddress.City)
		&& ((*this).State == OtherAddress.State) && ((*this).Zip == OtherAddress.Zip));
}
inline void Address::Copy(const Address & A)
{
	*this = A;
}
//--------------------------------------------------------------------------------------------//
inline void Address::operator = (const Address & NewAddress)
{
	(*this).Street = NewAddress.Street;
	(*this).City = NewAddress.City;
	(*this).State = NewAddress.State;
	(*this).Zip = NewAddress.Zip;
}
inline void Address::SetStreet(char Line[81])
{
	Street = Line;
}
inline void Address::SetCity(char Line[81])
{
	City = Line;
}
inline void Address::SetState(char Line[81])
{
	State = Line;
}
inline void Address::SetZip(char Line[81])
{
	Zip = Line;
}
#endif