#include "Cel.h"
#include "Utils.h"
#include <iostream>

Cel::Cel(char value): Field() {
    int v = charToHex(value);
    /*
    Bitwise maszkolassal elemezzuk, hogy milyen iranybol nyitottak a mezok.
    */
    if (v & 0x1) {
        engedelezettLepesek.push_back(Bal); // Azert kerul ide Bal, nem pedig Jobb, mint a feladatleirasban, mert azt taroljuk, hogy milyen lepessel lephetunk be. Nem pedig azt, hogy melyik iranyba nyitott az adott Cel mezo.
    }
    if (v & 0x2) {
        engedelezettLepesek.push_back(Le);
    }
    if (v & 0x4) {
        engedelezettLepesek.push_back(Jobb);
    }
    if (v & 0x8) {
        engedelezettLepesek.push_back(Fel);
    }
}

/**
* Visszater azzal, hogy az adott lepessel be tudunk-e lepni az aktualis mezobe.
**/
bool Cel::Accept(Lepes lepes) {
    return count(engedelezettLepesek.begin(), engedelezettLepesek.end(), lepes) != 0;
}

void Cel::Berak(int x, int y, std::queue<std::pair<int, int>>& sor) {} // Cel-mezoknel celbaertunk, ezert ezeket a mezoket nem tesszuk bele a sorba, mert nem tudunk beloluk tovabblepni.