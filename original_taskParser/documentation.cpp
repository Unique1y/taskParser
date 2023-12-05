example of saved_data.txt

//Basic Structure
[1|Software Update|11/29/23|Daily|In Progress|{[]}|]



//Basic Structure of Task Item 
[ID|Task_Name|11/23/19|In Progress|Categorization|{}|""]
[15|Software Update|03/17/23|Completed|ROOT|{[9|Deliverable|03/03/15|In Progress|]}|"with fantastic handwriting calligraphy note this and just more testing and additional testing"]
[15|Software Update|03/17/23|Completed|ROOT|{43,23,80,3}|"note testing"]
[15|Software Update|11/15/23|Completed|ROOT|{9,14,20,13}|"with fantastic handwriting calligraphy note this and just more testing and additional testing"]
[15|Software Update|03/17/23|Completed|LEAF|{55}|"brooklyn good place"]

..from comparing these, it should be like if there is a 
* okay every task item generated starts as Root_Daily, or Subroot,
    - if it is a Root it is displayed, and if it is a leaf it is not displayed
    - in the 6 section, it will look for children that are created. 


    But how do I write, I need parents right?
so you look for 


* how 

    



or it should be 


ID|Name|Date|Type?(Daily,M,Y)..not displayed|In Progress|Parser for Children

{
Child 1
Child 2 
}
