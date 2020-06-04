#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include "UserInterface.h"
#include "ListItem.h"
#include "ListMenu.h"

using namespace userInterface;

class Display : public UserInterface {
public:
    Display(std::vector<Menu*>&, EventMap&);
    ~Display();
};

class DisplayListMenu : public ListMenu {
public:
    DisplayListMenu();
    DisplayListMenu(std::string&, std::vector<Item*>&, EventMap&) {

    }
    ~DisplayListMenu();
};

class DisplayListItem : public ListItem {
public:
    DisplayListItem(std::string&&, size_t);
    ~DisplayListItem();

    void Display();
};




#endif