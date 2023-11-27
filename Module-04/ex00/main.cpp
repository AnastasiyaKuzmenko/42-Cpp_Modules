/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:07:53 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/11/19 19:31:56 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "color.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete i;
	delete j;
	delete meta;
	return 0;
}

/*
int main()
{
	std::cout<<GREEN<<"----------animal from animal----------"<<RESET<<std::endl;
	const Animal *animo = new Animal();
	std::cout<<"Type: "<<BLUE<<animo->getType()<<RESET<<std::endl;
	std::cout<<"Sound: ";
	animo->makeSound();
	delete animo;
	std::cout<<GREEN<<"--------------------------"<<RESET<<std::endl<<std::endl;

	std::cout<<GREEN<<"----------cat from animal----------"<<RESET<<std::endl;
	const Animal *kitty = new Cat();
	std::cout<<"Type: "<<BLUE<<kitty->getType()<<RESET<<std::endl;
	std::cout<<"Sound: ";
	kitty->makeSound();
	delete kitty;
	std::cout<<GREEN<<"--------------------------"<<RESET<<std::endl<<std::endl;

	std::cout<<GREEN<<"----------dog from animal----------"<<RESET<<std::endl;
	const Animal *doggy = new Dog();
	std::cout<<"Type: "<<BLUE<<doggy->getType()<<RESET<<std::endl;
	std::cout<<"Sound: ";
	doggy->makeSound();
	delete doggy;
	std::cout<<GREEN<<"--------------------------"<<RESET<<std::endl<<std::endl;

	std::cout<<GREEN<<"----------wrong animal from wrong animal----------"<<RESET<<std::endl;
	const WrongAnimal *wrongAnimo = new WrongAnimal();
	std::cout<<"Type: "<<BLUE<<wrongAnimo->getType()<<RESET<<std::endl;
	std::cout<<"Sound: ";
	wrongAnimo->makeSound();
	delete wrongAnimo;
	std::cout<<GREEN<<"--------------------------"<<RESET<<std::endl<<std::endl;

	std::cout<<GREEN<<"----------wrong cat from wrong animal----------"<<RESET<<std::endl;
	const WrongAnimal *wrongKitty = new WrongCat();
	std::cout<<"Type: "<<BLUE<<wrongKitty->getType()<<RESET<<std::endl;
	std::cout<<"Sound: ";
	wrongKitty->makeSound();
	delete wrongKitty;
	std::cout<<GREEN<<"--------------------------"<<RESET<<std::endl<<std::endl;

	std::cout<<GREEN<<"----------wrong cat from wrong cat----------"<<RESET<<std::endl;
	const WrongCat *wrongKitty2 = new WrongCat();
	std::cout<<"Type: "<<BLUE<<wrongKitty2->getType()<<RESET<<std::endl;
	std::cout<<"Sound: ";
	wrongKitty2->makeSound();
	delete wrongKitty2;
	std::cout<<GREEN<<"--------------------------"<<RESET<<std::endl<<std::endl;
	return 0;
}
*/
