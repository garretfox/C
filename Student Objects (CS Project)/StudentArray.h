#ifndef STUDENTARRAY_H
#define STUDENTARRAY_H
#include "Student.h"
#include <vector>
class StudentArray
{
public:
	StudentArray                  ();
	~StudentArray                 ();
	void SortStudentsByID         ();
	void SortStudentsByName       ();
	void DisplayStudentArray      ();
	void WriteStudentsToFileArray (fstream  &);
	void ReadStudentsFromFileArray(fstream &);
	vector <Student> S;
};
#endif