Freedom Outside
===============
Freedom Outside is a simple console game for the Programming course written by:  
* Riccardo Maffei
* Federico Bertani
* Danilo Branca


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
>Prisoners are detaind in the basement of Party's palace.  
>Not everyone knows that the palace was built on the old Khmer empire's prison where there's an inhuman tradition: freedom will be given to the one who will survive to the other prisoners.  
>Your captors have just pushed you in a damp cell with other unscrupulous prisoners who will try to kill you. You should run away and immediately find a weapon.  
>Let the game begin!

###The UI
In every turn a basic interface is shown to the player.  
The interface is composed by:    
* a map
* The current prisoner's name
* The prisoner's info
* The prisoners in the room
* A list of actions
* The action result

#####The map
The map section shows the explored part of the map from the perspective of the current prisoner.
Every prisoner can view only up to 2 rooms away from his position in every direction but can't see if and where are other prisoners because the lighting system is not working propely in the old prison and the other prisoners are hidden.  
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
In case of destructive weapon the damage value is random (between a range) and when the attacker and the attacked player are the same, the given damages are divided by the attacker agility simulating his/her agility to run away (E.g.: when throwing a granade).

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
Items are divided as follows:

* Weapons
 * Simple weapons
 * Destructive weapons
* Health kits
* Armors

#####Weapons

#####Health kits

#####Armors