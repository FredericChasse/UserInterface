#ifndef __LIST_ITEM_H__
#define __LIST_ITEM_H__

#include <string>
#include "UserInterface.h"

namespace userInterface {

    class ListItem : public Item {
    public:
        ListItem(std::string& name, size_t offset) {
            text = name;
            line = offset;
            highlightStatus = false;
        }
        virtual ~ListItem() = 0;

        virtual void SetHighlightStatus(bool state) {
            highlightStatus = state;
        }

    protected:
        size_t line;
        std::string text;
        bool highlightStatus;
    };

    ListItem::~ListItem() {}

}


#endif