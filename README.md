Freedom Outside
===============
Freedom Outside is a simple console game for the Programming course written by:  
* Riccardo Maffei (GH: @RiccardoMaffei TW:@Riccardo_Maffei)
* Federico Bertani (GH: @federicoB)
* Danilo Branca (GH: tepiddust)

We have been asked to set the repository as private by the professors.  
**The repository will be set as public at the end of the course.**

Download
---------
The latest source of Freedom Outside can be downloaded from:
* https://github.com/RiccardoMaffei/FreedomOutside/
* https://github.com/RiccardoMaffei/FreedomOutside/archive/master.zip

Or you can clone the git repository:  
`git clone https://github.com/RiccardoMaffei/FreedomOutside.git`

How to compile
---------------
A makefile is provided with the source code.  
Running `make` in the same directory will automatically build the binary using `g++`.  
The object files are stored in ./build/ to permit incremental builds but if you don't need it you can safely delete the entire build directory.

The binary `FreedomOutside` will be generated in the current working directory.

Note that the current version of Freedom Outside is compatible with Mac and Unix-like systems.  
The compatibility with other systems has not been tested.

How to play
------------
To run the game you can simply use `./FreedomOutside` and the game will start with 4 player as default.  
If you want to customize the number of player you can use  
`./FreedomOutside --number-of-players X` or `./FreedomOutside -n X`  
putting the number of player (>1) instead of the 'X'.  
**The console width must be at least 130 character.**  
**An height of 80 character is recommended to avoid continuous scrolling.**

About the game
----------------------------
###Prologue
>Democratic Kampuchea (Cambodia), 1977.  
>Red Khmers have been in power for 2 years.  
>The police has eyes everywhere and every careless action is considered against the party.  
>Prisoners are detained in the basement of Party's palace.  
>Not everyone knows that the palace was built on the old Khmer empire's prison where there's an inhuman tradition: freedom will be given to the one who will survive to the other prisoners.  
>Your captors have just pushed you in a damp cell with other unscrupulous prisoners who will try to kill you. You should run away and immediately find a weapon.  
>Let the game begin!

###The UI
In every turn a basic interface is shown to the player.  
The interface is composed by:    
* A map
* The current prisoner's name
* The prisoner's info
* The prisoners in the room
* A list of actions
* The action result

#####The map
The map section shows the explored part of the map from the perspective of the current prisoner.
Every prisoner can view only up to 2 rooms away from his position in every direction but can't see if and where are other prisoners because the lighting system is not working properly in the old prison and the other prisoners are hidden.  
Every prisoner can see other prisoners if they are in the same room.

#####The current prisoner's name
The current prisoner number and his/her name is shown to recognize the player who should play the current turn.

#####The prisoner's info
In this section there are the basic prisoner's info such as:
* The health
* The agility
* The strength
* The inventory list
* The armor

#####The prisoners in the room
While prisoners in other rooms are hidden, you can still see prisoners in your same room. You can see their number, name and health.

#####The list of action
The list of action is the central part of the game. Everything you can do is shown in this section. You are asked to write your choice (the number of action) and press enter to execute it.

#####The action result
The action result is shown for a bit and then starts the turn of the following player.

###The game flow
Freedom Outside is a turn-based game.  
The game flow is very simple:

1. The title and the prologue is shown.
2. Every player is asked for its name.
3. While there is more than one player alive
  1. The interface is shown.
  2. The player is asked to choose his/her action choice.
  3. The action is executed.
  4. The action result is shown.
4. The winner (if there is one) is shown.

###Prisoner's statistics and damage logic
Every player has:

Property name | Default value | Min value | Max value | How to increase | How to decrease
------------- | ------------- | --------- | --------- | --------------- | ---------------
Health | 100 | 0 | 100 | heal yourself | s.b. damage you
Agility | 1.00 | 1.00 | 4.00 | move around | not implemented yet
Strength | 1.00 | 1.00 | 4.00 | combat | not implemented yet
Armor protection | no armor (1.00) | 1.00 | 4.00 | change armor | change armor

Damages are divided in given and received:
#####Given damages
Given damages are computed with the following formula:  
````
given_damages = strength * weapon_damage_value
````
In case of destructive weapon the damage value is random (between a range) and when the attacker and the attacked player are the same, the given damages are divided by the attacker agility simulating his/her agility to run away (E.g.: when throwing a grenade).

#####Received damages
Received damages are computed with the following formula:  
````
received_damages = inbound_damage / (agility * armor_protection)
````
###Actions
Actions can be summarized as follows:
* Hide yourself (wait).
* Move to north/south/east/west.
* Pickup/drop any item (according to the inventory size).
* Wear/unwear an armor.
* Combat against other prisoners using weapons.
* Heal yourself using potions.

###Items
Items are everything that can be picked up or dropped. They spawn around the map according to some probability rules.  
Items are divided as follows:

* Weapons
 * Simple weapons
 * Destructive weapons
* Health kits
* Armors

#####Weapons
Weapons are special items which can be used to combat against other players.  
Simple weapons are weapons with a standard damage value and are used against one prisoner only while destructive weapons are used against every prisoner in the room and they have a random damage value in a range.

The simple weapons are:  

Weapon name | Damage value | Probability %
----------- | ------------ | -------------
Rotten wooden plank | 1 | 21
Wooden plank | 2 | 20
Sharp wooden plank | 3 | 19
Rotten stick | 4 | 18
Stick | 5 | 17
Rusty iron pipe | 6 | 16
Iron pipe | 7 | 15
Hammer | 8 | 14
Knife | 9 | 13
Sword | 10 | 12
Spear | 15 | 11
Axe | 20 | 10
Iron mace | 30 | 9
Blowgun | 29 | 8
Bow | 25 | 7
Slingshot | 30 | 6
Hunting Bow | 35 | 5
Handgun | 45 | 4
Rifle | 60 | 3
Shotgun | 70 | 2
Ak-47 | 90 | 1

The destructive weapons are:  

Weapon name | Min damage value | Min damage value | Probability %
----------- | ---------------- | ---------------- | -------------
Molotov | 30 | 80 | 6
Grenade | 35 | 85 | 5
TNT | 50 | 100 | 2

#####Health kits
Health kits are special items which can be used to heal yourself.

They are:  

Kit name | Heal value | Probability %
-------- | ---------- | -------------
Tiny healing potion | 5 | 25
Small healing potion | 10 | 15
Medium healing potion | 30 | 5
Big healing potion | 50 | 2
Huge healing potion | 100 | 1

#####Armors
Armors are special items which can be worn and used to protect yourself against damages.

They are:  

Armor name | Protection factor | Probability %
---------- | ----------------- | -------------
Rags armor | 1.1 | 20
Leather armor | 1.2 | 18
Hide armor | 1.3 | 15
Copper armor | 1.4 | 9
Bronze armor | 1.5 | 7
Iron armor | 1.6 | 5
Steel armor | 1.7 | 3
Gold armor | 1.8 | 2
Diamond armor | 1.9 | 1

License
-------
This software is released under the GNU GPL v3.0 license.  
A copy of the license is provided in the LICENSE file.

>Copyright (C) 2016  Riccardo Maffei, Federico Bertani, Danilo Branca.

>This program is free software: you can redistribute it and/or modify
>it under the terms of the GNU General Public License as published by
>the Free Software Foundation, either version 3 of the License, or
>(at your option) any later version.

>This program is distributed in the hope that it will be useful,
>but WITHOUT ANY WARRANTY; without even the implied warranty of
>MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
>GNU General Public License for more details.

>You should have received a copy of the GNU General Public License
>along with this program.  If not, see <http://www.gnu.org/licenses/>.
