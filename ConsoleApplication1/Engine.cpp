#include "Engine.h"
#include <time.h>
#include <iostream>
#include <string>


#include "Character.h"
#include "Shotgun.h"
#include "Rifle.h"
#include "Cannon.h";

Engine::Engine() : isRunning(false)
{
    //Init random time seed
    srand(time(NULL));
}

Engine::~Engine()
{
}

void Engine::Start()
{
	isRunning = true;


    int gameState = 0;

    Character p1 = Character("Player");
    Character p2 = Character("Enemy");

    cout << "Pick your weapon.\n";
    cout << "Shotgun, Rifle, Cannon\n";

    string text;
    getline(cin, text);

    if (text == "Shotgun" || "shotgun") { p1.Equip(Shotgun(), 0); }
    else if (text == "Rifle" || "rifle") { p1.Equip(Rifle(), 0); }
    else if (text == "Cannon" || "cannon") { p1.Equip(Cannon(), 0); }
    else {

    }

    int wep = rand() % 3;

    if (wep == 0) { p2.Equip(Shotgun(), 0); }
    else if (wep == 1) { p2.Equip(Rifle(), 0); }
    else if (wep == 2) { p2.Equip(Cannon(), 0); }

    cout << "Enemy chose: " << p2.GetWeaponID() << "\n";

    while (gameState == 0) {

        //input

        cout << "Your action - Attack, Reload\n" << "Ammo left: " << p1.GetWeaponAmmo(0) << "\n";
        getline(cin, text);

        if (text == "Attack" || "attack") { p1.Attack(&p2); }

        //Win condition
        if (p2.GetHealth() <= 0) { gameState = 1; break; }

        //AI

        switch (p2.AILogic()) {
        case 0: p2.Attack(&p1);
            break;
        case 1:
            p2.Reload();
            break;
        }

        //Loss condition
        if (p1.GetHealth() <= 0) { gameState = 2; break; }

        //Loop
    }

    if (gameState == 1) {
        std::cout << "Congraulations you win!";
    }
    else {
        std::cout << "Sorry you lose.";
    }

	while (isRunning) {

		//Input

		//Update

		//Render

	}
}
