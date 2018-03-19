#ifndef MATH_TREE_H
#define MATH_TREE_H

#include "WCS_Pointer.h"

#include "Token.h"

class MathTree
{
	
private:
	struct Node : public Token, public RefCount
	{
		WCS_Pointer <Node>		pLeft;
		WCS_Pointer <Node>		pRight;
		WCS_Pointer <Node>		pParent;
		bool					LeftSideDone;

		Node(const Token &);
	};
public:
	enum Exception{ DivideByZeroError, DoesNotExist };
	MathTree();
	~MathTree();
	bool					DeleteTree();
	Variable::ValueType		Evaluate();
	bool					InsertBinaryOperator(const Token &);
	bool					InsertOperand(const Token &);
	bool					InsertUnaryOperator(const Token &);

private:
	MathTree(const MathTree &);
	MathTree &				operator =			(const MathTree &);
	WCS_Pointer <Node> &	GetLeftMostOperator(const WCS_Pointer <Node> &);

	WCS_Pointer <Node>		pLastOperator;
	WCS_Pointer <Node>		pRoot;
};

#endif
