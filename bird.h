#pragma once
#include "animal.h"
#include <fstream>

class Bird : Animal
{
private:
	char* _breed;
	char* _color;
	char* _animal_nutrition;
	char* _habitat;
	

public:
	Bird() {
		_breed = new char[64];
		_color = new char[64];
		_animal_nutrition = new char[64];
		_habitat = new char[64];
	}
	Bird(std::ifstream& in) {
		in >> _breed;
		in >> _color;
		in >> _animal_nutrition;
		in >> _habitat;
	}
	~Bird() {
		delete[] _breed;
		delete[] _color;
		delete[] _animal_nutrition;
		delete[] _habitat;
	}

	void save(std::ofstream& out) override {
		out << BIRD << std::endl;
		out << _breed << std::endl;
		out << _color << std::endl;
		out << _animal_nutrition << std::endl;
		out << _habitat << std::endl;
	}

	void show() override {
		std::cout << "Bird:" << std::endl;
		std::cout << _breed << std::endl;
		std::cout << _color << std::endl;
		std::cout << _animal_nutrition << std::endl;
		std::cout << _habitat << std::endl;
	}

	void edit() override{
		int choice;
		std::cout << "Select a characteristic" << std::endl;
		std::cout << "1. Breed" << std::cout;
		std::cout << "2. Color" << std::cout;
		std::cout << "3. Animal nutrition" << std::cout;
		std::cout << "4. Habitat" << std::cout;
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

		case 4:
			std::cin.getline(_habitat, 64);
			break;
		default:
			break;
		}
	}
};

