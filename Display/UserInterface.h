#ifndef __USER_INTERFACE_H__
#define __USER_INTERFACE_H__

#include <vector>
#include <map>
#include <functional>

#include "UserApp.h"
#include "ListIterator.h"

namespace userInterface {

    typedef std::map<Event, std::function<void()>> EventMap;

    class Item {
    public:
        Item();
        virtual ~Item() = 0;

        virtual int RunProcess();
        virtual void Display() = 0;
    };

    class Menu {
    public:
        Menu();
        Menu(std::vector<Item*>& itemList, EventMap& eventMap);
        virtual ~Menu() = 0;

        virtual int RunProcesses();
        virtual void ProcessEvent(Event event);
        virtual void Display();

    protected:
        ListIterator<Item> items;
        EventMap managedEvents;
    };

    class UserInterface {
    public:
        UserInterface(std::vector<Menu*>& menuList, EventMap& eventMap);
        virtual ~UserInterface() = 0;

        virtual int RunProcesses();
        virtual void ProcessEvent(Event event);

    protected:
        ListIterator<Menu> menus;
        std::map<Event, std::function<void()>> managedEvents;
    };

}


#endif