#include "UserInterface.h"

using namespace std;
using namespace userInterface;

// Item
//===========================================
Item::Item() {

}
Item::~Item() {

}
int Item::RunProcess() {
    return 0;
}

// Menu
//===========================================
Menu::Menu() {

}
Menu::Menu(std::vector<Item*>& itemList, EventMap& eventMap) : items(itemList) {
    managedEvents = eventMap;
}
Menu::~Menu() {
    for (auto& item : items.List()) {
        delete item;
    }
}

void Menu::ProcessEvent(Event event) {
    auto it = managedEvents.find(event);
    if (it != managedEvents.end()) {
        managedEvents[event]();
    }
}

int Menu::RunProcesses() {
    int ret = 0;
    for (auto& item : items.List()) {
        if (item->RunProcess() < 0) {
            ret = -1;
        }
    }
    return ret;
}

void Menu::Display() {
    for (auto& item : items.List()) {
        item->Display();
    }
}

// UserInterface
//===========================================
UserInterface::UserInterface(std::vector<Menu*>& menuList, EventMap& eventMap) : menus(menuList) {
    managedEvents = eventMap;
    menus.Current()->Display();
}
UserInterface::~UserInterface() {
    for (auto& menu : menus.List()) {
        delete menu;
    }
}
void UserInterface::ProcessEvent(Event event) {
    auto it = managedEvents.find(event);
    if (it != managedEvents.end()) {
        managedEvents[event]();
    } else {
        menus.Current()->ProcessEvent(event);
    }
}
int UserInterface::RunProcesses() {
    int ret = 0;
    for (auto& menu : menus.List()) {
        if (menu->RunProcesses() < 0) {
            ret = -1;
        }
    }
    return ret;
}