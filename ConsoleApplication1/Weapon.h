#pragma once

#include <string>
class Weapon
{

public:
	Weapon();
	~Weapon();

	int GetDamage() { return damage; }
	int GetAccuracy() { return acuracy; };
	int GetAmmo() { return ammo; }
	bool IsMaxAmmo() { return ammo == maxAmmo; }
	std::string GetWeaponID() { return weaponID; }

	void Reload() { ammo = maxAmmo; }
	void Shoot() { ammo -= 1; }

protected: 

	std::string weaponID;
	int damage;
	int acuracy;
	int ammo;
	int maxAmmo;
};

