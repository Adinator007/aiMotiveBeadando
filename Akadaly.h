#pragma once
#include "Field.h"

/**
* Akadaly mezot reprezentalo osztaly.
**/
class Akadaly : public Field {
public:
    bool Accept(Lepes lepes);
    void Berak(int x, int y, std::queue<std::pair<int, int>>& sor);
};