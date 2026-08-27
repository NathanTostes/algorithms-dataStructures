#include <iostream>
#include <string.h>
#include <random>
using namespace std;

void printGameTable (int gt[10][10], bool boatsRevealed[5]) {
    cout << "\n  A B C D E F G H I J\n";

    for (int i = 0; i < 10; i++) {
        cout << i;
        
        for(int j = 0; j < 10; j++) {
            if (gt[i][j] == 0) {
                cout << " X";
                continue;
            }
            if (gt[i][j] == 1 && boatsRevealed[0]) {
                if(gt[i][j-1] == 1) {
                    cout << "\u2591\u2591";
                } else {
                    cout << " \u2591";
                }
                continue;
            }
            if (gt[i][j] == 2 && boatsRevealed[1]) {
                if(gt[i][j-1] == 2) {
                    cout << "\u2592\u2592";
                } else {
                    cout << " \u2592";
                }
                continue;
            }
            if (gt[i][j] == 3 && boatsRevealed[2]) {
                if(gt[i][j-1] == 3) {
                    cout << "\u2592\u2592";
                } else {
                    cout << " \u2592";
                }
                continue;
            }
            if (gt[i][j] == 4 && boatsRevealed[3]) {
                if(gt[i][j-1] == 4) {
                    cout << "\u2593\u2593";
                } else {
                    cout << " \u2593";
                }
                continue;
            }
            if (gt[i][j] == 5 && boatsRevealed[4]) {
                if(gt[i][j-1] == 5) {
                    cout << "\u2588\u2588";
                } else {
                    cout << " \u2588";
                }
                continue;
            }
            cout << "  ";
        }

        cout << "\n";
    }
}

bool isTableBoatSizeInPositionValid(int gt[10][10], int boatSize, int orientation, int coordenate1, int coordenate2) {
    bool isValid = false;

    if(orientation == 0 && (coordenate2 - boatSize) >= 0 && (coordenate2 - boatSize) <= 9 ) {
        isValid = true;
        for(int sizeConstructed = 0; sizeConstructed < boatSize; sizeConstructed++) {
            if(gt[coordenate1][coordenate2-sizeConstructed] > 0) {
                isValid = false;
            }
        }
    } 
    if(orientation == 1 && (coordenate1 + boatSize) >= 0 && (coordenate1 + boatSize) <= 9) {
        isValid = true;
        for(int sizeConstructed = 0; sizeConstructed < boatSize; sizeConstructed++) {
            if(gt[coordenate1+sizeConstructed][coordenate2] > 0) {
                isValid = false;
            }
        }
    }
    if(orientation == 2 && (coordenate2 + boatSize) >= 0 && (coordenate2 + boatSize) <= 9) {
        isValid = true;
        for(int sizeConstructed = 0; sizeConstructed < boatSize; sizeConstructed++) {
            if(gt[coordenate1][coordenate2+sizeConstructed] > 0) {
                isValid = false;
            }
        }
    } 
    if(orientation == 3 && (coordenate1 - boatSize) >= 0 && (coordenate1 - boatSize) <= 9) {
        isValid = true;
        for(int sizeConstructed = 0; sizeConstructed < boatSize; sizeConstructed++) {
            if(gt[coordenate1-sizeConstructed][coordenate2] > 0) {
                isValid = false;
            }
        }
    }
    
    return isValid;
}

void setTableBoatSizeNumberInPosition(int gt[10][10], int boatSize, int boatNumber, int orientation, int coordenate1, int coordenate2) {
    for(int sizeConstructed = 0; sizeConstructed < boatSize; sizeConstructed++) {
        if(orientation == 0) {
            gt[coordenate1][coordenate2-sizeConstructed] = boatNumber;
        } 
        if(orientation == 1) {
            gt[coordenate1+sizeConstructed][coordenate2] = boatNumber;
        }
        if(orientation == 2) {
            gt[coordenate1][coordenate2+sizeConstructed] = boatNumber;
        } 
        if(orientation == 3) {
            gt[coordenate1-sizeConstructed][coordenate2] = boatNumber;
        }
    }
}

void populateTableWithBoatSizeNumber (int gt[10][10], int boatSize, int boatNumber) {

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> orientationDistrib(0,3);
    uniform_int_distribution<int> positionDistrib(0,9);

    bool isValidBoat = false;
    int orientation;
    int position1;
    int position2;

    while (!isValidBoat) {
        orientation = orientationDistrib(gen);
        position1 = positionDistrib(gen);
        position2 = positionDistrib(gen);
    
        isValidBoat = isTableBoatSizeInPositionValid(gt, boatSize, orientation, position1, position2);
    }

    setTableBoatSizeNumberInPosition(gt, boatSize, boatNumber, orientation, position1, position2);
}

bool isGameFinished(bool boatsRevealed[5]) {
    for(int boatNumber = 0; boatNumber < 5; boatNumber++) {
        if(!boatsRevealed[boatNumber]) {
            return false;
        }
    }

    return true;
}

void attackTarget(int gt[10][10], bool boatsRevealed[5]) {
    string target;
    bool validTarget = false;
    char validLines[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char validColumns[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int attackedLine;
    int attackedColumn;

    while(!validTarget) {
        cout << "\nAttack target using number + letter (Example: 3B): ";

        cin >> target;

        if(target.length() != 2) {
            cout << "\nInvalid target, the target has just 2 characters, line and column\n";
            continue;
        }

        char attackedLineChar = target.at(0);
        char attackedColumnChar = target.at(1);

        bool validLine = false;
        bool validColumn = false;

        for(int currentLine = 0; currentLine < 10; currentLine++) {
            if(attackedLineChar == validLines[currentLine]) {
                attackedLine = currentLine;
                validLine = true;
            }
        }
        if(!validLine) {
            cout << "\nInvalid line, write a valid line. (Example: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9)\n";
            continue;
        }

        for(int currentColumn = 0; currentColumn < 10; currentColumn++) {
            if(attackedColumnChar == validColumns[currentColumn]) {
                attackedColumn = currentColumn;
                validColumn = true;
            }
        }
        if(!validColumn) {
            cout << "\nInvalid column, write a valid column. (Example: A, B, C, D, E, F, G, H, I, J)\n";
            continue;
        }

        if(gt[attackedLine][attackedColumn] == 0) {
            cout << "\nYou just attack the same target, choose another target.\n";
            continue;
        }

        validTarget = true;
    }

    if(gt[attackedLine][attackedColumn] < 0) {
        gt[attackedLine][attackedColumn] = 0;
        cout << "\nTheres not a boat in the attack target, continue attacking\n";
    }

    if(gt[attackedLine][attackedColumn] > 0) {
        string boatNames[5] = {"Destroyer", "Cruiser", "Submarine", "Battleship", "Carrier"};

        int destroyedBoat = gt[attackedLine][attackedColumn];

        boatsRevealed[destroyedBoat - 1] = true;

        cout << "\nW, You destroyed a " << boatNames[destroyedBoat-1] << "!\n";
    }
}

int main() {
    int table[10][10] = {
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1}
    };
    
    populateTableWithBoatSizeNumber(table, 2, 1);
    populateTableWithBoatSizeNumber(table, 3, 2);
    populateTableWithBoatSizeNumber(table, 3, 3);
    populateTableWithBoatSizeNumber(table, 4, 4);
    populateTableWithBoatSizeNumber(table, 5, 5);

    bool boatsRevealed[5] = {false, false, false, false, false};
    
    while(!isGameFinished(boatsRevealed)) {
        printGameTable(table, boatsRevealed);
        attackTarget(table, boatsRevealed);
    }

    printGameTable(table, boatsRevealed);
    cout << "WWWWWWWWWW, You got this!!!\n";

    return 0;
}