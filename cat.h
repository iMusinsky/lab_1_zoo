#pragma once
#include "animal.h"
#include <fstream>

class Cat : Animal
{
private:
	char* _breed;
	char* _color;
	char* _full_owner_name
	char* _name;

	
public:
	Cat() {
		_breed = new char[64];
		_color = new char[64];
		_full_owner_name = new char[64];
		_name = new char[64];
	}
	Cat(std::ifstream& in) {
		in >> _breed;
		in >> _color;
		in >> _full_owner_name;
		in >> _name;
	}
	~Cat() {
		delete[] _breed;
		delete[] _color;
		delete[] _full_owner_name;
		delete[] _name;
	}

	void save(std::ofstream& out) override {
		out << CAT << std::endl;
		out << _breed << std::endl;
		out << _color << std::endl;
		out << _full_owner_name << std::endl;
		out << _name << std::endl;
	}

	void show() override {
		std::cout << "Cat:" << std::endl;
		std::cout << _breed << std::endl;
		std::cout << _color << std::endl;
		std::cout << _full_owner_name << std::endl;
		std::cout << _name << std::endl;
	}


	void edit() override {
		int choice;
		std::cout << "Select a characteristic" << std::endl;
		std::cout << "1. Breed" << std::cout;
		std::cout << "2. Color" << std::cout;
		std::cout << "3. Full owner name" << std::cout;
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
			std::cin.getline(_full_owner_name, 64);
			break;

		case 4:
			std::cin.getline(_name, 64);
			break;
		default:
			break;
		}
	}
protected:


};