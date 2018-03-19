#include "StudentArray.h"
#include <vector>


StudentArray::StudentArray()
{
	S.resize(26);
}
void StudentArray::SortStudentsByID()
{
	vector <Student> TempVector;
	TempVector.resize(5);
	int i;
	for (i = 0; i < 25; i++)
	{
		if (S[i].GetStudID() < S[i + 1].GetStudID())
		{
			TempVector[0] = (*this).S[i];
			(*this).S[i] = (*this).S[i + 1];
			(*this).S[i + 1] = TempVector[0];
		}
		else
		{

		}
	}
}
void StudentArray::ReadStudentsFromFileArray(fstream & F)
{
	int i;
	int StudNum;
	cout << "Enter Number of Students" << endl;
	cin >> StudNum;
	if (StudNum > 25)
	{
		cout << "Invalid Number of Students" << endl;
	}
	else
	{
		for (i = 0; i < StudNum; i++)
		{
			(*this).S[i].ReadStudentFromFile(F);
		}
	}
	
}
void StudentArray::WriteStudentsToFileArray(fstream & F)
{
	int i;
	int StudNum;
	cout << "Enter Number of Students" << endl;
	cin >> StudNum;
	if (StudNum > 25)
	{
		cout << "Invalid Number of Students" << endl;
	}
	else
	{
		for (i = 0; i < StudNum; i++)
		{
			(*this).S[i].WriteStudentToFile(F);
		}
	}
}
void StudentArray::SortStudentsByName()
{
	vector <Student> TempVector;
	TempVector.resize(5);
	int i;

	for (i = 0; i < 25; i++)
	{
		if (S[i].GetPerName().GetLast() < S[i + 1].GetPerName().GetLast())
		{
			TempVector[0] = (*this).S[i];
			(*this).S[i] = (*this).S[i + 1];
			(*this).S[i + 1] = TempVector[0];

		}
		else;
	}
}
StudentArray::~StudentArray()
{
}
void StudentArray::DisplayStudentArray()
{
	int i;
	for (i = 0; i < 25; i++)
	{
		if ((*this).S[i].GetPerName().GetFirst() != " ")
		(*this).S[i].DisplayStudent();
		else;
	}
}




