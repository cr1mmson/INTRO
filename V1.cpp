#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;


int row=0,col=0;

char **p;
int **pData;
int counterN = 0;

void fillMatrixView();
void fillMatrixDATA();
void clearDisplay();
bool counter(int dataPosition);
void startGame();
void playerElection();
bool checkPosition(int posR, int posC);

int main(){

    while(true) {
        cout<<"\n:::::STARTING GAME:::::\n";
        cout<<"1) Start game";
        cout<<"2) Exit";
        
        startGame();
    }

}

void startGame() {
    fillMatrixView();

}

void fillMatrixView() {

    cin>>row;
    cin>>col;
    p = new char * [row];

    for (int i=0;i<row;i++){
        p[i] = new char[col];
    }
    for (int i=0;i<row;i++){
        for (int j=0;j<col;j++){

            *(*(p+i)+j) = '#';
        }
    }

    for (int i=0;i<row;i++){
        cout<<endl;
        for (int j=0;j<col;j++){
            cout<<*(*(p+i)+j);
        }

    }

    fillMatrixDATA();

}

void deleteMatrix() {
    for (int i=0;i<row;i++){
        delete [] p[i];
    }
    delete [] p;

}


void fillMatrixDATA() {
    srand(time(NULL));
    pData = new int * [row];

    for (int i=0;i<row;i++){
        pData[i] = new int[col];
    }
    for (int i=0;i<row;i++){
        for (int j=0;j<col;j++) {
            *(*(pData+i)+j) = 0;
        }
    }

    int rowRanPos = rand()%(row), colRanPos = rand()%(col);
    *(*(pData+rowRanPos)+colRanPos) = 1;

  //IMPRIMIR MATRIZ DE 0,1
    for (int i=0;i<row;i++) {
        cout<<endl;
        for (int j=0;j<col;j++){
            cout<<*(*(pData+i)+j);
        }
    }

    playerElection();
}

void playerElection() {
    int rowElection = 0, colElection = 0;
    cout<<"\nEnter the position you want to display(row, col): \n";

    for(int tries; tries<3 ;tries++) {

        cin>>rowElection;
        cin>>colElection;

        if(checkPosition(rowElection, colElection)) {
            cout<<"\nYou win!";
            tries = 3;
        }
        else{
            cout<<"\nTry again\n";
        }

    }

}

bool checkPosition(int posR, int posC) {

    if(*(*(pData+posR)+posC)==1) {
        return true;
    }
    return false;

}
