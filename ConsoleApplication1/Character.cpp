#include "Character.h"
#include <iostream>

Character::Character(string id_)
{
	id = id_;
	health = 100;
	isReloading = false;
}

Character::~Character()
{
}

void Character::Equip(Weapon newWeapon, int possition)
{
	weapon = newWeapon;
}

int Character::GetWeaponDamage(int weaponID)
{
	return weapon.GetDamage();
}

int Character::GetWeaponAccuracy(int weaponID)
{
	return weapon.GetAccuracy();
}

void Character::Attack(Character* target)
{
	isReloading = false;

	if (weapon.GetAmmo() == 0) {
		cout << id << " is out of ammo\n";
		return;
	}
	cout << id << " Attacks!\n";

	if (rand() % 100 + 1 >= GetWeaponAccuracy(0)) {
		//Hit


		if (target->GetIsReloading()) {
			target->Damage(GetWeaponDamage(0) * 2);
			std::cout << "Critical Hit! Remaing health = " << target->GetHealth() << "\n";
		}
		else {
			target->Damage(GetWeaponDamage(0));
			std::cout << "Hit! Remaing health = " << target->GetHealth() << "\n";
		}

	}
	else {
		std::cout << "Miss!\n";
	}

	weapon.Shoot();
}

void Character::Reload()
{
	weapon.Reload();
	isReloading = true;
}

int Character::AILogic()
{

	if (weapon.IsMaxAmmo()) { return 0; }
	else if (weapon.GetAmmo() == 0) { return 1; }
	else if (rand() % 2 + 1 > weapon.GetAmmo() * 2) { return 1; }
	return 0;
}
