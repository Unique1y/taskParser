#include <iostream>
#include <fstream> 
#include <sstream> 
#include <string> 

using namespace std;


int main(){
    // 1.01^365 vs 0.99^365
    
    ifstream myFileStream("data.txt");

    if(!myFileStream.is_open()){
        cout << "Failure to Read File, please try again" << endl;
        return 0;
    }
/* 

*/

    string firstName, lastName, tempString, DOB; 
    int age; 

    string myString;
    string line;

//two arguments for getline, first argument: where to look to get the line, where to store the line once it gets it
while(getline(myFileStream, line)) {
    stringstream ss(line);
    //can i do comma? as a set variable?
    getline(ss, firstName, ',');       
    getline(ss, lastName, ','); 
    getline(ss, tempString, ',');
    getline(ss, myString, ',');
    age = stoi(myString);
    getline(ss, tempString, ',');
    getline(ss, DOB, ',');
    DOB = DOB.substr(0,2)+DOB.substr(3,2) + DOB.substr(6,2);
    cout << age << endl; 
    cout << DOB << endl;
}

   myFileStream.close();
   return 0;
}