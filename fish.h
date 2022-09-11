#pragma once
#include "animal.h"
#include <fstream>

class Fish : Animal
{
private:
	//порода
	char* _breed;
	// окрас
	char* _color;
	// тип питания
	char* _animal_nutrition;


public:
	Fish() {
		_breed = new char[64];
		_color = new char[64];
		_animal_nutrition = new char[64];

		std::cout << "Bread: ";
		std::cin.getline(_breed, 64);
		std::cout << "Color: ";
		std::cin.getline(_color, 64);
		std::cout << "Animal nutrition: ";
		std::cin.getline(_animal_nutrition, 64);
	}
	Fish(std::ifstream& in){
		in >> _breed;
		in >> _color;
		in >> _animal_nutrition;
	}
	~Fish() {
		delete[] _breed;
		delete[] _color;
		delete[] _animal_nutrition;
	}

	void save(std::ofstream& out) override {
		out << FISH << std::endl;
		out << _breed << std::endl;
		out << _color << std::endl;
		out << _animal_nutrition << std::endl;
	}

	void show() override {
		std::cout << "Fish:" << std::endl;
		std::cout << _breed << std::endl;
		std::cout << _color << std::endl;
		std::cout << _animal_nutrition << std::endl;
	}

	void edit() override {
		int choice;
		std::cout << "Select a characteristic" << std::endl;
		std::cout << "1. Breed" << std::cout;
		std::cout << "2. Color" << std::cout;
		std::cout << "3. Animal nutrition" << std::cout;
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			std::cin.getline(_breed, 64);
			break;

		case 2:
			std::cin.getline(_color, 64);
			break;

		case 3:
			std::cin.getline(_animal_nutrition, 64);
			break;

		default:
			break;
		}
	}

};