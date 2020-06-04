#ifndef __LIST_MENU_H__
#define __LIST_MENU_H__

#include <string>
#include "UserInterface.h"
#include "ListItem.h"

namespace userInterface {

    class ListMenu : public Menu {
    public:
        ListMenu();
        ListMenu(std::string& name, 
                 std::vector<Item*>& itemList, 
                 EventMap& eventMap)
               : Menu(itemList, eventMap) {
            text = name;
        }
        virtual ~ListMenu() = 0;

    protected:
        std::string text;
    };

    ListMenu::~ListMenu() {}

}


#endif