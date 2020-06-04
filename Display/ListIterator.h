#ifndef __LIST_ITERATOR_H__
#define __LIST_ITERATOR_H__

#include <vector>

namespace userInterface {

    template<class Element>
    class ListIterator {
    public:
        ListIterator() {
            idx = 0;
        }
        ListIterator(std::vector<Element*>& listToUse) {
            for (auto const & element : listToUse) {
                if (element == nullptr) {
                    throw("ListIterator Bad usage: nullptr in constructor list");
                }
            }
            list = listToUse;
            idx = 0;
        }
        ListIterator(std::vector<Element*>& listToUse, size_t initIdx) : ListIterator(listToUse) {
            if (initIdx >= list.size()) {
                throw("ListIterator Bad usage: Start index outside of vector range.")
            }
            idx = initIdx;
        }
        Element* Current() {
            return list[idx];
        }
        Element* Next() {
            if (++idx == list.size()) {
                idx = 0;
            }
            return list[idx];
        }
        Element* Previous() {
            if (idx > 0) {
                idx--;
            } else {
                idx = list.size() - 1;
            }
            return list[idx];
        }
        const std::vector<Element*>& List() {
            return list;
        }

    private:
        std::vector<Element*> list;
        size_t idx;
    };
}





#endif