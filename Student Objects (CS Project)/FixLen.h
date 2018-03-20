#ifndef FIXLEN_H
#define FIXLEN_H
#include <assert.h>
#include <string>
template <class DATA, int Length>	
class Array
{
public:
	enum Exceptions { IndexOutOfBounds };
	Array();
	Array(const Array <DATA, Length> &);
	Array(const DATA &);
	~Array();
	void			Copy(const Array <DATA, Length> &);
	DATA &			At(int);
	ostream & Display(ostream & = cout);
	bool operator < (const Array <DATA, Length> &);
	void WriteArray  ();
	const DATA &	At(int) const;
	Array <DATA, Length> &	operator =	(const Array <DATA, Length> &);
	Array <DATA, Length> &	operator =  (const char [] );
	DATA &			operator []	(int);
	const DATA &	operator []	(int) const;
private:
	DATA *		pData;
	int			NumElements;
};
//////////constructor///////////
template <class DATA, int Length>
bool Array <DATA, Length>::operator < (const Array <DATA, Length> & A)
{
	int i;
	for (i = 0; i < Length; i++)
	{
		if ((*this)[i] < A[i])
			return true;
		else;
	}
}
template <class DATA, int Length>     
Array <DATA, Length>::Array()
{
	
	
	pData = new DATA[Length];
	
	pData[Length - 1] = '/0';
	
}
/////////////////////////////////
//////////copy array///////////
template <class DATA, int Length>
Array <DATA, Length>::Array(const Array <DATA, Length> & A)
{
	int		i;

	NumElements = A.NumElements;
	pData = new DATA[NumElements];
	for (i = 0; i < NumElements; i++)
		pData[i] = A.pData[i];
}

template <class DATA,int Length>
Array <DATA, Length>::Array(const DATA & Data)
{
	int		i;

	NumElements = Length;
	pData = new DATA[NumElements];
	for (i = 0; i < NumElements; i++)
		pData[i] = Data;
}

template <class DATA, int Length>
Array <DATA, Length>::~Array()
{
	delete[] pData;
}

template <class DATA,int Length>
inline DATA & Array <DATA, Length>::At(int i)
{
	return operator [] (i);
}

template <class DATA,int Length>
inline const DATA & Array <DATA, Length>::At(int i) const
{
	return operator [] (i);
}

template <class DATA, int Length>
void Array <DATA, Length>::Copy(const Array <DATA, Length> & A)
{
	int		i;

	if (NumElements != A.NumElements)	// check if they are the same size
	{
		delete[] pData;		// no, need to create an array the right size
		NumElements = A.NumElements;
		pData = new Data[NumElements];
	}
	else;
	for (i = 0; i < NumElements; i++)
		pData[i] = A.pData[i];
}

template <class DATA,int Length>
inline Array <DATA, Length> & Array <DATA, Length>::operator = (const Array <DATA, Length> & A)	// still can use inline with template methods
{
	Copy(A);
	//assert(strlen(pData) == Length);
	return *this;
}
template <class DATA, int Length>
inline Array <DATA, Length> & Array <DATA, Length>::operator = (const char A[])
{
	int i;
	for (i = 0; i <= Length;i++)
	 (*this).pData[i] = A[i];


	//assert(strlen(pData) == Length);
	return *this;
}
template <class DATA, int Length>
inline DATA & Array <DATA, Length>::operator [] (int i)	// still can use inline with template methods
{
	//		assert ((i >= 0) && (i < NumElements));		// assert is automatically removed if you switch configuration manager from debug to release
	if (!(i >= 0) && (i < NumElements))
		throw IndexOutOfBounds;
	else
		return pData[i];
}

template <class DATA, int Length>
inline const DATA & Array <DATA, Length>::operator [] (int i) const
{
	assert((i >= 0) && (i < NumElements));
	return pData[i];
}
template <class DATA, int Length>
void Array <DATA, Length>::WriteArray()
{
	cout << "Please Read In Array Data" << endl;

	
	cin >> pData;
	assert(strlen(pData) == Length);
	
}
template <class DATA, int Length>
ostream & Array <DATA, Length>::Display(ostream & out)
{
	cout << "TEST" << endl;
	return out << pData;
	cout << "TEST GOOD" << endl;
}
#endif