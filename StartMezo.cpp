#include "StartMezo.h"

bool StartMezo::Accept(Lepes lepes) {
    return false; // nem lehet visszalepni a StartMezo-re.
}
void StartMezo::Berak(int x, int y, std::queue<std::pair<int, int>>& sor) {} // a StartMezo-re vissza nem mehetunk, ezert nem tesszuk bele az (x, y) koordinatakat a sorba.