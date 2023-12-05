#include <iostream> 
#include <string>
#include <list> 
#include <fstream> 
#include <sstream> 
#include <cctype> 


//using namespace std;

/*
    Example of Task Item    
id | Finish Todo Applicaiton | 11/28/23 | Daily | In Progress
(0-10) | Pushups | Current Date | Daily(maybe this isn't shown) | Finished? 
(11-99) | Clean room, take out trash | Weekly(I think this isn't shown) | In progress



*Functionality
1. I should have the ability to delete/archive my already finished 
except for the daily ones, I think they should just refresh


*/
class TaskItem {
    //private member variable first
private: 
    int id;
    std::string description; 
    std::string date; //this is date assigned
    bool completed;
public: 
    //TaskItem(): id(0), description(""), date("n/a"), completed(false) {}
    //this constructor up there versus 
    TaskItem(int identification_number, std::string title, std::string time) {
        id = identification_number;
        description = title;
        date = time; 
        completed = false;

    }
    

    int getID() {
        return id;
    }

    std::string getDescription() {
        return description;
    }


    std::string getDate() {
        return date;
    }

    bool isCompleted() {
        return completed;
    }

};

// Thoughts on application that identifies the user's voice memo 
//creates a quick summary of the discussed topics and tasks mentioned in the memo
    //has the ability to automate categorization or the ability to have some type of identifier for title.



int main() {
    //1.01 vs 0.99 ^365

    //read data from text file first
    std::ifstream inFile("data.txt");

    //Make sure that it's open 
    if(inFile.is_open() == false){
        std::cout << "ERROR, Failure to find File"; 
        return 0;
    }



//g++
    int num_tag;
    std::string name_tag, date_tag; 


/* 
Format of Input >> 
ID | Description | 

*/
char c;
int numToken;
std::string token;

    while(!inFile.eof()) {
    //  c = inFile.get();
    //std::cout << c << " test" << std::endl;

        if(isspace(c)){
            c = inFile.get();
            //If it's space should it just eat it up basically? 
            //I think so, because this makes it so that space is
            //never recognized as an indicator for anything
        }
        //The only indicator is that it 
        
        

        
    }


    







    return 0;

}