/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:07:53 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/11/19 19:40:15 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "color.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"


int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;

	return 0;
}

/*
int main()
{


    // Uncomment this to check abstract class
//    Animal *test = new Animal();
//	    test->makeSound();
//   delete test;


	Animal *animalsArr[100];
	for (int i = 0; i <= 49; i++)
	{
		std::cout<<"Animal: "<<BLUE<<i<<RESET<<std::endl;
		animalsArr[i] = new Dog();
		std::cout<<"Type: "<<RED<<animalsArr[i]->getType()<<RESET<<std::endl;
		std::cout<<"Sound: ";
		animalsArr[i]->makeSound();
		std::cout<<GREEN<<"--------------------------"<<RESET<<std::endl<<std::endl;
	}
		
	for (int i = 50; i <= 99; i++)
	{
		std::cout<<"Animal: "<<BLUE<<i<<RESET<<std::endl;
		animalsArr[i] = new Cat();
		std::cout<<"Type: "<<RED<<animalsArr[i]->getType()<<RESET<<std::endl;
		std::cout<<"Sound: ";
		animalsArr[i]->makeSound();
		std::cout<<GREEN<<"--------------------------"<<RESET<<std::endl<<std::endl;
	}

	std::cout<<GREEN<<"--------------------------"<<RESET<<std::endl<<std::endl;
	std::cout<<GREEN<<"-----DESTROYING ANIMALS ARRAY-----"<<RESET<<std::endl<<std::endl;
	std::cout<<GREEN<<"--------------------------"<<RESET<<std::endl<<std::endl;
	for (int i = 0; i <= 99; i++)
	{
		 std::cout<<"Animal: "<<BLUE<<i<<RESET<<std::endl;
		delete animalsArr[i];
		std::cout<<GREEN<<"--------------------------"<<RESET<<std::endl;
	}

	std::cout<<GREEN<<"--------------------------"<<RESET<<std::endl<<std::endl;
	std::cout<<GREEN<<"--------DEEP COPY CAT-----"<<RESET<<std::endl<<std::endl;
	std::cout<<GREEN<<"--------------------------"<<RESET<<std::endl<<std::endl;
	
	
	std::cout<<BLUE<<"Cat: A"<<RESET<<std::endl;
	Cat *a = new Cat();
	a->getBrain()->setIdea(0,"I'm hungry.");
	std::cout<<"Type: "<<RED<<a->getType()<<RESET<<std::endl;
	std::cout<<"Sound: ";
	a->makeSound();
	std::cout<<"Idea 0: ";
	std::cout<<RED<<a->getBrain()->getIdea(0)<<RESET<<std::endl;
	std::cout<<"Idea 0 Adress: ";
	std::cout<<RED<<a<<RESET<<std::endl;
	std::cout<<GREEN<<"--------------------------"<<RESET<<std::endl<<std::endl;

	std::cout<<BLUE<<"Cat: B is a Copy from Cat A"<<RESET<<std::endl;
	Cat *b = new Cat(*a);
	std::cout<<BLUE<<"Now we delete Cat A"<<RESET<<std::endl;
	delete a;

	std::cout<<std::endl;
	std::cout<<BLUE<<"Cat: B"<<RESET<<std::endl;
	std::cout<<"Type: "<<RED<<b->getType()<<RESET<<std::endl;
	std::cout<<"Sound: ";
	b->makeSound();
	std::cout<<"Idea 0: ";
	std::cout<<RED<<b->getBrain()->getIdea(0)<<RESET<<std::endl;
	std::cout<<"Idea 0 Adress: ";
	std::cout<<RED<<b<<RESET<<std::endl;
	std::cout<<GREEN<<"--------------------------"<<RESET<<std::endl<<std::endl;
	delete b;


	std::cout<<GREEN<<"--------------------------"<<RESET<<std::endl<<std::endl;
	std::cout<<GREEN<<"--------DEEP COPY DOG-----"<<RESET<<std::endl<<std::endl;
	std::cout<<GREEN<<"--------------------------"<<RESET<<std::endl<<std::endl;
	
	
	std::cout<<BLUE<<"Dog: C"<<RESET<<std::endl;
	Dog *c = new Dog();
	c->getBrain()->setIdea(0,"I'm hungry!");
	std::cout<<"Type: "<<RED<<c->getType()<<RESET<<std::endl;
	std::cout<<"Sound: ";
	c->makeSound();
	std::cout<<"Idea 0: ";
	std::cout<<RED<<c->getBrain()->getIdea(0)<<RESET<<std::endl;
	std::cout<<"Idea 0 Adress: ";
	std::cout<<RED<<c<<RESET<<std::endl;
	std::cout<<GREEN<<"--------------------------"<<RESET<<std::endl<<std::endl;

	std::cout<<BLUE<<"Dog: D is a Copy from Dog C"<<RESET<<std::endl;
	Dog *d = new Dog(*c);
	std::cout<<BLUE<<"Now we delete Dog A"<<RESET<<std::endl;
	delete c;

	std::cout<<std::endl;
	std::cout<<BLUE<<"Dog: D"<<RESET<<std::endl;
	std::cout<<"Type: "<<RED<<d->getType()<<RESET<<std::endl;
	std::cout<<"Sound: ";
	d->makeSound();
	std::cout<<"Idea 0: ";
	std::cout<<RED<<d->getBrain()->getIdea(0)<<RESET<<std::endl;
	std::cout<<"Idea 0 Adress: ";
	std::cout<<RED<<d<<RESET<<std::endl;
	std::cout<<GREEN<<"--------------------------"<<RESET<<std::endl<<std::endl;
	delete d;

	return 0;
}
*/

