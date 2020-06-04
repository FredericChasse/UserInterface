#include "MainMenu.h"

using namespace userInterface;
using namespace std;


DisplayListMenu* ConfigMainMenu() {

    vector<Item*> menuItems { 
        new DisplayListItem("Item 1", 0),
        new DisplayListItem("Item 2", 1)
    };

    DisplayListMenu* mainMenu = new DisplayListMenu();

    EventMap map;
    map[Event::UP] = [&]() {
        Item* newItem = items.
    }

}