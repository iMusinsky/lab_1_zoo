#pragma once
#include <fstream>
#include <iostream>

enum Animals
{
	FISH,
	BIRD,
	CAT
};


class Animal
{
private:

public:
	Animal() virtual = 0;
	~Animal() virtual = 0;

	void save(std::ofstream& out) virtual = 0;
	void show() virtual = 0;
	void edit() virtual = 0;



};