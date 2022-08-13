#pragma once
#include "Field.h"

/**
* Ures mezot reprezentalo osztaly.
**/
class UresMezo : public Field {
public:
    bool Accept(Lepes lepes);
    void Berak(int x, int y, std::queue<std::pair<int, int>>& sor);
};