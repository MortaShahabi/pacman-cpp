#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <cmath>

using namespace std;

const int Rows = 22;
const int Cols = 40;

int itemCounter = 0;

// Fire

int f1x = -1, f1y = -1, f2x = -1, f2y = -1, f3x = -1, f3y = -1, f4x = -1, f4y = -1, f5x = -1, f5y = -1;

char originalMap[Rows][Cols] = {
    { '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    { '#','P','.','.','.','.','.','.','.','0','#','.','.','#','.','.','#','.','.','.','.','.','B','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
    { '#','.','.','#','#','#','#','#','#','.','#','.','.','#','.','.','#','.','.','.','.','.','#','#','#','#','#','#','#','#','#','.','.','.','.','.','.','.','.','#'},
    { 'T','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','#','#','#','.','.','.','0','.','.','#','#','.','.','#','#','#','#','.','.','T'},
    { 'T','.','#','.','.','.','.','#','#','#','#','#','#','#','#','.','.','#','.','.','.','.','#','.','.','#','#','#','.','#','#','.','.','.','.','0','.','.','.','T'},
    { 'T','.','#','.','.','.','.','B','.','.','.','#','.','.','.','.','#','#','.','#','.','.','=','.','.','.','.','.','.','#','#','.','.','#','#','#','#','.','.','T'},
    { 'T','.','#','.','#','.','.','#','.','.','.','#','.','.','.','.','.','.','.','#','.','.','#','.','.','#','.','.','.','0','#','.','.','.','.','.','.','.','.','T'},
    { 'T','.','.','.','#','.','.','#','.','.','.','#','.','.','.','.','#','#','.','.','.','#','#','.','.','#','.','#','#','#','#','.','.','#','#','#','#','.','.','T'},
    { '#','.','.','.','#','.','0','#','#','#','#','#','#','#','#','.','.','#','-','-','-','-','#','.','.','#','.','#','.','0','#','.','.','.','#','.','.','.','.','#'},
    { '#','#','#','.','#','.','.','.','.','.','#','.','.','.','.','.','.','#','#','-','-','#','#','.','.','#','.','#','.','.','.','.','.','.','#','.','.','#','.','#'},
    { '#','.','.','.','#','.','.','#','.','.','.','.','0','#','.','#','.','#','S','-','-','-','#','.','.','.','.','#','.','.','.','.','.','.','.','.','K','#','.','#'},
    { '#','0','.','.','#','.','.','#','#','#','#','#','#','#','.','#','.','#','#','#','#','#','#','.','.','.','.','#','.','.','#','.','.','.','#','.','.','#','.','#'},
    { '#','#','#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','0','#','#','#','#','.','K','.','.','.','#','.','.','B','.','.','.','#','0','.','.','.','#'},
    { '#','.','.','.','#','#','#','B','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','=','#','#','#','#','#','#','.','#','#','#','#','.','#'},
    { 'T','.','.','.','#','.','.','.','.','#','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','.','.','.','.','.','#','.','.','.','.','.','.','.','.','T'},
    { 'T','.','#','.','#','0','.','.','.','#','.','#','#','#','.','.','#','#','#','.','.','.','#','.','.','.','.','.','#','.','#','0','.','.','.','.','.','.','.','T'},
    { 'T','.','#','.','#','#','#','#','#','#','.','.','#','.','.','.','.','0','.','.','#','.','.','.','.','.','.','.','#','.','#','#','#','#','#','#','.','.','.','T'},
    { 'T','.','#','.','#','.','.','.','.','.','.','.','#','.','#','#','#','#','#','.','.','#','#','#','.','#','#','.','#','.','.','.','.','.','.','#','.','.','.','T'},
    { 'T','.','.','.','#','.','#','#','.','.','.','.','.','.','.','.','.','#','.','.','.','.','.','.','.','#','#','.','#','.','.','.','#','#','.','#','.','.','.','T'},
    { '#','#','#','#','#','.','#','#','.','.','.','#','#','#','.','0','.','.','.','.','#','.','#','.','.','.','#','.','.','.','.','.','#','#','.','#','#','#','#','#'},
    { '#','0','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#','.','#','.','.','.','B','.','.','.','.','.','.','.','.','.','.','.','0','#'},
    { '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}
};

char map[Rows][Cols] = {
    { '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    { '#','P','.','.','.','.','.','.','.','0','#','.','.','#','.','.','#','.','.','.','.','.','B','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
    { '#','.','.','#','#','#','#','#','#','.','#','.','.','#','.','.','#','.','.','.','.','.','#','#','#','#','#','#','#','#','#','.','.','.','.','.','.','.','.','#'},
    { 'T','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','#','#','#','.','.','.','0','.','.','#','#','.','.','#','#','#','#','.','.','T'},
    { 'T','.','#','.','.','.','.','#','#','#','#','#','#','#','#','.','.','#','.','.','.','.','#','.','.','#','#','#','.','#','#','.','.','.','.','0','.','.','.','T'},
    { 'T','.','#','.','.','.','.','B','.','.','.','#','.','.','.','.','#','#','.','#','.','.','=','.','.','.','.','.','.','#','#','.','.','#','#','#','#','.','.','T'},
    { 'T','.','#','.','#','.','.','#','.','.','.','#','.','.','.','.','.','.','.','#','.','.','#','.','.','#','.','.','.','0','#','.','.','.','.','.','.','.','.','T'},
    { 'T','.','.','.','#','.','.','#','.','.','.','#','.','.','.','.','#','#','.','.','.','#','#','.','.','#','.','#','#','#','#','.','.','#','#','#','#','.','.','T'},
    { '#','.','.','.','#','.','0','#','#','#','#','#','#','#','#','.','.','#','-','-','-','-','#','.','.','#','.','#','.','0','#','.','.','.','#','.','.','.','.','#'},
    { '#','#','#','.','#','.','.','.','.','.','#','.','.','.','.','.','.','#','#','-','-','#','#','.','.','#','.','#','.','.','.','.','.','.','#','.','.','#','.','#'},
    { '#','.','.','.','#','.','.','#','.','.','.','.','0','#','.','#','.','#','S','-','-','-','#','.','.','.','.','#','.','.','.','.','.','.','.','.','K','#','.','#'},
    { '#','0','.','.','#','.','.','#','#','#','#','#','#','#','.','#','.','#','#','#','#','#','#','.','.','.','.','#','.','.','#','.','.','.','#','.','.','#','.','#'},
    { '#','#','#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','0','#','#','#','#','.','K','.','.','.','#','.','.','B','.','.','.','#','0','.','.','.','#'},
    { '#','.','.','.','#','#','#','B','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','=','#','#','#','#','#','#','.','#','#','#','#','.','#'},
    { 'T','.','.','.','#','.','.','.','.','#','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','.','.','.','.','.','#','.','.','.','.','.','.','.','.','T'},
    { 'T','.','#','.','#','0','.','.','.','#','.','#','#','#','.','.','#','#','#','.','.','.','#','.','.','.','.','.','#','.','#','0','.','.','.','.','.','.','.','T'},
    { 'T','.','#','.','#','#','#','#','#','#','.','.','#','.','.','.','.','0','.','.','#','.','.','.','.','.','.','.','#','.','#','#','#','#','#','#','.','.','.','T'},
    { 'T','.','#','.','#','.','.','.','.','.','.','.','#','.','#','#','#','#','#','.','.','#','#','#','.','#','#','.','#','.','.','.','.','.','.','#','.','.','.','T'},
    { 'T','.','.','.','#','.','#','#','.','.','.','.','.','.','.','.','.','#','.','.','.','.','.','.','.','#','#','.','#','.','.','.','#','#','.','#','.','.','.','T'},
    { '#','#','#','#','#','.','#','#','.','.','.','#','#','#','.','0','.','.','.','.','#','.','#','.','.','.','#','.','.','.','.','.','#','#','.','#','#','#','#','#'},
    { '#','0','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#','.','#','.','.','.','B','.','.','.','.','.','.','.','.','.','.','.','0','#'},
    { '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}
};

int dotCounter(){
    int dotCounter = 0;
    for(int i = 0; i < Rows; i++){
        for (int j = 0; j < Cols; j++){
            if (map[i][j] == '.'){
                dotCounter++;
            }
        }
    }
    return dotCounter;
}

void resetGame(int &score, int &lives, int &px, int &py, int &sx, int &sy, char &sUnder, int &remDots, bool &hasKey, bool &powerMode, int &powerTurns, bool &invincible, int &invTurns, bool &pepperMode, int &pepperTurns, int &turn, int &move){
    score = 0;
    lives = 3;
    itemCounter = 0;
    turn = 0;
    move = 0;
    hasKey = false;

    powerMode = false;
    powerTurns = 0;

    invincible = false;
    invTurns = 0;

    pepperMode = false;
    pepperTurns = 0;

    sUnder = '-';

    f1x = -1;
    f1y = -1;
    f2x = -1;
    f2y = -1;
    f3x = -1;
    f3y = -1;
    f4x = -1;
    f4y = -1;
    f5x = -1;
    f5y = -1;


    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            map[i][j] = originalMap[i][j];
            if (map[i][j] == 'P') {
                px = i;
                py = j;
            }
            if (map[i][j] == 'S') {
                sx = i;
                sy = j;
            }
        }
    }

    remDots = dotCounter();
}

void Fire1(int turn){

    if(turn >= 20){

        if(turn % 5 == 0){

            while(true){
                f1x = rand() % Rows;
                f1y = rand() % Cols;
                if(map[f1x][f1y] == ' ') break;
            }
            map[f1x][f1y] = '@';
        }

        if(turn % 5 == 4 && map[f1x][f1y] == '@'){
            map[f1x][f1y] = ' ';
        }
    }

}

void Fire2(int turn){

    if(turn >= 25){

        if(turn % 5 == 1){

            while(true){
                f2x = rand() % Rows;
                f2y = rand() % Cols;
                if(map[f2x][f2y] == ' ') break;
            }
            map[f2x][f2y] = '@';
        }

        if(turn % 5 == 0 && map[f2x][f2y] == '@'){
            map[f2x][f2y] = ' ';
        }
    }

}

void Fire3(int turn){

    if(turn >= 30){

        if(turn % 5 == 2){

            while(true){
                f3x = rand() % Rows;
                f3y = rand() % Cols;
                if(map[f3x][f3y] == ' ') break;
            }
            map[f3x][f3y] = '@';
        }

        if(turn % 5 == 1 && map[f3x][f3y] == '@'){
            map[f3x][f3y] = ' ';
        }
    }

}

void Fire4(int turn){

    if(turn >= 35){

        if(turn % 5 == 3){

            while(true){
                f4x = rand() % Rows;
                f4y = rand() % Cols;
                if(map[f4x][f4y] == ' ') break;
            }
            map[f4x][f4y] = '@';
        }

        if(turn % 5 == 2 && map[f4x][f4y] == '@'){
            map[f4x][f4y] = ' ';
        }
    }

}

void Fire5(int turn){

    if(turn >= 40){

        if(turn % 5 == 4){

            while(true){
                f5x = rand() % Rows;
                f5y = rand() % Cols;
                if(map[f5x][f5y] == ' ') break;
            }
            map[f5x][f5y] = '@';
        }

        if(turn % 5 == 3 && map[f5x][f5y] == '@'){
            map[f5x][f5y] = ' ';
        }
    }

}

void respawn(int &px, int &py, int &sx, int &sy, char &sUnder, bool powerMode){
    if (!powerMode){
        //Respawn P
        if(!(sx == px && sy == py)){
            map[px][py] = ' ';
        }
        
        for (int i = 0; i < Rows; i++){
            for (int j = 0; j < Cols; j++){
                if (originalMap[i][j] == 'P'){
                    px = i; py = j;
                    map[i][j] = 'P';
                }
            }
        }

        sUnder = ' ';
    }
    else {
        //Respawn S
        map[sx][sy] = sUnder;
        for (int i = 0; i < Rows; i++){
            for (int j = 0; j < Cols; j++){
                if (originalMap[i][j] == 'S'){
                    sx = i; sy = j;
                    map[i][j] = 'S';
                    sUnder = '-';
                }
            }
        }
    }
}

void itemGiver(bool validMove){

    int itemC;
    int itemH;
    int itemV;
    int itemA;
    int itemF;
    int itemM;
    int itemL;

    if(validMove && itemCounter < 7){

        // Cherry: C
        
        itemC = rand() % 5;

        if(itemC == 1){
            int cx, cy;
            while(true){
                cx = rand() % Rows;
                cy = rand() % Cols;
                if(map[cx][cy] == ' ' && originalMap[cx][cy] != 'P') break;
            }
            map[cx][cy] = 'C';
            itemCounter++;
        }

        // Strawberry: H
        
        itemH = rand() % 10;

        if(itemH == 2){
            int hx, hy;
            while(true){
                hx = rand() % Rows;
                hy = rand() % Cols;
                if(map[hx][hy] == ' ' && originalMap[hx][hy] != 'P') break;
            }
            map[hx][hy] = 'H';
            itemCounter++;
        }

        // Grape: V
        
        itemV = rand() % 10;

        if(itemV == 3){
            int vx, vy;
            while(true){
                vx = rand() % Rows;
                vy = rand() % Cols;
                if(map[vx][vy] == ' ' && originalMap[vx][vy] != 'P') break;
            }
            map[vx][vy] = 'V';
            itemCounter++;
        }

        // Apple: A
        
        itemA = rand() % 20;

        if(itemA == 4){
            int ax, ay;
            while(true){
                ax = rand() % Rows;
                ay = rand() % Cols;
                if(map[ax][ay] == ' ' && originalMap[ax][ay] != 'P') break;
            }
            map[ax][ay] = 'A';
            itemCounter++;
        }

        // Pepper: F
        
        itemF = rand() % 20;

        if(itemF == 6){
            int fx, fy;
            while(true){
                fx = rand() % Rows;
                fy = rand() % Cols;
                if(map[fx][fy] == ' ' && originalMap[fx][fy] != 'P') break;
            }
            map[fx][fy] = 'F';
            itemCounter++;
        }

        // Mushroom: M
        
        itemM = rand() % 50;

        if(itemM == 1){
            int mx, my;
            while(true){
                mx = rand() % Rows;
                my = rand() % Cols;
                if(map[mx][my] == ' ' && originalMap[mx][my] != 'P') break;
            }
            map[mx][my] = 'M';
            itemCounter++;
        }

        // Maple Leaf: L
        
        itemL = rand() % 100;

        if(itemL == 7){
            int lx, ly;
            while(true){
                lx = rand() % Rows;
                ly = rand() % Cols;
                if(map[lx][ly] == ' ' && originalMap[lx][ly] != 'P') break;
            }
            map[lx][ly] = 'L';
            itemCounter++;
        }

    }
}


void drawMap(){
    for (int i = 0; i < Rows; i++){
        for (int j = 0; j < Cols; j++){
            if (map[i][j] == '#'){
                cout << "\U0001F9F1";
            }
            else if (map[i][j] == 'T'){
                cout << "\U0001F504";
            }
            else if (map[i][j] == '@'){
                cout << "\U0001F525";
            }
            else if (map[i][j] == 'C'){
                cout << "\U0001F352";
            }
            else if (map[i][j] == 'H'){
                cout << "\U0001F353";
            }
            else if (map[i][j] == 'V'){
                cout << "\U0001F347";
            }
            else if (map[i][j] == 'A'){
                cout << "\U0001F34F";
            }
            else if (map[i][j] == 'F'){
                cout << "\U0001F360";
            }
            else if (map[i][j] == 'M'){
                cout << "\U0001F344";
            }
            else if (map[i][j] == 'L'){
                cout << "\U0001F341";
            }
            else if (map[i][j] == 'P'){
                cout << "\U0001F61B";
            }
            else if (map[i][j] == 'S'){
                cout << "\U0001F47B";
            }
            else if (map[i][j] == '0'){
                cout << "\U0001F535";
            }
            else if (map[i][j] == '.'){
                cout << "\U0001F538";
            }
            else if (map[i][j] == '-'){
                cout << "\U0001F7E8";
            }
            else if (map[i][j] == 'K'){
                cout << "\U0001F511";
            }
            else if (map[i][j] == '='){
                cout << "\U0001F6AA";
            }
            else if (map[i][j] == ' '){
                cout << "\U0001F7E9";
            }
            else if (map[i][j] == 'B'){
                cout << "\U0001FA9F ";
            }
        }
        cout << endl;
    }
}

void teleport(int &x, int &y){
    // L
    if (y == 0) {
        y = Cols - 2;
    }
    // R
    else if (y == Cols - 1) {
        y = 1;
    }
}

bool movePacman(char moveP, bool &validMove, int &px, int &py, int &score, int &remDots, int &move, int &lives, bool &powerMode, int &powerTurns, bool &invincible, int &invTurns, bool &pepperMode, int &pepperTurns, bool &hasKey, int &sx, int &sy, char &sUnder){

    int newPx = px;
    int newPy = py;

    if (moveP == 'W' || moveP == 'w') newPx--;
    else if (moveP == 'S' || moveP == 's') newPx++;
    else if (moveP == 'A' || moveP == 'a') newPy--;
    else if (moveP == 'D' || moveP == 'd') newPy++;
    else validMove = false;

    if (!validMove) return false;

    if (map[newPx][newPy] == '#' || map[newPx][newPy] == '-' || (map[newPx][newPy] == '=' && !hasKey)){
        return false;
    }
    
    if (map[newPx][newPy] == 'C') {
        score += 100;
        itemCounter--;
    }

    if (map[newPx][newPy] == 'H') {
        score += 300;
        itemCounter--;
    }

    if (map[newPx][newPy] == 'V') {
        score += 500;
        itemCounter--;
    }

    if (map[newPx][newPy] == 'A') {
        score += 700;
        itemCounter--;
    }

    if (map[newPx][newPy] == 'F') {
        pepperMode = true;
        pepperTurns = 10;
        itemCounter--;
    }

    if (map[newPx][newPy] == 'M') {
        lives++;
        itemCounter--;
    }

    if (map[newPx][newPy] == 'L') {
        score += 1000;
        invincible = true;
        invTurns += 10;
        itemCounter--;
    }

    if(map[newPx][newPy] == '@' && !invincible && !pepperMode) {
        lives--;
    }

    if (map[newPx][newPy] == 'T') {
        teleport(newPx, newPy);
    }

    if (map[newPx][newPy] == 'S') {
        if (powerMode) {
            score += 50;
            respawn(px, py, sx, sy, sUnder, powerMode);
        } 
        else{
            if(!invincible){
                lives--;
                respawn(px, py, sx, sy, sUnder, powerMode);

                invincible = true;
                invTurns = 5;
            }
        }

        return true;
    }

    if (map[newPx][newPy] == '.'){
        score++;
        remDots--;
    }
    if (map[newPx][newPy] == '0'){
        score += 10;
        powerMode = true;
        powerTurns = 15;
    }
    
    if(map[newPx][newPy] == 'B'){
        map[newPx][newPy] = ' ';
        
        newPx = px;
        newPy = py;
    }

    if(map[newPx][newPy] == 'K'){
        hasKey = true;
    }
    
    if(map[newPx][newPy] == '=' && hasKey){
        hasKey = false;
    }

    map[px][py] = ' ';
    px = newPx;
    py = newPy;
    map[px][py] = 'P';

    move++;
    

    return true;
}


void sGhostMove(int &sx, int &sy, char &sUnder){
    int moveS;
    int newSx, newSy;

    while (true) {
        moveS = rand() % 4;

        newSx = sx;
        newSy = sy;

        if (moveS == 0) newSx--;        // up
        else if (moveS == 1) newSx++;   // down
        else if (moveS == 2) newSy--;   // left
        else if (moveS == 3) newSy++;   // right

        if (map[newSx][newSy] != '#' && map[newSx][newSy] != '=' && map[newSx][newSy] != 'B'){
            break;
        }
    }

    if (map[newSx][newSy] == 'T') {
        teleport(newSx, newSy);
    }


    map[sx][sy] = sUnder;
    sUnder = map[newSx][newSy];

    sx = newSx;
    sy = newSy;
    map[sx][sy] = 'S';
}


void gameStateBar(int score, int lives, int remDots, int move, bool powerMode, int powerTurns, bool invincible, int invTurns, bool hasKey, bool &pepperMode, int &pepperTurns){
    cout << "Score: " << score << " | Lives: ";

    for(int i = 0; i < lives; i++){
        cout << "\u2665" << " ";
    }

    cout << "| Dots left: " << remDots << " | Moves: " << move;

    if (hasKey){
        cout << " | You have a KEY";
    }

    if (pepperMode){
        cout << " | PEPPER! (" << pepperTurns << ")";
    }

    if (powerMode){
        cout << " | POWER (" << powerTurns << ")";
    }

    if (invincible){
        cout << " | INVINCIBLE (" << invTurns << ")";
    }

    cout << endl;
}


void turnsUpdater(bool validMove, int &turn, bool &powerMode, int &powerTurns, bool &invincible, int &invTurns, bool &pepperMode, int &pepperTurns){
    if(validMove){

        turn++;

        if (powerMode) {
            powerTurns--;
            if (powerTurns == 0) {
                powerMode = false;
            }
        }

        if (pepperMode) {
            pepperTurns--;
            if (pepperTurns == 0) {
                pepperMode = false;
            }
        }

        if (invincible) {
            invTurns--;
            if (invTurns == 0) {
                invincible = false;
            }
        }

    }
}

void symbolLegend(){
    cout << "******************************" << endl;
    cout << "*        SYMBOL LEGEND       *" << endl;
    cout << "******************************" << endl;
    cout << "* P : Pac-Man                *" << endl;
    cout << "* S : Simple Ghost           *" << endl;
    cout << "* # : Wall                   *" << endl;
    cout << "* . : Dot                    *" << endl;
    cout << "* 0 : Power Pellet           *" << endl;
    cout << "* B : Breakable Wall         *" << endl;
    cout << "* K : Key                    *" << endl;
    cout << "* = : Door                   *" << endl;
    cout << "* T : Tunnel                 *" << endl;
    cout << "* C : Cherry                 *" << endl;
    cout << "* H : Strawberry             *" << endl;
    cout << "* V : Grape                  *" << endl;
    cout << "* A : Apple                  *" << endl;
    cout << "* F : Pepper                 *" << endl;
    cout << "* M : Mushroom               *" << endl;
    cout << "* L : Maple Leaf             *" << endl;
    cout << "* @ : Fire                   *" << endl;
    cout << "******************************";
    
}

int main(){

    SetConsoleOutputCP(CP_UTF8);
    srand(time(0));

    int itemDots = dotCounter();
    int remDots = dotCounter();
    int turn = 0;
    int move = 0;
    int score = 0;
    int lives = 3;

    bool powerMode = false;
    int powerTurns = 0;

    bool invincible = false;
    int invTurns = 0;

    bool pepperMode = false;
    int pepperTurns = 0;


    bool hasKey = false;

    bool running = true;

    char firstChoice;
    cout << "Press L to see the symbol legend, or ANYTHING ELSE to start: ";
    cin >> firstChoice;

    if(firstChoice == 'L' || firstChoice == 'l'){
        while(true){
            system("cls");
            cout << endl;
            symbolLegend();
            cout << endl << endl << "Now press ANYTHING but L to start: ";
            cin >> firstChoice;
            if(!(firstChoice == 'L' || firstChoice == 'l')) break;
        }
    }


        //Pac-Man : P

    int px, py;

    for (int i = 0; i < Rows; i++){
        for (int j = 0; j < Cols; j++){
            if (map[i][j] == 'P'){
                px = i;
                py = j;
                break;
            }
        }
    }

        //Simple Ghost : S
    
    char sUnder = '-';

    int sx, sy;

    for (int i = 0; i < Rows; i++){
        for (int j = 0; j < Cols; j++){
            if (map[i][j] == 'S'){
                sx = i;
                sy = j;
                break;
            }
        }
    }

    while (running){
        system("cls");

        gameStateBar(score, lives, remDots, move, powerMode, powerTurns, invincible, invTurns, hasKey, pepperMode, pepperTurns);

        bool validMove = true;

        // Items System

        if(remDots < itemDots-20){
            itemGiver(validMove);
        }

        // Fire System

        Fire1(turn);
        Fire2(turn);
        Fire3(turn);
        Fire4(turn);
        Fire5(turn);


        drawMap();

        char moveP;
        cout << "Move by (W A S D), or Q to quit: ";
        cin >> moveP;
        if (moveP == 'Q' || moveP == 'q'){
            running = false;
        }

        bool hasMoved = movePacman(moveP, validMove, px, py, score, remDots, move, lives, powerMode, powerTurns, invincible, invTurns, pepperMode, pepperTurns, hasKey, sx, sy, sUnder);

        if(pepperMode && hasMoved){
            movePacman(moveP, validMove, px, py, score, remDots, move, lives, powerMode, powerTurns, invincible, invTurns, pepperMode, pepperTurns, hasKey, sx, sy, sUnder);
        }

        if(validMove){
            sGhostMove(sx, sy, sUnder);
            if (sx == px && sy == py) {
                if (powerMode) {
                    score += 50;
                    respawn(px, py, sx, sy, sUnder, powerMode);
                    continue;
                } 
                else{
                    if(!invincible){
                        lives--;

                        respawn(px, py, sx, sy, sUnder, powerMode);

                        invincible = true;
                        invTurns = 5;
                    }
                    continue;
                }
            }
        }

        turnsUpdater(validMove, turn, powerMode, powerTurns, invincible, invTurns, pepperMode, pepperTurns);

        char finalChoice;

                //Lose Condition

        if (lives == 0){
            system("cls");
            drawMap();
            cout << "\nGAME OVER\nFinal Score: " << score << endl;
            cout << "Press R to restart or Q to quit: ";
            cin >> finalChoice;

            if (finalChoice == 'R' || finalChoice == 'r'){
                resetGame(score, lives, px, py, sx, sy, sUnder, remDots, hasKey, powerMode, powerTurns, invincible, invTurns, pepperMode, pepperTurns, turn, move);
                continue;
            } 
            else{
                break;
            }
        }

                //Win Conditin

        if (remDots == 0){
            system("cls");
            drawMap();
            cout << endl << "YOU WON! Final score: " << score << endl;
            cout << "Press R to restart or Q to quit: ";
            cin >> finalChoice;

            if (finalChoice == 'R' || finalChoice == 'r'){
                resetGame(score, lives, px, py, sx, sy, sUnder, remDots, hasKey, powerMode, powerTurns, invincible, invTurns, pepperMode, pepperTurns, turn, move);
                continue;
            }
            else{
                break;
            }
        }

    }
    return 0;
}
