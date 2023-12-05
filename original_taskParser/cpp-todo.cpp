#include <iostream> 
#include <string> 
#include <list> 
#include <ctime> 
//Password for liu.eason30::dy/dx@Lway5 // same password for issenliu@gmail.com


//
class  TodoItem {
//private member variables

private: 
        int id; 
        std::string description;
        bool completed;
    public: 
    //basic constructor 
        TodoItem(): id(0), description(""), completed(false) {} //empty to do item body
        ~TodoItem() = default;  

        bool create(std::string new_description) {
            //generates a random integer between 1 and 100 
            id = rand() % 100 + 1;

            description = new_description;
            return true; 
        }


    int getId() {return id;}
    std::string getDescription() {return description;}
    bool isCompleted() {return completed;}

    void setCompleted(bool val){
        completed = val;
    }

}; 

int main() {
    char input_option;
    int input_id;
    std::string input_description;
    std::string version = "v0.1.0";
    std::list<TodoItem> todoItems;
    std::list<TodoItem>::iterator it;   

    srand(time(NULL)); //seed for the random generator, not sure if this is really necessary but he seems like he knows that the 
    
    todoItems.clear(); 




/*
    TodoItem test; 
    test.create("this is a test");
    todoItems.push_back(test); //pushback vs pushfront?
*/


    while(1+2 == 3) {
        //i think this clears everything and makes it only the program cls
        system("cls");
        std::cout << "Todo List Maker" << version << std::endl; 
        std::cout << std::endl << std::endl; //why is there two endl here? 

        for(it = todoItems.begin(); it != todoItems.end(); it++){
            
            std::string completed = it-> isCompleted() ? "done" : "not done";
            
            
           // std::cout << it-> getId() << " | " << it-> getDescription() << " | " << it -> isCompleted() << std:: endl;
            std::cout << it-> getId() << " | " << it-> getDescription() << " | " << completed << std:: endl;
        }

        if(todoItems.empty()) {
            std::cout << "Add your first todo!" << std::endl; 
        }

        std::cout << std::endl << std::endl;



        std::cout << "[a]dd a new Todo" << std::endl;
        std::cout << "[c]omplete a Todo" << std::endl;
        std::cout << "[q]uit" << std::endl;

        std::cout << "choice: ";

        std::cin >> input_option;

        if(input_option== 'q'){
            std::cout << "Have a great day now" << std::endl;
            break;
        } else if(input_option == 'a') {
            std::cout << "Add a new description: ";
            std::cin.clear(); //input stream buffer clearing, bug of this 
            /* 
                39 | finish | not done
                12 | l | not done
                
                clearing, if there's any existing keys that are left over in the input buffer before we get there, those will be assigned into our new variable before the one we want 
            */
            //std::cin >> input_description;
//            std::getline(std::cin, input_description);
            std::cin.ignore();
            std::getline(std::cin, input_description);



            TodoItem newItem;
            newItem.create(input_description);
            todoItems.push_back(newItem);
        } 
        else if(input_option == 'c')  {
            std::cout << "Enter id to mark completed: ";
            std::cin >> input_id;     

            for(it = todoItems.begin(); it!= todoItems.end(); it++) {
                if(input_id== it-> getId()) {
                    it -> setCompleted(true);
                    break;
                }
            }
        
        }


        
    }

    return 0; 
}