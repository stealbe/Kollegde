#pragma once
#include "Carnivore.h"
#include "Herbivore.h"
#include <vector>

class Continent {
protected:
	vector<Carnivore*> carnivores;
	vector<Herbivore*> herbivores;
public:
	Continent(vector<Carnivore*> carnivoresList, vector<Herbivore*> herbivoresList)
		: carnivores(carnivoresList), herbivores(herbivoresList) {
	}
	virtual void MealsHerbivores() const = 0;
	virtual void NutritionCarnivores() const = 0;
};