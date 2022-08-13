#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include "Field.h"
#include "Akadaly.h"
#include "Cel.h"
#include "UresMezo.h"
#include "StartMezo.h"
#include "Terkep.h"
#include "Utils.h"

int main() {
    int startX, startY; // start pozicio koordinatai (az a pozicio, ami 'T'-vel van jelolve a bemeneten)
    Terkep* terkep = beolvas(startX, startY);
    std::cout << bfs(startX, startY, terkep) << std::endl;
    /*for (int i = 0; i<3; i++) {
        for (int j=0; j<3; j++){
            std::cout<<terkep->getTavolsag(i, j)<<"\t";
        }
        std::cout<<std::endl;
    }*/
    delete terkep;
    return 0;
}

