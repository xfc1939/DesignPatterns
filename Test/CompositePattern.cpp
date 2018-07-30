//
// Created by xfc on 2018/7/14.
//

#include "../CompositePattern/CompositePattern.h"

void Test() {
    Composite composite("first");
    Leaf leaf("leaf");
    Leaf leaf1("leaf1");
    Leaf leaf2("leaf2");
    Leaf leaf3("leaf3");
    Composite composite1("sun");

    composite1.add(&leaf1);
    composite1.add(&leaf2);
    composite1.add(&leaf3);

    composite.add(&leaf);
    composite.add(&composite1);
    composite.display(0);

}

int main() {
    Test();
    return 0;
}
