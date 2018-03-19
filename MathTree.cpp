#include "MathTree.h"

MathTree::Node::Node(const Token & Toke) : Token(Toke)
{
}

MathTree::MathTree()
{
}

MathTree::~MathTree()
{
	DeleteTree();
}

bool MathTree::DeleteTree()
{
	WCS_Pointer <Node> Ptr;
	if (pRoot)
	{

		Ptr = GetLeftMostOperator(pRoot);

		while (Ptr)
		{
		(*Ptr).pLeft.SetToNull();
		(*Ptr).pRight.SetToNull();
			if (Ptr != pRoot)
			{
				Ptr = (*Ptr).pParent;
				if (Ptr == pRoot)
				{
					(*Ptr).LeftSideDone = 1;
					Ptr = GetLeftMostOperator((*Ptr).pRight);
					if (Ptr == (*pRoot).pRight)
					{
						(*Ptr).pLeft.SetToNull();
						(*Ptr).pRight.SetToNull();
					}
					else
					{
						break;
					}
				}
				else
				{
					Ptr = GetLeftMostOperator((*Ptr).pRight);
				}
			}
			else
			{
				pRoot.SetToNull();
				return 1;
				cout << "Tree Deleted" << endl;
			}
		}
	}
	else
	{
		throw DoesNotExist;
		cout << "Tree Doesn't Exist" << endl;
		return 0;
	}
}

Variable::ValueType MathTree::Evaluate()
{
	WCS_Pointer <Node> Ptr;

	if (pRoot)
	{
		Ptr = GetLeftMostOperator(pRoot);
		while (Ptr)
			if (!(*Ptr).LeftSideDone)
			{
			(*Ptr).SetValue((*(*Ptr).pLeft).GetValue());
			(*Ptr).LeftSideDone = true;
			Ptr = GetLeftMostOperator((*Ptr).pRight);
			}
			else
			{
				switch ((*Ptr).GetType())
				{
				case Token::OperatorPlusToken:
					(*Ptr).SetValue((*Ptr).GetValue() + (*(*Ptr).pRight).GetValue());
					break;
				case Token::OperatorMinusToken:
					(*Ptr).SetValue((*Ptr).GetValue() - (*(*Ptr).pRight).GetValue());
					break;
				case Token::OperatorAsteriskToken:
					(*Ptr).SetValue((*Ptr).GetValue() * (*(*Ptr).pRight).GetValue());
					break;
				case Token::OperatorSlashToken:
					if ((*(*Ptr).pRight).GetValue() == 0)
					{
						throw DivideByZeroError;
					}
					else
						(*Ptr).SetValue((*Ptr).GetValue() / (*(*Ptr).pRight).GetValue());
					break;
					
				}
				Ptr = (*Ptr).pParent;
			}
		return (*pRoot).GetValue();
	}
	else
		return 0;
}


WCS_Pointer <MathTree::Node> & MathTree::GetLeftMostOperator(const WCS_Pointer <Node> & pStart)
{
	WCS_Pointer <Node> Ptr(pStart);

	while ((*Ptr).pLeft)
	{
		(*Ptr).LeftSideDone = false;
		Ptr = (*Ptr).pLeft;
	}
	return (*Ptr).pParent;
}

bool MathTree::InsertBinaryOperator(const Token & Toke)
{
	WCS_Pointer <Node> pNewOperator(WCS_Pointer <Node>(new Node(Toke)));

	while (pLastOperator && (*pLastOperator).GetPrecedence() >= Toke.GetPrecedence())
		pLastOperator = (*pLastOperator).pParent;
	if (pLastOperator)
	{  // go on the right side of pLastOperator
		(*pNewOperator).pLeft = (*pLastOperator).pRight;
		(*(*pNewOperator).pLeft).pParent = pNewOperator;
		(*pNewOperator).pParent = pLastOperator;
		(*pLastOperator).pRight = pNewOperator;
		pLastOperator = pNewOperator;
	}
	else
	{  // new node becomes root of tree
		pLastOperator = pNewOperator;
		(*pLastOperator).pLeft = pRoot;
		(*pRoot).pParent = pLastOperator;
		pRoot = pLastOperator;
	}
	return true;
}

bool MathTree::InsertOperand(const Token & Toke)
{
	if (!pRoot)
		pRoot = WCS_Pointer <Node>(new Node(Toke));
	else
		(*pLastOperator).pRight = WCS_Pointer <Node>(new Node(Toke));
	return true;
}

bool MathTree::InsertUnaryOperator(const Token & Toke)
{
	Token	Temp(Token::ConstantToken, 0);

	InsertOperand(Temp);
	InsertBinaryOperator(Toke);
	return true;
}
