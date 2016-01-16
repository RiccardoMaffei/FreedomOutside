Freedom Outside
===============
Freedom Outside is a simple game for the Programming course written by:  
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
`./FreedomOutside --number-of-player X` or `./FreedomOutside -n X`  
putting the number of player (>1) instead of the 'X'.  
**The console width must be at least 130 character.**  
**An height of 80 character is recommended to avoid continuous scrolling.**

Short story and basic rules
----------------------------
###Prologue
>Democratic Kampuchea (Cambodia), 1977.  
>Red Khmers have been in power for 2 years.  
>The police have eyes everywhere and every careless action is considered against the party.  
>Prisoners are detaind in the basement of Party's palace.  
>Not everyone knows that the palace was built on the old Khmer empire's prison where there's an inhuman tradition: freedom will be given to the one who will survive to the other prisoners.  
>Your captors have just pushed you in a damp cell with other unscrupulous prisoners who will try to kill you. You should run away and immediately find a weapon.  
>Let the game begin!

###Basic rules
At the beginning, the game will ask you the name of the player called "prisoners" in the game.
