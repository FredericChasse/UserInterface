#include "Display.h"

using namespace std;
using namespace userInterface;

// Display
//=========================================
Display::Display(std::vector<Menu*>& menuList, EventMap& eventMap) : UserInterface(menuList, eventMap) {

}
Display::~Display() {

}

// DisplayListMenu
//=========================================
DisplayListMenu::DisplayListMenu() {

}
DisplayListMenu::DisplayListMenu(std::string& name, std::vector<Item*>& itemList, EventMap& eventMap) : ListMenu(name, itemList, eventMap) {

}
DisplayListMenu::~DisplayListMenu() {

}

// DisplayListItem
//=========================================
DisplayListItem::DisplayListItem(std::string&& name, size_t offset) : ListItem(name, offset) {

}
DisplayListItem::~DisplayListItem() {

}
void DisplayListItem::Display() {

}