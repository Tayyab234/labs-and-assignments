#include <iostream>
#include<fstream>
int ID[100];
using namespace std;
ofstream COUT("D:/MARKS.DAT");
ifstream CIN("D:/STUDENT.DAT");
int TotalStudents;
int MagicNo;
double Marks[100][11], p;
double Statistics[10][11];
int presentMenu()
{
    int Choice = 0;
    
        cout << "\t Marks Manager" << endl
            << "1. Load Data" << endl
            << "2. Add" << endl
            << "3. save " << endl
            << "4. sort " << endl
            << "5. View All" << endl
            << "6. Search specific data" << endl
            << "7. Exit" << endl
            << endl << "Enter Your Choice (1-7) ";
      do{
          cin >> Choice;
          if (Choice < 0 || Choice > 7)
            cout << endl << "Please enter a valid choice between 1 and 7 " << endl;

    } while (Choice < 1 || Choice > 7);

    return Choice;
}
void Add_marks(int m) {
    int b = 0;
    for (int a = 2;a < 22;a++) {
        
        Marks[b][0] = ID[a];
        cout << "__________________________________________________" << endl;
        cout << "Please enter test 1 marks of  " << ID[a] << " : ";
        cin >> m;
        Marks[b][1] = m;
        cout << endl;
        cout << "Please enter test 2 marks of  " << ID[a] << "  : ";
        cin >> Marks[b][2];
        cout << endl;
        cout << "Please enter assignment no 1 marks of " << ID[a] << " : ";
        cin >> Marks[b][3];
        cout << endl;
        cout << "_____________________________________________________" << endl;
        b = b + 1;
    }
    cout << endl << "Please enter weightage of test 1 and test 2 and assignment no 1  : ";
    cin >> Marks[0][4];
    cout <<endl << "All student marks are enterred : For save data select  3 please " << endl;
    cout << "______________________________________________________" << endl;
    Marks[0][7] = 100;
    Marks[0][8] = 300;
}
void save(int h) {
   int sum = 0;
    for (h = 0;h < 20;h++) {
        Marks[h][5] = Marks[h][1] + Marks[h][2] + Marks[h][3];
        p = Marks[h][5];
        Marks[h][6] = p/ 300 * Marks[0][4];
    }
    for (int b = 0;b < 20;b++) {
        COUT << Marks[b][0] << "\t" << Marks[b][1] << "\t" << Marks[b][2] << "\t" << Marks[b][3] << "\t" << Marks[b][5] << "\t" << Marks[b][6] << endl;
    }
    cout << endl<<"Data of all students has saved in the file ______ MARKS.DAT _______" << endl;
    cout << "For view data of students please select 5 " << endl;
    cout << "________________________________________________" << endl;
}

int main()
{
    int Selection = 0;
    for (int a = 0;a < 22;a++) {
        CIN >> ID[a];
    }
    do {
        Selection = presentMenu();
        if (Selection == 1) {
            cout <<endl<< "________________________________________________________" << endl;
            cout << "Data is loading now " << endl;
           
            cout << "Magic Number is : " << ID[0] << endl;
            cout << "total number of students in this session is : " << ID[1] << endl;
            cout << "_____________________________________________________" << endl;
            cout << "ID's of the students are given below " << endl;
            cout << "______________________________________________________" << endl;
            for (int a = 2;a < 22;a++) {
                cout << ID[a] << endl;
            }
            cout << endl << "_____________________________________________________" << endl;
        }
        else if (Selection == 2) {
            cout << endl << "________________________________________________" << endl;
              cout << "Magic Number is : " << ID[0] << endl;
              cout << "total number of students in this session is : " << ID[1] << endl;
              cout << "_____________________________________________________" << endl;
              cout << "Add marks of all students in this session out of 100 " << endl;
              cout << "______________________________________________________" << endl;
             Add_marks(0);
        }
        else if (Selection == 3) {
            cout << endl << "___________________________________-__________" << endl;
            cout << "All Data of student marks is saving in file now " << endl;
            cout << "____________________________________________________" << endl;
            save(0);
        }
        else if (Selection == 4) {
            cout << "____________________________________" << endl;
            cout << "Data of all students are sorting now" << endl;
            cout << "______________________________________" << endl;
            cout << "Data of students has sorted : for view please select 5 " << endl;
            cout << endl << "___________________________________________________" << endl;
        }
        else if (Selection == 5) {
            cout << endl << "________________________________________________" << endl;
            cout << "Magic Number is : " << ID[0] << endl;
            cout << "total number of students in this session is : " << ID[1] << endl;
            cout << "_____________________________________________________" << endl;
            cout << "Marks and weihtage of all students are given below " << endl;
            cout << "______________________________________________________" << endl;
            cout << "|ID'S |Test 1|Test 2|Assignment 1|Max = 300 |" << Marks[0][4] << endl;
            for (int b = 0;b < 20;b++) {
                  
                cout << "___________________________________________________________________________________________________________________________________" << endl;
                cout << Marks[b][0] << "\t" << Marks[b][1] << "\t" << Marks[b][2] << "\t" << Marks[b][3] << "\t    " << Marks[b][5] << "\t    " << Marks[b][6] << endl;
                cout << "______________________________________________________________________________________________________________________________________" << endl;
            }

        }
        else if (Selection == 6) {
            int r = 0;
            cout << endl << "________________________________________________" << endl;
            cout << "Magic Number is : " << ID[0] << endl;
            cout << "total number of students in this session is : " << ID[1] << endl;
            cout << "_____________________________________________________" << endl;
            int c;
            cout << "Please enter ID of student which you can view data  " << endl;
            cin >> c;
            cout << "________________________________________________________" << endl;
            for (int a = 0;a < 20;a++) {
                if (Marks[a][0] == c) {
                    cout << "|ID'S |Test 1| Test 2|Assignment 1 |Max = 300 |" << Marks[0][4] << endl;
   

                        cout << "___________________________________________________________________________________________________________________________________" << endl;
                        cout << Marks[a][0] << "\t" << Marks[a][1] << "\t" << Marks[a][2] << "\t" << Marks[a][3] << "\t      " << Marks[a][5] << "\t     " << Marks[a][6] << endl;
                        cout << "______________________________________________________________________________________________________________________________________" << endl;
                        break;
                }
                if (Marks[a][0] != c) 
                    r = r + 1;
                
                

            }

            if (r == 19)
                cout << "Please enter correct ID of student " << endl;
        }

    } while (Selection != 7);

    return 0;
}
