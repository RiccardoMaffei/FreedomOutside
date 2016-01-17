FreedomOutside: build/ActionCombat.o build/Action.o build/ActionDrop.o build/ActionHeal.o build/ActionMovement.o build/ActionPickup.o build/ActionRelativeMovement.o build/ActionUnwear.o build/ActionWait.o build/ActionWear.o build/FedeList.o build/ItemArmor.o build/Item.o build/ItemDestructiveWeapon.o build/ItemHealthKit.o build/ItemSimpleWeapon.o build/ItemWeapon.o build/Map.o build/Node.o build/Player.o build/Randomizer.o build/Room.o build/StringUtils.o build/Game.o build/main.o build/ConsoleView.o build/View.o
	#create a directory
	mkdir -p build
	#linking
	g++ -o FreedomOutside build/ActionCombat.o build/Action.o build/ActionDrop.o build/ActionHeal.o build/ActionMovement.o build/ActionPickup.o build/ActionRelativeMovement.o build/ActionUnwear.o build/ActionWait.o build/ActionWear.o build/FedeList.o build/ItemArmor.o build/Item.o build/ItemDestructiveWeapon.o build/ItemHealthKit.o build/ItemSimpleWeapon.o build/ItemWeapon.o build/Map.o build/Node.o build/Player.o build/Randomizer.o build/Room.o build/StringUtils.o build/Game.o build/main.o build/ConsoleView.o build/View.o
	#rm build/*
	#rmdir build

#compiling object files
build/ActionCombat.o: model/ActionCombat.cpp model/ActionCombat.hpp model/Action.hpp model/ItemDestructiveWeapon.hpp model/FedeList.hpp model/Node.hpp model/Node.cpp model/FedeList.cpp model/ItemWeapon.hpp model/Player.hpp model/Item.hpp model/Room.hpp model/StringUtils.hpp model/ItemArmor.hpp
	mkdir -p build
	g++ -o build/ActionCombat.o -c model/ActionCombat.cpp 

build/Action.o: model/Action.cpp model/Action.hpp model/FedeList.hpp model/Node.hpp model/Node.cpp model/Node.hpp model/FedeList.cpp model/FedeList.hpp
	mkdir -p build
	g++ -o build/Action.o -c model/Action.cpp 

build/ActionDrop.o:  model/ActionDrop.cpp  model/ActionDrop.hpp  model/Action.hpp model/StringUtils.hpp model/FedeList.hpp  model/Node.hpp  model/Node.cpp  model/FedeList.cpp  model/ItemArmor.hpp model/Item.hpp model/Room.hpp
	mkdir -p build
	g++ -o build/ActionDrop.o -c model/ActionDrop.cpp 

build/ActionHeal.o:  model/ActionHeal.cpp  model/ActionHeal.hpp model/Action.hpp model/StringUtils.hpp model/FedeList.hpp  model/Node.hpp  model/Node.cpp  model/FedeList.cpp  model/Item.hpp model/Room.hpp
	mkdir -p build
	g++ -o build/ActionHeal.o -c model/ActionHeal.cpp 

build/ActionMovement.o: model/ActionMovement.cpp model/ActionMovement.hpp  model/Action.hpp model/StringUtils.hpp model/FedeList.hpp  model/Node.hpp  model/Node.cpp  model/FedeList.cpp  model/ItemArmor.hpp model/Item.hpp model/Room.hpp
	mkdir -p build
	g++ -o build/ActionMovement.o -c model/ActionMovement.cpp 

build/ActionPickup.o: model/ActionPickup.cpp model/ActionPickup.hpp model/Action.hpp model/StringUtils.hpp model/FedeList.hpp  model/Node.hpp  model/Node.cpp  model/FedeList.cpp  model/Item.hpp model/Room.hpp
	mkdir -p build
	g++ -o build/ActionPickup.o -c model/ActionPickup.cpp 

build/ActionRelativeMovement.o: model/ActionRelativeMovement.cpp model/ActionRelativeMovement.hpp model/ActionMovement.hpp model/Action.hpp model/StringUtils.hpp model/FedeList.hpp  model/Node.hpp  model/Node.cpp  model/FedeList.cpp  model/Item.hpp model/Room.hpp
	mkdir -p build
	g++ -o build/ActionRelativeMovement.o -c model/ActionRelativeMovement.cpp 

build/ActionUnwear.o: model/ActionUnwear.cpp model/ActionUnwear.hpp model/Action.hpp model/StringUtils.hpp model/FedeList.hpp  model/Node.hpp  model/Node.cpp  model/FedeList.cpp  model/Item.hpp model/ItemArmor.hpp model/Room.hpp
	mkdir -p build
	g++ -o build/ActionUnwear.o -c model/ActionUnwear.cpp 

build/ActionWait.o: model/ActionWait.cpp model/ActionWait.hpp model/FedeList.hpp  model/Node.hpp  model/Node.cpp  model/FedeList.cpp 
	mkdir -p build
	g++ -o build/ActionWait.o -c model/ActionWait.cpp 

build/ActionWear.o: model/ActionWear.cpp model/ActionWear.hpp model/Action.hpp model/StringUtils.hpp model/FedeList.hpp  model/Node.hpp  model/Node.cpp  model/FedeList.cpp  model/Item.hpp model/Room.hpp
	mkdir -p build
	g++ -o build/ActionWear.o -c model/ActionWear.cpp 

build/FedeList.o: model/FedeList.cpp model/FedeList.hpp model/Node.hpp model/Node.cpp
	mkdir -p build
	g++ -o build/FedeList.o -c model/FedeList.cpp 

build/ItemArmor.o: model/ItemArmor.cpp model/ItemArmor.hpp model/Item.hpp model/StringUtils.hpp
	mkdir -p build
	g++ -o build/ItemArmor.o -c model/ItemArmor.cpp 

build/Item.o: model/Item.cpp model/Item.hpp model/StringUtils.hpp
	mkdir -p build
	g++ -o build/Item.o -c model/Item.cpp 

build/ItemDestructiveWeapon.o: model/ItemDestructiveWeapon.cpp model/ItemDestructiveWeapon.hpp model/Item.hpp model/StringUtils.hpp model/ItemWeapon.hpp
	mkdir -p build
	g++ -o build/ItemDestructiveWeapon.o -c model/ItemDestructiveWeapon.cpp 

build/ItemHealthKit.o: model/ItemHealthKit.cpp model/ItemHealthKit.hpp model/Item.hpp model/StringUtils.hpp
	mkdir -p build
	g++ -o build/ItemHealthKit.o -c model/ItemHealthKit.cpp 

build/ItemSimpleWeapon.o: model/ItemSimpleWeapon.cpp model/ItemSimpleWeapon.hpp model/Item.hpp model/StringUtils.hpp
	mkdir -p build
	g++ -o build/ItemSimpleWeapon.o -c model/ItemSimpleWeapon.cpp 

build/ItemWeapon.o: model/ItemWeapon.cpp model/ItemWeapon.hpp model/Item.hpp model/StringUtils.hpp
	mkdir -p build
	g++ -o build/ItemWeapon.o -c model/ItemWeapon.cpp 

build/Map.o: model/Map.cpp model/Map.hpp model/Item.hpp model/StringUtils.hpp model/Item.hpp model/StringUtils.hpp model/FedeList.hpp model/Node.hpp model/Node.cpp model/FedeList.cpp 

	mkdir -p build
	g++ -o build/Map.o -c model/Map.cpp 

build/Node.o: model/Node.cpp model/Node.hpp
	mkdir -p build
	g++ -o build/Node.o -c model/Node.cpp 

build/Player.o: model/Player.cpp model/Player.hpp model/FedeList.hpp  model/Node.hpp  model/Node.cpp  model/FedeList.cpp  model/Item.hpp model/Room.hpp model/StringUtils.hpp
	mkdir -p build
	g++ -o build/Player.o -c model/Player.cpp 

build/Randomizer.o: model/Randomizer.cpp model/Randomizer.hpp model/FedeList.hpp  model/Node.hpp  model/Node.cpp  model/FedeList.cpp  model/Item.hpp model/Room.hpp model/StringUtils.hpp model/ItemWeapon.hpp model/ItemDestructiveWeapon.hpp model/ItemHealthKit.hpp
	mkdir -p build
	g++ -o build/Randomizer.o -c model/Randomizer.cpp 

build/Room.o: model/Room.cpp model/Room.hpp model/FedeList.hpp  model/Node.hpp  model/Node.cpp  model/FedeList.cpp  model/Item.hpp model/Room.hpp model/StringUtils.hpp
	mkdir -p build
	g++ -o build/Room.o -c model/Room.cpp 

build/StringUtils.o: model/StringUtils.cpp model/StringUtils.hpp
	mkdir -p build
	g++ -o build/StringUtils.o -c model/StringUtils.cpp 

build/Game.o: control/Game.cpp control/Game.hpp model/FedeList.hpp  model/Node.hpp  model/Node.cpp  model/FedeList.cpp  model/Item.hpp model/Room.hpp model/StringUtils.hpp model/ItemWeapon.hpp model/ItemDestructiveWeapon.hpp model/ItemHealthKit.hpp view/View.hpp model/Action.hpp model/Player.hpp model/Item.hpp model/ItemArmor.hpp view/ConsoleView.hpp model/Map.hpp model/ActionMovement.hpp model/ActionRelativeMovement.hpp model/ActionDrop.hpp model/ActionUnwear.hpp model/ActionWait.hpp model/ActionCombat.hpp
	mkdir -p build
	g++ -o build/Game.o -c control/Game.cpp 

build/main.o: control/main.cpp control/Game.hpp model/FedeList.hpp  model/Node.hpp  model/Node.cpp  model/FedeList.cpp  model/Item.hpp model/Room.hpp model/StringUtils.hpp view/View.hpp model/Action.hpp model/Player.hpp model/Item.hpp model/ItemArmor.hpp view/ConsoleView.hpp model/Map.hpp control/Game.hpp
	mkdir -p build
	g++ -o build/main.o -c control/main.cpp 

build/ConsoleView.o: view/ConsoleView.cpp view/ConsoleView.hpp model/FedeList.hpp model/Node.hpp model/Node.cpp model/FedeList.cpp model/Map.hpp model/Player.hpp model/Item.hpp model/Action.hpp model/ItemArmor.hpp model/StringUtils.hpp
	mkdir -p build
	g++ -o build/ConsoleView.o -c view/ConsoleView.cpp 
	
build/View.o: view/View.cpp view/View.hpp model/FedeList.hpp model/Node.hpp model/Node.cpp model/FedeList.cpp model/Action.hpp model/StringUtils.hpp model/Room.hpp model/ItemArmor.hpp model/Item.hpp model/Action.hpp
	mkdir -p build
	g++ -o build/View.o -c view/View.cpp 
