#pragma once
#include "Field.h"

/**
* Cel mezot reprezentalo mezo. Bovithetoseg szempontjabol lett bevezetve.
**/
class Cel : public Field {
private:
    std::vector<Lepes> engedelezettLepesek;
public:
    
    Cel(char value);

    /**
    * Visszater azzal, hogy az adott lepessel be tudunk-e lepni az aktualis mezobe.
    **/
    bool Accept(Lepes lepes);

    void Berak(int x, int y, std::queue<std::pair<int, int>>& sor); // Cel-mezoknel celbaertunk, ezert ezeket a mezoket nem tesszuk bele a sorba, mert nem tudunk beloluk tovabblepni.
};