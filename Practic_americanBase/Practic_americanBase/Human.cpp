#include "Human.h"
#include "Base.h"

void Human::arrive()
{
	if (isActive) throw "Human is already on the base.";
	isActive = true;
	Base::setPeople(Base::getPeople() + 1);
}

bool Human::leave()
{
	if (!isActive) return 0;
	if (Base::getPeople() <= 0) throw "No people on the base.";
	isActive = false;
	Base::setPeople(Base::getPeople() - 1);
	return 1;
}