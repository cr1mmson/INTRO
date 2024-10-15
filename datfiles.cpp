#include <iostream>

using namespace std;

const char *employees = "employees.dat";
const char *extra_hours = "extra_hours.dat";
FILE *fptr;

void menu();
void createFile(const char *files);
void updateFile(const char *files);
void readFile(const char *files);
void deleteFile(const char *files);

struct employee{
    int code;
    char name[20];
    char last_name[20];
    int phone_number;
}empData;


int main() {

    if (( fptr = fopen(employees, "w" )) == NULL){
        printf( "File could not be opened.\n");
    printf("Creating file...\n");
    createFile(employees);

    }

    if (( fptr = fopen(extra_hours, "w" )) == NULL){
        printf( "File could not be opened.\n");
        printf("Creating file...\n");
        createFile(extra_hours);
    }

    menu();

}

void menu() {
    printf("1. Add Employees\n");
    printf("2. Extra hours register\n");
    printf("3. Check employees extra hours\n");
    printf("4. Modify or delete extra hours from employees\n");
    printf("5. Check all the registers\n");

    int ch;
    cin>>ch;
    switch(ch) {

        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
    }

}

void createFile(const char *files) {
    fptr = fopen(files, "w+b");
    fclose(fptr);
}

void readFile(const char *files) {
    fflush(stdin);
    fptr = fopen(files, "r+b");
    if(!fptr) {
        fptr = fopen(files, "w+b");
    }

    int id =0;

    fread(&empData, sizeof (empData), 1, fptr);

    do{
        cout<<id<<" | " <<empData.code<< " | "<< empData.name <<" | " << empData.last_name <<" | " << empData.phone_number << endl;
        fread(&empData,sizeof(empData),1,fptr);
        id+=1;
    }while(feof(fptr)==0);
}

void updateFile(const char *files) {
    fptr = fopen(files, "a+b");
    char res;
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
        cout<<("Do you want to enter another employee? (y/n)");
        cin>>res;
    	
    }while(res=='y'|| res=='Y');
	
    fclose(fptr);
    readFile(files);

}

void deleteFile(const char *files) {


}
