#include <iostream>

using namespace std;

const char *employees = "employees.dat";
const char *extra_hours = "extra_hours.dat";
FILE *fptr;

void menu();
void createFile(const char *files);
void updateFile(const char *files, int);
void readFile(const char *files);
void deleteFile(const char *files);
void findE(const char *files);

struct employee{
    int code;
    char name[20];
    char last_name[20];
    int phone_number;
}empData;


int main() {

    if ( (fptr = fopen(employees, "r+b" )) == NULL){
        printf( "File employees could not be opened.\n");
    printf("Creating file...\n");
    createFile(employees);

    }

    if (( fptr = fopen(extra_hours, "r+b" )) == NULL){
        printf( "File extra hours could not be opened.\n");
        printf("Creating file...\n");
        createFile(extra_hours);
    }

    menu();

}

void menu() {
    bool flag = true;
    while(flag) {
        printf("1. Add Employees\n");
        printf("2. Extra hours register\n");
        printf("3. Check employees extra hours\n");
        printf("4. Modify or delete extra hours from employees\n");
        printf("5. Check all the registers\n");
        printf("6. Exit\n");

        int ch;
        cin>>ch;
        switch(ch) {

            case 1:
                updateFile(employees, 1);
            break;
            case 2:
                findE(employees);
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                flag = false;
                break;
        }


    }

}

void createFile(const char *files) {
    fptr = fopen(files, "w+b");
    fclose(fptr);
}

void readFile(const char *files) {
    fflush(stdin);
    fptr = fopen(files, "r+b");

    int id =0;

    fread(&empData, sizeof (empData), 1, fptr);

    do{
        cout<<id<<" | " <<empData.code<< " | "<< empData.name <<" | " << empData.last_name <<" | " << empData.phone_number << endl;
        fread(&empData,sizeof(empData),1,fptr);
        id+=1;
    }while(feof(fptr)==0);
    fclose(fptr);
}

void updateFile(const char *files, int mode) {
    fptr = fopen(files, "a+b");
    char res;
    if(mode == 1) {

        do{
            fflush(stdin);
            cout<<"Enter code:";
            cin>>empData.code;
            cin.ignore();
            cout<<"Enter name: ";
            cin.getline(empData.name,20);
            cout<<"Enter last name: ";
            cin.getline(empData.last_name,20);
            cout<<"Enter phone number: ";
            cin>>empData.phone_number;
            fwrite(&empData,sizeof(empData),1,fptr);
            cout<<("Do you want to enter another employee? (y/n): ");
            cin>>res;

        }while(res=='y'|| res=='Y');

    }

    else {
        int id;
        cout<<"Enter the index id:";
        cin>>id;
        fseek(fptr,id * sizeof(empData),SEEK_SET);
        cout<<"Enter the new code: ";
        cin>>empData.code;
        cin.ignore();
        cout<<"Enter the name: ";
        cin.getline(empData.name,35);
        cout<<"Enter the last name: ";
        cin.getline(empData.last_name,35);
        cout<<"Enter the phone number: ";
        cin>>empData.phone_number;
        fwrite(&empData,sizeof(employee),1,fptr);
    }


    fclose(fptr);
    readFile(files);

}

void deleteFile(const char *files) {


}

void findE(const char *files) {
    system("cls");
    fflush(stdin);
    fptr = fopen(files, "r+b");
    int empCode;
    printf("Enter the employee code: ");
    cin>>empCode;
    while(feof(fptr)==0) {
        fread(&empData, sizeof (empData), 1, fptr);
        if(empCode == empData.code) {
            system("cls");
            printf("Found an employee with code %d\n",empCode);
            cout<< empData.name <<" | " << empData.last_name << endl;
            system("pause");
        }
    }
}

