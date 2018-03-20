#include "StudentArray.h"
#include "Student.h"
#include <fstream>


Student::Student()
{
	PhoneNum = "000000\0";
	StudID   = "000000000\0";
	AreaCode = "000\0";
}
Student::~Student()
{
}
Student::Student(Address & A, Name & N) : PerAdd(A), PerName(N)
{
}
void Student::ReadStudentFromFile(fstream & F)
{
	//char AreaCodeLine[4];
	//char StudentIDLine[10];
	//char PhoneNumLine[7]; 
	char Line[81];
	if (F.eof())
	{
		F.clear();
		F.close();
	}
	else
	{
		
		cout << "Reading..." << endl;
		F.getline(Line, 81);
		cout << "Last Name is " << Line << endl;
		PerName.SetLast(Line);

		F.getline(Line, 81);
		cout << "Middle Name is " << Line << endl;
		PerName.SetMid(Line);

		F.getline(Line, 81);
		cout << "First Name is " << Line << endl;
		PerName.SetFirst(Line);

		F.getline(Line, 81);
		cout << "Street is " << Line << endl;
		PerAdd.SetStreet(Line);

		F.getline(Line, 81);
		cout << "City is " << Line << endl;
		PerAdd.SetCity(Line);
	
		F.getline(Line, 81);
		cout << "State is " << Line << endl;
		PerAdd.SetState(Line);

		F.getline(Line, 81);
		cout << "ZIP is " << Line << endl;
		PerAdd.SetZip(Line);
		
		F.getline(Line, 5);
		cout << "Area Code is " << Line<< endl;
		AreaCode = Line;
		
		F.getline(Line, 8);
		cout << "Phone Number is " << Line << endl;
		PhoneNum = Line;

		F.getline(Line, 10);
		cout << "Student ID is " << Line << endl;
		StudID = Line;
		
	}
	
	
}
void Student::WriteStudentToFile(fstream & O)
{
	O.open("WriteFile", ios_base::out);
	cout << "Writing File" << endl;
	(*this).GetPerName().GetLast().Display(O); 
	O << endl;
	
	(*this).GetPerName().GetMid().Display(O); 
	O << endl;

	(*this).GetPerName().GetFirst().Display(O); 
	O << endl;
	
	(*this).GetPerAdd().GetStreet().Display(O);
	O << endl;

	(*this).GetPerAdd().GetCity().Display(O);
	O << endl;
	
	(*this).GetPerAdd().GetState().Display(O);
	O << endl;
	
	(*this).GetPerAdd().GetZip().Display(O);
	O << endl;
	
	(*this).GetAreaCode().Display(O);

	O << "\n";
	
	(*this).GetPhoneNum().Display(O);

	O << "\n";

	(*this).GetStudID().Display(O);

	O << "\n";
	
}
void Student::DisplayStudent()
{
	if ( PhoneNum[0] == '0')
		cout << "no student to display" << endl;
	else
	{
		PerName.DisplayLast();
		PerName.DisplayMid();
		PerName.DisplayFirst();
		PerAdd.DisplayAddress();
		AreaCode.Display();
		cout << "\n";
		PhoneNum.Display();
		cout << "\n";
		StudID.Display();
		cout << "\n";
	}

}
