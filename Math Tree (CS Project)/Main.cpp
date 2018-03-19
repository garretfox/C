#include <iostream>
#include <fstream>
using namespace std;

#include "Token.h"
#include "MathTree.h"
#include "Operator.h"

void main(int argc, char * argv[])
{
	bool Exit = 0;
	int		i;
	fstream	MyFile;
	Token T;
	MathTree MT;
	Variable V;


	MyFile.open(argv[1], ios_base::in);
	do{
		try
		{
			switch (MyFile.get())
			{
			case 'C':
				T.SetType(ConstantToken);
				MyFile >> i;
				if (i > 999)
					throw TooLargeConstant;
				else
				{
					T.SetValue(i);
					MT.InsertOperand(T);
				}
				break;
			case 'V':
				T.SetType(VariableToken);
				MyFile >> i;
				if (i > 99)
					throw InvalidVariable;
				else
				{
					T.SetWhich(i);
					MT.InsertOperand(T);
				}
				break;
			case 'v':
				MyFile >> i;
				if (i > 99)
					throw InvalidVariable;
				else
				T.SetWhich(i);
				MyFile >> i;
				if (i > 999)
					throw TooLargeConstant;
				else
				T.SetValue(i);
				break;
			case 'E':
				MT.Evaluate();
				MT.DeleteTree();
				break;
			case 'O':
				T.SetType(OperatorToken);
				MyFile >> i;
				if (i == 0)
					T.SetPrecedence(BinaryPlusMinusPrecedence);
				else if (i == 1)
					T.SetPrecedence(MultiplyDividePrecedence);
				else if (i == 2)
					T.SetPrecedence(UnaryPlusMinusPrecedence);
				else if (i == 3)
					T.SetPrecedence(ParenthesesPrecedence);
				MT.InsertBinaryOperator(T);
				break;
			case 'D':
				MT.DeleteTree();
				break;
			case 'X':
				MT.DeleteTree();
				cout << "Bye." << endl;
				exit(0);
				break;
			}
		}
		catch (MathTree::Exception e)
			{
				switch (e)
				{
				case MathTree::DivideByZeroError:
					cout << "Cannot Divide By Zero" << endl;
					break;
				}
			}
		catch (Token::Exception e)
			{
				switch (e)
				{
				case Token::ConstantTooLarge:
					cout << "Constant May Not Exceed 999" << endl;
					break;
				case Token::InvalidVariable:
					cout << "Variable Typename May Not Exceed 99" << endl;
					break;
				case Token::TokenFileNotOpen:
					cout << "File Not Open" << endl;
					break;
				}
			}

	} while (!Exit);
		
} 
			
				
































/*
void main()
{
	bool Exit = 0;
	char c;
	do
	{
		switch (c = getch())
		{
		case 'c':
			cout << "1" << endl;
		case 'V':
			break;
		case 'v':
			break;
		case 'O':
			break;
		case 'E':
			break;
		case 'D':
			break;
		case 'X':
			break;
		default:
			cout << "Invalid Input" << endl;
			break;
		};
	} while (!Exit);
};
*/