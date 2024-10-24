#include <iostream>

using namespace std;

const char *employees = "employees.dat";
const char *extra_hours = "extra_hours.dat";
FILE *fptr;
FILE *fptr2;

void menu();
void createFile(const char *files);
void updateFile(const char *files, int);
void readFile(const char *files);
void deleteFile(const char *files);
void findE(const char *files);
void readFile2(const char *files);
void readHE(const char *files);
void modifyHours();
void deleteHours();

struct employee{
    int code;
    char name[20];
    char last_name[20];
    int phone_number;
}empData;

struct extraHours{
    int code;
    float hoursW;
    float salary;
}empSalary;


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
                readHE(extra_hours);
                break;
            case 4:
                modifyHours();
                break;
            case 5:
                readFile2(extra_hours);
                break;
            case 6:
                flag = false;
                break;
            default: ;
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
    char res;
    if(mode == 1) {

        do{
            fflush(stdin);
            cout<<"Enter code:";
            int code;
            cin>>code;
            fptr = fopen(files, "r+b");
            do {
                fread(&empData, sizeof (empData), 1, fptr);
                if(code == empData.code) {
                    printf("Code already on file, enter other code: ");
                    cin>>code;
                }
            }while(feof(fptr)==0);
            fclose(fptr);
            system("pause");
            fptr = fopen(files, "a+b");
            empData.code=code;
            cin.ignore();
            cout<<"Enter name: ";
            cin.getline(empData.name,20);
            cout<<"Enter last name: ";
            cin.getline(empData.last_name,20);
            cout<<"Enter phone number: ";
            cin>>empData.phone_number;
            fwrite(&empData,sizeof(employee),1,fptr);
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
    bool flagFound=false;
    printf("Enter the employee code: ");
    cin>>empCode;
    while(feof(fptr)==0) {
        fread(&empData, sizeof (empData), 1, fptr);
        if(empCode== empData.code) {flagFound=true; break;}
    }
        if(flagFound) {

            system("cls");
            printf("Found an employee with code %d\n",empCode);
            cout<< empData.name <<" | " << empData.last_name << endl;
            printf("Enter the extra hours: ");
            float extraH;
            cin>>extraH;

            fptr2 = fopen(extra_hours, "a+b");
            fflush(stdin);
            empSalary.code = empCode;
            empSalary.hoursW = extraH;
            empSalary.salary = 13.23 * extraH +3500;
            fwrite(&empSalary,sizeof (extraHours), 1, fptr2);
            fclose(fptr2);
        }

}

void readFile2(const char *files) {
    fflush(stdin);
    fptr2 = fopen(files, "r+b");

    int id =0;

    fread(&empSalary, sizeof (empSalary), 1, fptr2);

    do{
        cout<<id<<" | " <<empSalary.code<<" | " << empSalary.hoursW << " | " <<empSalary.salary<< endl;
        fread(&empSalary,sizeof(empSalary),1,fptr2);
        id+=1;
    }while(feof(fptr2)==0);
    fclose(fptr2);
}

void readHE(const char *files) {
    fflush(stdin);
    fptr2 = fopen(files, "r+b");
    printf("Enter the employee code: ");
    int codeS;
    cin>>codeS;
    do{
        fread(&empSalary, sizeof (empSalary), 1, fptr2);
        if(codeS == empSalary.code) {
            cout<<" | " <<empSalary.code<<" | " << empSalary.hoursW << " | " <<empSalary.salary<< endl;
        }
    }while(feof(fptr2)==0);
    fclose(fptr2);
}

void modifyHours() {
    fptr2 = fopen(extra_hours, "r+b");
    int empCode;
    bool flagFound=false;
    printf("Enter the employee code: ");
    cin>>empCode;

    while(feof(fptr2)==0) {
        fread(&empSalary, sizeof (empSalary), 1, fptr2);
        if(empCode== empSalary.code) {flagFound=true; break;}
    }
    if(flagFound) {

        fseek(fptr2,empSalary.code * sizeof(empSalary),SEEK_SET);
        cout<<"Enter the new extra hours: ";
        cin>>empSalary.hoursW;
        fwrite(&empSalary,sizeof(extraHours),1,fptr2);
    }
    fclose(fptr2);
}

void deleteHours() {
    const char * temp = "temp.dat";
    FILE *tarch = fopen(temp, "w+b");
    fptr2 = fopen(extra_hours, "r+b");
    int empCode;
    cout<<"Enter the code to delete: ";
    cin>>empCode;
    while(fread(&empSalary,sizeof(extraHours),1,fptr2)){
        if(empSalary.code !=empCode){
            fwrite(&empSalary,sizeof(extraHours),1,tarch);

        }

    }
    fclose(fptr2);
    fclose(tarch);
    remove("extra_hours.dat");
    rename("temp.dat","extra_hours.dat");

}
