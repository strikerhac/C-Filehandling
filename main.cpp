#include <iostream>
#include <fstream>
#include <cstdio>
#include<bits/stdc++.h>
using namespace std;

// function declaration
void deleterecord(string regnum);
void displaystudentlist();

typedef struct
    {
	   string regnum;
	   string name;
	   string clas;
	   string month;
       string fees;
	}student;

int main()
{
	student mystud;
	string line;
	ofstream file;
    int i;

    cout << "Add:1 | Delete:2 | Display:3" << endl;
    cin >> i;
    switch(i){
        case 1:
            cout << "Enter your Registration number:" << endl;
            cin >> mystud.regnum;
            cout << "Enter your Name:" << endl;
            cin >> mystud.name;
            cout << "Enter your class:" << endl;
            cin >> mystud.clas;
            cout << "Enter your month:" << endl;
            cin >> mystud.month;
            cout << "Enter your tuition fees:" << endl;
            cin >> mystud.fees;
            line = "{RegistrationNo=["+mystud.regnum+"];Name=["+mystud.name+"];Class=["+mystud.clas+"];Month=["+mystud.month+"];Fee=["+mystud.fees+"];}";
            file.open("database.txt", std::ios_base::app);
            file << line << endl;
            file.close();
            break;
        case 2:
            cout << "Enter your Registration number:" << endl;
            cin >> mystud.regnum;
            deleterecord(mystud.regnum);
            if(remove("database.txt") != 0)
                cout <<"Error deleting file\n"<<endl;
            rename("tmp.txt","database.txt");
            cout << "The record is successfully deleted"<< endl;
            break;
        case 3:
            displaystudentlist();
            break;
        default:
            break;
    }

}

void deleterecord(string ID) {
    ifstream read("database.txt");
    ofstream write("tmp.txt");
    if (read.is_open()) {
       std::string line;
       while (getline(read,line)) {
          if (line.find(ID)!= std::string::npos)
             continue;
             write<<line<<endl;
       }
    } else {
       std::cerr << "Error: coudn't open file\n";
       /* additional handle */
    }
    read.close();
    write.close();
}
void displaystudentlist(){
  string data;
  ifstream myfile("database.txt");
  if(myfile.is_open()){
   while(getline(myfile,data)){
      cout << data << '\n';
   }
  myfile.close();
   }
}














