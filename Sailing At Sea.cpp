/**
    Programmer      :   Stanley
    Class           :   ET-575 Introduction to C++ Programming Design and Implementation
    Semester        :   Spring 2017
    Professor       :   Trowbridge
    Extra Credit    :   Sailing At Sea
    Software uses   :   Code:blocks
**/

#include <iostream>
#include <stdlib.h>

using namespace std;

bool isSunk = false;
bool isLost = false;

void initMap(char myMap[10][10], int MAPSIZE, int posY, int posX);
void displayMap(char myMap[10][10], int MAPSIZE);
void menue(char myMap[10][10], int MAPSIZE, int posY, int posX);
void moveShip(char option, int &posY, int &posX, char myMap[10][10], int MAPSIZE);
void banner();
int main()
{
    const int MAPSIZE = 10;
    char myMap[MAPSIZE][MAPSIZE];

    //The stating position of the ship
    int posY = 5;
    int posX = 5;


    //Create the map by setting up the size, land ocean
    // and place the ship on the map
    initMap(myMap, MAPSIZE, posY, posX);
    //Display the new updated map
    displayMap(myMap, MAPSIZE);
    //Show a menu to the user
    //and take the ship direction from the user
    menue(myMap, MAPSIZE, posY, posX);


    return 0;
}



//This function is to populate the array with map, including
void initMap(char myMap[10][10], int MAPSIZE, int posY, int posX){
//    int posY = 5;
//    int posX = 5;

    //Loop in the Y-AXIS
    for(int y_axis = 0; y_axis < MAPSIZE; y_axis++){
        //Loop in the X-AXIS
        for(int x_axis = 0; x_axis < MAPSIZE; x_axis++){
            //if the y-axis equals to the starting y-position of the ship
            //and the x-axis equals to the starting x-position of the ship
            if( (y_axis == posY) && (x_axis == posX)){
            //Then place the ship on the map
               myMap[y_axis][x_axis] = 'S';
            //If Y-AXIS is smaller than the X-AXIS
            }else if( y_axis < x_axis ){
                //Then create land
                myMap[y_axis][x_axis] = '.';
            }else{
                //Create sea
                myMap[y_axis][x_axis] = '~';
            }
        }
    }
}

//Function to display the map and its components on the screen
void displayMap(char myMap[10][10], int MAPSIZE){
    banner();

    //Y-AXIS of the map
    for(int y_axis = 0; y_axis < MAPSIZE; y_axis++){
            //Create the left side border of the map
            cout << y_axis << " ";
            //X-AXIS
            for(int x_axis = 0; x_axis < MAPSIZE; x_axis++){
                //Print out the array or the map
                cout << myMap[y_axis][x_axis] << " ";
                //If the Y-AXIS and the X-AXIS equal the size of the map minus 1
                if( (y_axis == MAPSIZE -1) && (x_axis == MAPSIZE -1) ){
                    //then move to the next line
                    cout << endl;
                    //insert a space at the beginning of the line
                    cout << "  ";
                    //Then print out the bottom border of the map
                    for(int ncount = 0; ncount < MAPSIZE; ncount++){
                        cout << ncount << " ";
                    }
                }
            }

            cout << endl;
        }

}

//Function to convert upper case letter to lower case letter
char validate(char &option){
    //If the letter is upper case
    if( (int(option) >= 65) && ( int(option)<= 90) ){
            //Then convert it to lower case
            return(int(option) + 32);
        }else{
            return option;
        }

}

//Function to display a menu to the user
//And take input or ship direction from the user
void menue(char myMap[10][10], int MAPSIZE, int posY, int posX){
    char option;

    //Do all those things
    do{
        //Show all the possible direction
        cout << "(n)orth " << endl;
        cout << "(s)outh " << endl;
        cout << "(e)ast " << endl;;
        cout << "(w)est " << endl;
        cout << endl;
        cout << "Which way, Captain? ";
        cin >> option;

        //Convert the user's input to lowercase if necessary
        option = validate(option);
        //Examine the user's input
        switch(option){
            //If it is n
            case'n':
                //Then move the ship one space up
                moveShip(option, posY, posX, myMap, MAPSIZE);
                break;
                //If it is s
            case's':
                //Then move the ship one space down
                moveShip(option, posY, posX, myMap, MAPSIZE);
                break;
                //If it is e
            case'e':
                //Then move the ship one space to the right
                moveShip(option, posY, posX, myMap, MAPSIZE);
                break;
                //If it is w
            case'w':
                //Then move the ship one space to the left
                moveShip(option, posY, posX, myMap, MAPSIZE);
                break;
                //Anything else
            default:
                //Ask for direction
                cout << "Pick a direction!!!" << endl;
                //Skip a line
                cout << endl;
                //Then wait for user to press any key to continue
                system("Pause");
                //Skip a line
                cout << endl;
        }

    //While the ship is not lost or sinking
    }while( (isSunk == false) && (isLost == false) );
    //Skip a line
    cout << endl;
    //If the ship is sinking or crash  on land
    if(isSunk == true){
        //Let the user knows the ship is sinking
        cout << "CRASH!!! Your boat begins to sink!!!!" << endl;
    }
    //If the ship lost
    else if( isLost == true){
        //Let the user knows the ship lost at sea
        cout << "ARGGGH!!!...you have been lost at sea!!!" << endl;
    }


  }

//This function allow the ship to move base on user's input
  void moveShip(char option, int &posY, int &posX, char myMap[10][10], int MAPSIZE){
    //If the user's input is n
    if(option == 'n'){
        //Subtract one from the ship Y-POSITION
        posY--;
    //If the user's input is s
    }else if(option == 's'){
        //Add one to the ship Y-POSITION
        posY++;
    //If the user's input is e
    }else if(option == 'e'){
        //Add one to the ship X-POSITION
        posX++;
    //If the user's input is w
    }else if(option == 'w'){
        //Subtract one from the ship X-POSITION
        posX--;

    }
    //Calls the initialMap function to update the map with the ship new position
    initMap(myMap, MAPSIZE, posY, posX);
    //Clear the screen before display the new map
    system("CLS");
    //Display the new map
    displayMap(myMap, MAPSIZE);

    //++++++++ Check if the ship crash on land +++++++++++++++

    //position y is smaller then position x
    //and the ship is at location posY and posX on the map
    if( (posY < posX) && (myMap[posY][posX] == 'S') ){
            //Then the ship crash on land
            isSunk = true;
    //Otherwise
    }else{
            //The ship does not crash
            isSunk = false;
    }

    //+++++++++ Check if the ship lost at sea ++++++++++++++++

    //If the ship Y-POSITION is smaller than 0
    //Or the ship Y-POSITION is greater than the size of the map
    if((posY == -1) || (posY == MAPSIZE )){
        //Then the lost at sea
        isLost = true;
    //If the ship X-POSITION is smaller than 0
    //Or the ship X-POSITION is greater than the size of the map
    }else if((posX == -1) || (posX == MAPSIZE)){
        //Then the lost at sea
        isLost = true;
    }


}


void banner(){

cout <<  "    #####                                                                         " << endl;
cout <<  "   #     #   ##   # #      # #    #  ####      ##   #####    ####  ######   ##    " << endl;
cout <<  "   #        #  #  # #      # ##   # #    #    #  #    #     #      #       #  #   " << endl;
cout <<  "    #####  #    # # #      # # #  # #        #    #   #      ####  #####  #    #  " << endl;
cout <<  "         # ###### # #      # #  # # #  ###   ######   #          # #      ######  " << endl;
cout <<  "   #     # #    # # #      # #   ## #    #   #    #   #     #    # #      #    #  " << endl;
cout <<  "    #####  #    # # ###### # #    #  ####    #    #   #      ####  ###### #    #  " << endl;
cout << endl;
}
