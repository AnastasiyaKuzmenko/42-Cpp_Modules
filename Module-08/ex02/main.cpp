/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:30:09 by akuzmenk          #+#    #+#             */
/*   Updated: 2024/02/23 11:40:36 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
	std::cout << "\033[35m" << " Test from subject " << "\033[0m" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "\033[35m" << " Test 1: Values as std::list<int> " << "\033[0m" << std::endl;
	{
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::list<int> s(mstack);
	}


	std::cout << std::endl << "\033[35m" << "Test 2: copy constructor" << "\033[0m" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int> copy(mstack);
		MutantStack<int>::iterator it = copy.begin();
		MutantStack<int>::iterator ite = copy.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}


	std::cout << std::endl << "\033[35m" << "Test 3: assignment operator" << "\033[0m" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int> copy;
		copy = mstack;
		MutantStack<int>::iterator it = copy.begin();
		MutantStack<int>::iterator ite = copy.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	std::cout << std::endl << "\033[35m" << "Test 4: empty()" << "\033[0m" << std::endl;
	{
		MutantStack<int> mstack;
		std::cout << "empty: " << mstack.empty() << std::endl;
		mstack.push(20);
		std::cout << "not empty: " << mstack.empty() << std::endl << std::endl;
	}

	return 0;
}
