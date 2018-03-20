#ifndef STUDENT_H
#define STUDENT_H
#include "WCS_String.h"
#include "NameAddress.h"
#include "FixLen.h"
class Student
{
public:
	Student();
	Student(Address &, Name &);
	Student  & operator =   (const Student &);
	void           WriteStudent();
	void         DisplayPerName();
	void          DisplayPerAdd();
	void          DisplayStudID();
	void         DisplayStudent();
	void    ReadStudentFromFile(fstream & F);
	void     WriteStudentToFile(fstream & O);
	void           ReadPhoneNum();
	void           ReadAreaCode();
	Name    &        GetPerName();
	Address &         GetPerAdd();
	Array<char, 10>   GetStudID();
	Array<char, 7>  GetPhoneNum();
	Array<char, 4>  GetAreaCode();
	~Student();
private:
	 Name            PerName;
   	 Address          PerAdd;
	 Array<char, 10>  StudID;
	 Array<char, 7> PhoneNum;
	 Array<char, 4> AreaCode;

};
inline void Student::WriteStudent()
{
	cout << "Please enter Last name: " << endl;
	GetPerName().GetLast().Read();
	cout << "Please enter First name: " << endl;
	GetPerName().GetFirst().Read();
	cout << "Please enter Middle name: " << endl;
	GetPerName().GetMid().Read();
	cout << "Please enter Street name: " << endl;
	GetPerAdd().GetStreet().Read();
	cout << "Please enter City name: " << endl;
	GetPerAdd().GetCity().Read();
	cout << "Please enter State name: " << endl;
	GetPerAdd().GetState().Read();
	cout << "Please enter Zip Code: " << endl;
	GetPerAdd().GetZip().Read();
	cout << "Please enter Area Code: " << endl;
	AreaCode.WriteArray();
	cout << "Please enter Phone Number: " << endl;
	PhoneNum.WriteArray();
	cout << "Please enter Student ID: " << endl;
	StudID.WriteArray();
}
inline Array<char, 10> Student::GetStudID()
{
	return StudID;
}
inline Array<char, 7> Student::GetPhoneNum()
{
	return PhoneNum;
}
inline Array<char, 4> Student::GetAreaCode()
{
	return AreaCode;
}
inline Student & Student::operator = (const Student & P)
{
	PerAdd  = P.PerAdd;
	PerName = P.PerName;
	return *this;
}
inline Name & Student::GetPerName()
{
	return (*this).PerName;
}
inline Address & Student::GetPerAdd()
{
	return (*this).PerAdd;
}
inline void Student::DisplayPerName()
{
	(*this).PerName.ReadName();
}
inline void Student::DisplayPerAdd()
{
	(*this).PerAdd.DisplayAddress();
}
inline void Student::DisplayStudID()
{
	StudID.Display(); 
}
#endif
