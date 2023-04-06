#pragma once
#include "Weapon.h"
#include <string>

using namespace std;
class Character {


public:

	Character(string id_);
	~Character();

	void Equip(Weapon weapon, int possition);

	//Getters
	int GetWeaponDamage(int weaponID);
	int GetWeaponAccuracy(int weaponID);
	int GetWeaponAmmo(int weaponID) { return weapon.GetAmmo(); }
	int GetHealth() { return health; }
	bool GetIsReloading() { return isReloading; }
	std::string GetWeaponID() { return weapon.GetWeaponID(); }

	//Actions

	//Used to call which weapon will be used.
	void Action(string weaponID);
	void Attack(Character *target);
	void Reload();

	void Damage(int value) { health -= value; }
	

	//AI Functions

	//return indicates which action it should take.
	//0 = attack.
	//1 = reload.
	int AILogic();


private:

	string id;
	Weapon weapon;
	Weapon weapon2;

	//Atributes
	int health;
	int energy;
	int strength;
	int dexterity;


	bool isReloading;

};