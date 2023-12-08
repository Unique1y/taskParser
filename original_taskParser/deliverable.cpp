#include <iostream> 
#include <string>
#include <list> 
#include <fstream> 
#include <sstream> 
#include <cctype> 
#include <vector> 


/*
future plannig
* habit tracker chart ... checks when I'm slacking and gives a message of encouragement 
* Dealing with Corrupted Input/Data
* more importantly, alingment of output 
*/
using namespace std;




string version = "v0.1.0";
bool anyChange = false; 
int pageNumber = 1; 
int maxPages = 0;
int runNumber = 0;

//I don't think I need to use this

enum progression {
    PendingIntiation, //or unbegun 
    inProgress,
    Completed
};

/*
    Example of Task Item    
id | Finish Todo Applicaiton | 11/28/23 | Daily | In Progress
(0-10) | Pushups | Current Date | Daily(maybe this isn't shown) | Finished? 
(11-99) | Clean room, take out trash | Weekly(I think this isn't shown) | In progress


// Thoughts on application that identifies the user's voice memo 
//creates a quick summary of the discussed topics and tasks mentioned in the memo
//has the ability to automate categorization or the ability to have some type of identifier for title.



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
   // bool completed;
    std::string progress;
/*
enum
*/
public: 
    //TaskItem(): id(0), description(""), date("n/a"), completed(false) {}
    //this constructor up there versus 
    TaskItem(int identification_number, std::string title, std::string time, std::string pro ) {
        id = identification_number;
        description = title;
        date = time; 
        progress = pro;
       // completed = false;

    }
    
    int getID() const {
        return id;
    }

    std::string getDescription() const {
        return description;
    }


    std::string getDate() const{
        return date;
    }

/*
    bool isCompleted() const {
    //legacy code 
       // return completed;
    }
*/

    std::string getProgress() const {
        return progress;
    }


    //** Notable change, I added const to all of these because of printTaskList
    // I think I have to do this is because accessing private member variables never will
    //indicates that the function will never modify the state of the object it's called on 
    //promise to compiler that the function wont' change any non-static member variables

};


vector<TaskItem>::iterator it; //taskList_Iterator



void printTaskList(vector<TaskItem>tL){
   // for(const auto& element: tL)
    //use of auto is favored because it automatically deduces the container's type 
    //global variable dictating the page that it is on
    //say that there's 1000 entries right 
    //obviously how that's going to be divided is if we just did 
    unsigned int starting_index = (pageNumber-1) * 5;


    for(unsigned int i = starting_index;i<starting_index+5 && i<runNumber-1;i++){
        //THINKING PROBLEM: what happens if I dont' include the runNumber and what if it's not -1
        //Problem number 2, why is it plus 5 and not plus 4?oh because it's less than not less than or equal to I think
        cout << '[' << tL[i].getID() << '|' << tL[i].getDescription() << '|' << tL[i].getDate() << '|' << tL[i].getProgress() << ']' << std::endl;
        //https://www.educative.io/answers/how-to-iterate-through-a-vector-in-cpp
    }


/* Attempt Number 1*/ 
/*
    for(auto &task : tL){
        cout << '[' << task.getID() << '|' << task.getDescription() << '|' << task.getDate() << '|' << task.getProgress() << ']' << std::endl;
    }
*/ 

/* Attempt 2
    for(it = tL.begin(); it != tL.end(); it++){  } 
*/

   
   /* Quick Unit Test Check
    for(const TaskItem& t: tL){
        cout << t.getID() << endl;
    }
    */

}


void checkRunning() {
    std::cout << "Jousting" << std::endl;
}

/*
void printTaskList(vector<TaskItem>tL){
   // for(const auto& element: tL)
    //use of auto is favored because it automatically deduces the container's type 
    for(it = tL.begin(); it != tL.end(); it++){
    }

}
*/




int main() {
//ESPP employee share 
/*
Goal Number 1: Parsing Input from File stream and 
putting it into a vector list of Task Objects
*/

    char character;
    int int_char;
    
    std::string token; 
    /*
    So what is a Token?
    A Token is a data value separated by the 
    Pipe | 
    Example: 
    [ID|Task_Name|11/23/19|In Progress]
    ID is a token
    Task_Name is a token 
    and so is date 

    */

    //let's create some variables to hold the values so we can instantiate
    //the object all at once. 
    int id_holder;
    std::string name_holder;
    std::string date_holder;
    std::string progress_holder; 
    runNumber = 1; //**significant** understand that the runNumber is equal to total entries


    vector<TaskItem> taskList;

    
    //read data from text file first
    std::ifstream inFile("amadeus.txt");
    //ensuring that file is openable, if not exit program
    if(inFile.is_open() == false){
        std::cout << "ERROR, Failure to find File"; 
        return 0;
    }


    while(!inFile.eof()){  
        std::cout << "Run" << runNumber << std::endl;
        character = inFile.get();


    
       // std::cout << character << std::endl;

        //You can also print characters this way
        //int_char = character;
        // std::cout << (char)int_char;
        if(character == '['){
            runNumber++;

/*        
        learned something here 
        cannot do character ="[" as "" is 
        for const char * 
        and ' ' is for char 
*/
            //if we find [ this means that we are currently starting to take in input 
            //this signifies we are currently at the start and should scan for IDs
            token.clear(); 
            //if we're at the start we should make sure token is empty 
            character = inFile.get();
            while(character!='|') {
                token+=character;
                character = inFile.get();
            }
             
            id_holder = stoi(token);
            token.clear();
            //std::cout << token << std::endl; 

            //****Now we're done with the ID section, and we'll move on to the next section
            /* std::cout << character << std::endl; outputs | right now
            so we have to grab the next character
            */
            character = inFile.get();

            while(character!='|') {
                token += character;
                character = inFile.get();

            }

            name_holder = token;
            token.clear();

            character = inFile.get();


            //****Now we're done with the Name section and it's the date section
            
            while(character!='|') {
                token += character;
                character = inFile.get();
            }

            date_holder = token;
            token.clear();

            character = inFile.get();
           // checkRunning();
            //Now for the isCompleted() part 
            while(character!=']') {
                token += character;
                character = inFile.get();
                
            }
            progress_holder = token;
            token.clear();

            character = inFile.get();
            
        TaskItem tempItem(id_holder,name_holder,date_holder,progress_holder); 
        
        taskList.push_back(tempItem);
        cout << runNumber << endl;

        }
    }

    /* Unit Testing to ensure that the list is taking in right values and priting out right
    //printTaskList(taskList);
    */ 

/*
Goal Number 1: Parsing Input from File stream and 
putting it into a vector list of Task Objects
----------------------------------------------------
We have finished Phase 1, and now I have to work on Phase 2 
Phase 2 is Establishing the GUI and allowing for multiple page interaction on the
terminal so that I can see the list
    * As for the Vector List of Tasks Items, left arrow will be go to the newest added one,
    and right arrow will be to go to the later dates. It goes from newest to oldest on each
    page
*/

    char user_Input;
    //note to self maxpages is not equal to runNumber
    maxPages = (runNumber + 5 - 1) / 5;    
    //https://stackoverflow.com/questions/2745074/fast-ceiling-of-an-integer-division-in-c-c


    while(1+2==3) {
        system("cls"); //If I'm debugging a previous part I can't have this because this is kills all the other text
        std::cout << "Perseus ADV System:" << version << endl; 
        cout << "-----------------------------------" << endl; 
        printTaskList(taskList);
        std::cout << "Page " << pageNumber << '/' << maxPages << endl;
        cout << "-----------------------------------" << endl;
        cout << "[N]ext [B]ack [A]dd [E]dit [D]elete [Q]uit " << endl;
        cout << "Input: ";
        cin >> user_Input;

        if(user_Input == 'q'){
            cout << "Exiting PAD.V..." << endl;

            if(anyChange==false){
                break;
            }
            //Probably have to do a save option soon 
            //clear console here somehow
            cin.clear();
            cout << "[W]rite Data or [E]xit"; 
            cin >> user_Input;
            if(user_Input = 'E'){
                break;
            }else if(user_Input = 'W'){
                //write data
                //if there is no changes, I'm not sure how to detect this. I guess I could set a variable that becomes true if there is change at all 
                //this is dealt with 
                /*
                    for each item in the task_list
                    print out things
                */
            } 
        }else if(user_Input == 'a'){
            cout << "Constructing New Task... ID?: ";

            cin.clear();
        }else if(user_Input == 'n'){
            if(pageNumber+1<=maxPages){
                pageNumber++;
            }else {
                cout << "Error Last Page Already" << endl;
            }
        }else if(user_Input == 'b'){
            if(pageNumber-1 != 0){
                pageNumber--;
            }else {
                cout << "Error First Page Already" << endl;
            }
        }

        
    }




    return 0;

}



//add audio 
//perhaps audio compression 

