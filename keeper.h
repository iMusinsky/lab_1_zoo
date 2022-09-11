#pragma once
#include <iostream>
#include "bird.h"
#include "cat.h"
#include "fish.h"

class Keeper
{
private:
	Animal** _animals;
	unsigned int _count_of_animals;
public:
	Keeper() {
		_animals = nullptr;
	}
	~Keeper() {
		for (size_t i = 0; i < _count_of_animals; i++)	{
			delete _animals[i];
		}
		delete[] _animals;
	}

	void append_new_animal() {
		Animal* new_animal = create_new_animal();

		if (_count_of_animals == 0) {
			_animals = initialization();
			_animals[_count_of_animals - 1] = new_animal;
		}
		else {
			_animals = increase_count_of_animals();
			_animals[_count_of_animals - 1] = new_animal;
		}
	}

	void remove_animal() {
		int choice = choose_animal();

		_animals = decrease_count_of_animals(choice);
	}
	void show_list_of_animals() {
		for (size_t i = 0; i < _count_of_animals; i++) {
			std::cout << i + 1 << ". ";
			_animals[i]->show();
		}
	}
	void change_data() {
		int choice = choose_animal();

		_animals[choice - 1]->show();
		_animals[choice - 1]->edit();
	}

	void save_to_file() {
		std::ofstream out("animals.txt");
		if (!out.is_open())
			return;

		out << _count_of_animals << std::endl;
		for (size_t i = 0; i < _count_of_animals; i++)	{
			_animals[i]->save(out);
		}
	}
	void download_from_file() {
		std::ofstream in("animals.txt");
		if (!in.is_open())
			return;

		in >> _count_of_animals;
		int animal_type;
		for (size_t i = 0; i < _count_of_animals; i++)	{
			in >> animal_type;
			Animal* animal = nullptr;
			switch (animal_type)
			{
			case FISH:
				animal = new Fish(in);
				break;

			case BIRD:
				animal = new Bird(in);
				break;

			case CAT:
				animal = new Cat(in);
				break;

			default:
				break;
			}
			// сделать добавление в массив animals
		}
	}

protected:
	int choose_animal() {
		show_list_of_animals();
		int choice;
		std::cout << "Choose animal" << std::endl;
		std::cin >> choice;
		return choice;
	}

	Animal** decrease_count_of_animals(int choice) {
		Animal** temp = new Animal * [_count_of_animals - 1];

		for (size_t i = 0, j = 0; i < _count_of_animals; i++) {
			if (i == (choice - 1)) continue;
			temp[j++] = _animals[i];
		}
		--_count_of_animals;
		delete[] _animals;

		return temp;
	}

	Animal** initialization() {
		Animal** temp = new Animal * [1];
		++_count_of_animals;
		return temp;
	}

	Animal* create_new_animal() {
		int choice;
		std::cout << "Choose animal" << std::endl;
		std::cin >> choice;
		Animal* new_animal;
		switch (choice)
		{
		case FISH:
			new_animal = new Fish();
			break;

		case BIRD:
			new_animal = new Bird();
			break;

		case CAT:
			new_animal = new Cat();
			break;

		default:

			break;
		}
	}

	Animal** increase_count_of_animals() {
		Animal** temp = new Animal*[_count_of_animals + 1];

		for (size_t i = 0; i < _count_of_animals; i++)	{
			temp[i] = _animals[i];
		}
		++_count_of_animals;
		delete[] _animals;

		return temp;
	}
};
