#include "Field.h"

Field::Field()  {
    tav = -1; // -1 jelzi, hogy meg nem talaltuk meg a legrovidebb utat a StartMezo-tol
}

/**
return value: azzal ter vissza, hogy a tavolsag szerint szabad-e erre a mezore lepni. Ha voltunk mar egy mezon, akkor oda mar nem lephetunk vissza. (BFS logika miatt.)
**/
bool Field::validateTavolsag() {
    return tav == -1;
}
void Field::setTavolsag(int tav) {
    this->tav = tav;
}
int Field::getTavolsag() {
    return tav;
}