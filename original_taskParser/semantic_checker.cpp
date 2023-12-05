#include <iostream> 
#include <cctype> 


using namespace std;

string keywords[] = {
"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", 
"return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef","union", "unsigned", "void", "volatile", "while"
}; 
//32 total 

string ops[] = { 
"=", "|", "||", "&&", "==", "!=", "<", ">", "<=", ">=", "+", "-", "*", "/", "%", "&", "!", "++", "--", ".", "->", "(", ")", "[", "]", "{", "}", ";", ":", "," 
}; // 30 total 



int main(void) {

	string token;
	int succeeding;
	bool keyword = false;
	int gobbler = cin.get(); //gobbling actor




	while(!cin.eof()){


		token.clear();
		//gobble space i think this includes \n \t all of that 
		if(isspace(gobbler)){
			gobbler = cin.get();
		}

		/*
			this part checks if the alphaumeric input is a keyword or identifier 
		*/

		else if(gobbler == '_' || isalpha(gobbler)) {
			keyword = false; 	//here
			token += gobbler;
			gobbler = cin.get();


			while(gobbler =='_' || isalpha(gobbler) || isdigit(gobbler)) {
				token += gobbler;
				gobbler= cin.get();
			}

			for(int i=0;i<32;i++){
				if(token.compare(keywords[i])==0){
					keyword = true;
					cout << "keyword:" << token << endl;
					break;
				}
			}

			if(keyword = false){
				cout << "identifier:" << token << endl;
//				keyword= !keyword;  
//bool flip here wrong or no? should be up here
			}

		} 

//checking digit if it's digit then it's obviously an number

		else if(isdigit(gobbler)){
					token+= gobbler;
					gobbler = cin.get();
					while(isdigit(gobbler)){
						token += gobbler;
						gobbler = cin.get();
					}
					cout<< "number:" << token << endl;
				}




//now we deal with the symbols and use ops[] array to deal with this 

		else if(ispunct(gobbler)){

//dealing with strings
				if (gobbler == '"'){
						token += gobbler;
						gobbler = cin.get(); // moves 
					while(gobbler!= '"' ||(gobbler =='\\' && cin.peek() == '\\')){
						if(cin.peek() == '\\'){
							
							token += gobbler;
							gobbler = cin.get();
							token += gobbler;
							gobbler = cin.get();

						}
						token += gobbler;
						gobbler = cin.get();
					}
					token+= gobbler;
					gobbler = cin.get();
					cout << "string:" << token << endl;


					}

		else

/* Dealing with Characters
					if (gobbler == '\''){
						token += gobbler;


						while(cin.peek() != '\''){
							
							gobbler = cin.get();	
							token += gobbler;


						}


					gobbler = cin.get();
					token += gobbler;
					cout << "character:" << token << endl;

					}
*/
					if (gobbler == '\''){
						token += gobbler;
						gobbler = cin.get();
					while(gobbler!= '\''||(gobbler =='\\' && cin.peek() == '\\')){
						if(cin.peek() == '\\'){
							token += gobbler;
							gobbler = cin.get();
							token += gobbler;
							gobbler = cin.get();
						}
						token += gobbler;
						gobbler = cin.get();
					}
					token+= gobbler;
					gobbler = cin.get();
					cout << "character:" << token << endl;
					}
//Characeters here ///////////////////////////////////////////////


				else {
					//dealing with comments 
					succeeding = cin.get(); //succeeding for 2 character dealings

					if (gobbler == '/') {

					if(succeeding!='*'){
						token += gobbler;
						gobbler = succeeding;
					}


					else {
							gobbler = cin.get();
							succeeding = cin.get();

							while (gobbler != '*' || succeeding != '/') {		//while c is not * or succeeding is not / due to standard format of it would be /* */

    							token += gobbler;
    							gobbler = succeeding;

    							succeeding = cin.get();
							}
							gobbler = cin.get();
    					}


					} 



			

//now we have to deal with the 2 character symbol	
//hardcode else if loop 	

//||, && , ==, != , <=, >= ,++, --, ->, 

					else if (gobbler == '|') {
    						if (succeeding == '|') {
        						token += gobbler;
        						token += succeeding;
       							gobbler = cin.get();  //it will move it past as cin.get() has been called 2 times totally in the the characters and strings
    						} else {
								//it will do this when succeeding is not | but if pass then it will use gobbler to eat the current | and the next | and then move the gobler to the next 
								//token doesn't take the suceeding and instead the gobbler consumes it making it have that next character this logic is used 

        						token += gobbler;
        						gobbler = succeeding; // this will eat succeeding and return to the global scope to check it through the whole process again. 

								//gobbler is put into token and then gobbler is equal to succeeding and then it will reset and see where the next character on the gobbler will take us
    						}
					}	


					else if (gobbler == '&') {
    						if (succeeding == '&') {
		    					token += gobbler;
		    					token += succeeding;
		   						gobbler = cin.get();
    						} else {
		    					token += gobbler;
		    					gobbler = succeeding;
    						}

					} 

				else if (gobbler == '=') {
							if (succeeding == '=') {
								token += gobbler;
								token += succeeding;
								gobbler = cin.get();
							} else {
								token += gobbler;
								gobbler = succeeding;
							}
					} 


 				else if (gobbler == '!') {
    						if (succeeding == '=') {
        						token += gobbler;
        						token += succeeding;
       							 gobbler = cin.get();
    						} else {
        						token += gobbler;
        						gobbler = succeeding;
    				}
				}


				else if (gobbler == '<') {
    						if (succeeding == '=') {
        						token += gobbler;
								token += succeeding;
								gobbler = cin.get();
							} else {
								token += gobbler;
								gobbler = succeeding;
							}
							
				} else if (gobbler == '>') {
							if (succeeding == '=') {
								token += gobbler;
								token += succeeding;
								gobbler = cin.get();
							} else {
								token += gobbler;
								gobbler = succeeding;
							}
				} 



				else if (gobbler == '+') {
    					if (succeeding == '+') {
        					token += gobbler;
        					token += succeeding;
        					gobbler = cin.get();

    					} else {
        					token += gobbler;
        					gobbler = succeeding;
    					}


					} 

					else if (gobbler == '-') {
    					if (succeeding == '>' || succeeding == '-' ) {
        					token += gobbler;
        					token += succeeding;

        					gobbler = cin.get();
    				} else {
        				token += gobbler;
        				gobbler = succeeding;
    				}


					}  

					else { //standard case if all else fails it will default to this
						//	cout << (char) gobbler << endl; 
							token += gobbler;
							gobbler = succeeding;
					} 


//at the end i want to check whether the token will match a known operator
		
	for(int i = 0;i<30;i++){
		if(!token.compare(ops[i])){ // = 0 so it will pass here if it's false 
		cout << "operator:" << token << endl;
		break;
	}
			}
		}

		}
	}

	return 0;
}
