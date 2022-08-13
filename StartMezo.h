#pragma once
#include "Field.h"

/**
* A Start mezot reprezentalo mezo. Bovithetoseg szempontjabol lett bevezetve.
**/
class StartMezo : public Field {
public:
    bool Accept(Lepes lepes);
    void Berak(int x, int y, std::queue<std::pair<int, int>>& sor); // a StartMezo-re vissza nem mehetunk, ezert nem tesszuk bele az (x, y) koordinatakat a sorba.
};