/*
Lab 04
By: Vincent Fealy
3/1/23
*/

#include <iostream>
#include <stack>
#include <string>

#include "d_tnode.h"
#include "d_tnode1.h"
#include "inf2pstf.h"

tnode<char> *buildExpTree(const string& exp);

void prefixoutput(tnode<char> *exp);

void postorderT(tnode<char> *expr);

void preorderT(tnode<char> *expr);

int main()
{

	tnode<char> *oneponeTree;
	tnode<char> *oneptwoTree;
	tnode<char> *onepthreeTree;

	//The infix expressions asked to convert to pre-order and post order
	string p1 = "a*b";
	string p2 = "a+b+c";
	string p3 = "a+b*c/d-e";

	infix2Postfix one(p1);
	infix2Postfix two(p2);
	infix2Postfix three(p3);

	p1 = one.postfix();
	p2 = two.postfix();
	p3 = three.postfix();

	//trees
	oneponeTree = buildExpTree(p1);
	oneptwoTree = buildExpTree(p2);
	onepthreeTree = buildExpTree(p3);


	//outputting pre and post order
	std::cout << "Pre-Order" << std::endl;
	preorderT(oneponeTree);
  	std::cout << std::endl;
	preorderT(oneptwoTree);
  	std::cout << std::endl;
	preorderT(onepthreeTree);
	std::cout << std::endl;
    //
	std::cout << "Post-Order" << std::endl;
	postorderT(oneponeTree);
  	std::cout << std::endl;
	postorderT(oneptwoTree);
  	std::cout << std::endl;
	postorderT(onepthreeTree);
	std::cout << std::endl;

	//Here  will ask for the user input
	string user_exp;
	std::cout << "Enter the expression: ";
	std::cin >> user_exp;
//user expression
	infix2Postfix usr(user_exp);
	user_exp = usr.postfix();
	
	tnode<char> *user_Input;
	user_Input = buildExpTree(user_exp);
	
	//Output Prefix and Postfix form 
	std::cout << "Prefix form: ";
	prefixoutput(user_Input);
	std::cout << std::endl;
    //postfix
	std::cout << "Postfix form: ";
	postorderT(user_Input);
	std::cout << std::endl;
    //postfix
    //length ptr on user input length
	int size = user_exp.length();
	std::cout << "Expression tree: " << std::endl;
	displayTree(user_Input, size);
    //diplaying that tree
	return 0;
}

/*
For these next void functions, out=void
*Taking in tnode getting void out
*this outputs expression in preorder
*/
void preorderT(tnode<char> *expr)
{
	if(!expr)
    {
		return;
	}
    else
    {
		std::cout << expr->nodeValue << " ";

		postorderT(expr->left);
		postorderT(expr->right);
	}
}

void postorderT(tnode<char> *expr){
	if(!expr)
    {
		return;
	}
    else
    {
		postorderT(expr->left);
		postorderT(expr->right);

		std::cout << expr->nodeValue << " ";
	}
}

void prefixoutput(tnode<char> *exp)
{
	if(!exp)
    {
		return;
	}
	std::cout << exp->nodeValue << " ";
    //search left and right
	prefixoutput(exp->left);
	prefixoutput(exp->right);
}
	
	

tnode<char> *buildExpTree(const string& exp)
{
	tnode<char> *newnode, *lptr, *rptr;
	char token;
	stack<tnode<char> *> s;
	int i = 0;

	while(i != exp.length())
	{
		
		while (exp[i] == ' ' || exp[i] == '\t')
			i++;

		if (i == exp.length())
			break;

		token = exp[i];
		i++;

		if (token == '+' || token == '-' || token == '*' || token == '/')
		{

			rptr = s.top();
			s.pop();

			lptr = s.top();
			s.pop();
		
			newnode = new tnode<char>(token,lptr,rptr);

			s.push(newnode);
		}
		else
		{
			newnode = new tnode<char>(token);

			s.push(newnode);
		}
	}
    //return null exp
	if (!s.empty())
		return s.top();
	else
		return NULL;
}
    //if not an empty expression the root would be the top of the stack