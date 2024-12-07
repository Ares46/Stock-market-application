#ifndef LINK_LIST_H
#define LINK_LIST_H

#include "node.h"

class link_list {
    node* head;

public:
    link_list();
    void insertion(node* a);
    void display();
    void updata_values();
};
#endif
