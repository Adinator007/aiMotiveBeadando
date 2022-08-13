#include "Terkep.h" 

Terkep::Terkep(int n, int m) {
    this->n = n;
    this->m = m;
    // dinamikusan allokaljuk a palyat
    terep = new Field **[n];
    for (int i = 0; i < n; ++i)
        terep[i] = new Field * [m];
}

/**
* Fuggveny, amely berakja az (x, y) koordinataju mezot a sorba, ha az adott mezon meg nem voltunk es onnan tovabb tudunk lepni.
* (Celmezot nem teszunk bele a sorba, hiszen onnan nem tudunk tovabbhaladni, mert ott vege van az utvonalaknak.)
**/
void Terkep::Berak(int x, int y, std::queue<std::pair<int, int>>& sor) {
    terep[x][y]->Berak(x, y, sor);
}

/**
* Fuggveny, amely visszater a celmezok tavolsagainak osszegevel. Ha egy celmezo nem elerheto, akkor a tavolsagot 0-nak veszi.
**/
int Terkep::celMezokTavolsagOsszege() {
    int osszeg = 0;
    for (auto celMezoKoortinata : celMezok) {
        int x = celMezoKoortinata.first;
        int y = celMezoKoortinata.second;
        int tavolsag = (terep[x][y]->getTavolsag() == -1) ? 0 : (terep[x][y]->getTavolsag() - 1); // -1, azert kell, mert a leghosszabb ut nem a lepesek szamat, hanem a koztes szabad cellak szamat szamolja
        osszeg += tavolsag;
    }
    return osszeg;
}

/**
* Fuggveny, amely egy celmezot ad hozza a celmezok listajahoz.
**/
void Terkep::addCelMezo(int x, int y) {
    celMezok.push_back(std::make_pair(x, y));
}

/**
* Fuggveny, amely egy peldanyositott Field objektumot ad a 2 dimenzios terep egy cellajahoz.
**/
void Terkep::addField(int x, int y, Field* field) {
    terep[x][y] = field;
}

void Terkep::setTavolsag(int x, int y, int tav) {
    terep[x][y]->setTavolsag(tav);
}

int Terkep::getTavolsag(int x, int y) {
    return terep[x][y]->getTavolsag();
}

/**
* Fuggveny, amely visszater azzal a mezovel, ahova erkezni fogunk, ha az (x, y) mezorol a 'lepes' lepessel haladunk tovabb es beallitja az uj mezonek a tavolsagat.
* x: az aktualis (, ahonnan lepunk) mezonek az x koordinataja a palyan
* y: az aktualis (, ahonnan lepunk) mezonek az y koordinataja a palyan
* lepes: ezzel a lepessel akarunk ellepni az (x, y) koordinataju mezorol
* tav: az aktualis (, ahonnan lepunk) mezonek a tavolsaga a Start mezotol
**/
std::pair<int, int> Terkep::Leptet(int x, int y, Lepes lepes, int tav) {
    int ujX, ujY;
    if (lepes == Fel) {
        ujX = x - 1;
        ujY = y;
    }
    else if (lepes == Le) {
        ujX = x + 1;
        ujY = y;
    }
    else if (lepes == Jobb) {
        ujX = x;
        ujY = y + 1;
    }
    else { // Bal
        ujX = x;
        ujY = y - 1;
    }
    if (ValidKoordinatak(ujX, ujY) && terep[ujX][ujY]->Accept(lepes) && terep[ujX][ujY]->validateTavolsag()) { // a terkep felelossege, hogy az adott lepesirany szabad-e es, hogy van-e mar ott tavolsag kiszamitva.
        setTavolsag(ujX, ujY, tav + 1); // beallitja a tavolsagot
        return std::make_pair(ujX, ujY);
    }
    return std::make_pair(-1, -1); // Hibakod, ha nem lehet a parameterkent kapott 'lepes' iranyba ellepni
}

Terkep::~Terkep() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            delete terep[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        delete[] terep[i];
    }
    delete[] terep;
}