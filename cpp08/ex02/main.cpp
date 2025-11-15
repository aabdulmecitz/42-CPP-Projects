#include "MutantStack.hpp"
#include <list>

int main()
{
	std::cout << "===== MutantStack Test =====" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	
	std::cout << "Forward iteration:" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	
	std::cout << "\nReverse iteration:" << std::endl;
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}
	
	std::cout << "\n===== Comparing with std::list =====" << std::endl;
	std::list<int> mylist;
	mylist.push_back(5);
	mylist.push_back(17);
	mylist.pop_back();
	mylist.push_back(3);
	mylist.push_back(5);
	mylist.push_back(737);
	mylist.push_back(0);
	
	std::cout << "List forward iteration:" << std::endl;
	std::list<int>::iterator lit = mylist.begin();
	std::list<int>::iterator lite = mylist.end();
	++lit;
	--lit;
	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}
	
	std::stack<int> s(mstack);
	return 0;
}
