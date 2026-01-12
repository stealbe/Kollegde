#pragma once
#include "Continent.h"
#include "Carnivore.h"
#include "Herbivore.h"
#include <vector>
#include <iostream>
using namespace std;

class Africa : public Continent {
public:
	Africa(vector<Carnivore*> carnivoresList, vector<Herbivore*> herbivoresList)
		: Continent(carnivoresList, herbivoresList) {
	}
	void MealsHerbivores() const override {
		cout << "Africa Herbivores are grazing on the savannah." << endl;
		for (const auto& herbivore : herbivores) {
			if (herbivore->getIsAlive()) {
				herbivore->Eat();
			}
		}
	}
	void NutritionCarnivores() const override {
		cout << "Africa Carnivores are hunting their prey." << endl;
		for (const auto& carnivore : carnivores) {
			if (carnivore->getIsAlive()) {
				for (const auto& herbivore : herbivores) {
					if (herbivore->getIsAlive()) {
						carnivore->Eat(*herbivore);
						break;
					}
				}
			}
		}
	}
};