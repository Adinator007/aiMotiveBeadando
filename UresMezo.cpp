#include "UresMezo.h"

bool UresMezo::Accept(Lepes lepes) {
    return true;
}
void UresMezo::Berak(int x, int y, std::queue<std::pair<int, int>>& sor) {
    sor.push(std::make_pair(x, y)); // Ures mezorol tudunk tovabblepni, ezert be kell tennunk a sorba.
}