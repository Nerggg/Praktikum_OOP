#include "Hero.hpp"
#include "Invoker.hpp"
#include "Axe.hpp"
#include <iostream>

int main() {
    Invoker* inv1 = new Invoker(10, 1000);
    inv1->Invoker::useSkill();
    Invoker* inv2 = new Invoker(*inv1);
    inv1->Hero::heal(1);
    Invoker* inv3 = new Invoker(50, 200);
    inv3->Invoker::move(10, 25);
    *inv3 = *inv1;
    Axe* axe1 = new Axe(200, 10);
    axe1->Axe::move(2, 20);
    axe1->Axe::heal(10);
    Axe* axe2 = new Axe(*axe1);
    // Axe* axe3 = new Axe(400, 20);
    // *axe1 + *axe2;
    Axe* axe3 = new Axe(*axe1 + *axe2);
    axe1->Axe::useSkill();
    axe3->Axe::useSkill();

    delete axe1;
    delete axe3;
    delete inv1;
}