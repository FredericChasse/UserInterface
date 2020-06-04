#ifndef __USER_APP_H__
#define __USER_APP_H__

#include <functional>

namespace userInterface {
    /*! Define the different events of your system here. */
    enum class Event {
        LEFT,
        RIGHT,
        UP,
        DOWN,
        SELECT
    };

    /*! Change the ItemActionHandler signature by changing this typedef. */
    typedef std::function<void()> ItemActionHandler;
}


#endif 