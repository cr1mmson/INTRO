#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;


int row=0,col=0;

char **p;
int **pData;
int counterN = 0;
bool flagG;

void fillMatrixView();
void fillMatrixDATA();
void clearDisplay();
bool counter(int dataPosition);
void startGame();
void playerElection();
bool checkPosition(int posR, int posC);
void delay(int seconds) {
    for (int i = (time(nullptr)+seconds); time(nullptr) != i; time(nullptr));
}

int main(){
   flagG = true;
    while(flagG==true) {

        cout<<"\n:::::TREASURE GAME:::::\n";
        cout<<"1) Start game\n";
        cout<<"2) Exit\n";
        int choice;
        cin>>choice;
        switch(choice) {
            case 1:
                system("cls");
                cout<<"\n:::::STARTING GAME:::::\n";
                startGame();
            break;
            case 2:
                flagG=false;
            break;
        }
    }

}

void startGame() {
    fillMatrixView();

}

void fillMatrixView() {
    system("cls");
    cout<<"\n::::::::GAME:::::\n";
    cout<<"Configure the game size board (n x n): \n";
    cin>>row;
    cin>>col;
    p = new char * [row];
    system("cls");
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
    srand(time(nullptr));
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

    playerElection();
}

void playerElection() {
    int rowElection = 0, colElection = 0;
    cout<<"\nFirst player attempt\n";
    cout<<"\nEnter the position you want to display(row, col): \n";
    bool flagSP = false;

    int tries = 0;
    int tries2 = 0;

    for(tries = 0; tries<3 ;tries++) {


        cin>>rowElection;
        cin>>colElection;
        while(rowElection>row-1 || colElection>col-1) {
            cout<<"\nInvalid input\n";
            cin>>rowElection;
            cin>>colElection;
        }


        if(checkPosition(rowElection, colElection)) {
            system("cls");
            cout<<"\nYou win!";
            tries = 3;
            flagSP = false;
            for (int i=0;i<row;i++) {
                cout<<endl;
                for (int j=0;j<col;j++){
                    cout<<*(*(pData+i)+j);
                }
            }
        }
        else{
            system("cls");

            string t = to_string(*(*(pData+rowElection)+colElection));
            char const *n = t.c_str();
            *(*(p+rowElection)+colElection) = *n;

            for (int i=0;i<row;i++){
                cout<<endl;
                for (int j=0;j<col;j++){
                    cout<<*(*(p+i)+j);
                }

            }
            delay(1);
            cout<<"\nTry again\n";
             flagSP = true;

        }
    }

    if(flagSP==true && tries == 3) {
        delay(2);
        system("cls");
        cout<<"\nSecond player attempt\n";
        cout<<"\nEnter the position you want to display(row, col): \n";

        for(tries2 = 0; tries2<3 ;tries2++) {

            cin>>rowElection;
            cin>>colElection;
            while(rowElection>row-1 || colElection>col-1) {
                cout<<"\nInvalid input\n";
                cin>>rowElection;
                cin>>colElection;
            }

            if(checkPosition(rowElection, colElection)) {
                cout<<"\nYou win!";
                tries2 = 3;
                for (int i=0;i<row;i++) {
                    cout<<endl;
                    for (int j=0;j<col;j++){
                        cout<<*(*(pData+i)+j);
                    }
                }
            }
            else{

                system("cls");

                string t = to_string(*(*(pData+rowElection)+colElection));
                char const *n = t.c_str();
                *(*(p+rowElection)+colElection) = *n;

                for (int i=0;i<row;i++){
                    cout<<endl;
                    for (int j=0;j<col;j++){
                        cout<<*(*(p+i)+j);
                    }

                }
                delay(1);

                cout<<"\nTry again\n";
            }
        }

    }

    if(tries == 3 && tries2 == 3) {
        system("cls");
        cout<<"\nDraw\n";
        delay(2);
    }

    cout<<"\n\nWanna play again?\n1) Yes.\n2) No.\n";
    int electionPlay;
    cin>>electionPlay;
    if(electionPlay==1) {
        system("cls");
        flagG = true;
    }
    else {
        system("cls");
        flagG = false;
    }


}

bool checkPosition(int posR, int posC) {

    if(*(*(pData+posR)+posC)==1) {
        return true;
    }
    return false;

}
