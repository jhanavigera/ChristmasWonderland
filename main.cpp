// declarations
#include <iostream>
#include <string>
#include <conio.h>
#include <chrono>

#include "SecretSantaNode.h"
#include "Pictionary.h"

#include "stdlib.h"
#include "Windows.h" 

//////////////////// Secret Santa Functions ////////////////////
SecretSantaNode** Santa_Array; // global to the funtion
void SecretSanta();
void generate_random(int n);
void Print_SecretSanta(string name, int size);
//////////////////// Pictionary Functions  /////////////////////

// if data list is modified, do not change last character
// if data list is modified, do not change last character
string datalist[] = { "gifts", "stable","cookies" ,"Santa Claus" ,"hot chocolate","gumdrops","reindeer","gingerbread house","Santa's sleigh",
"eggnog","snowman","candy cane","elves","pumpkin pie","ho ho ho","stocking","sleigh ride","chestnuts","soup","snowman","jingle bells",
"cinnamon","snowball fight","decorations","angel","snowflake","chimney","star","Rudolph","ice skating","bells","gifts","Christmas Eve",
"scarf","lights","doll","the Grinch","the North Pole","mistletoe","turkey","mittens","wiseman","icicle","toys","Christmas tree","wrapping paper" , "\0" };

int getsize();

bool duplicate(int n);
string generateWord();
void pictionary_game();

//////////////////// Christmas Message Functions  /////////////////////

void Christmas_Message();
void Goodbye_Message();

////////////////// Holiday Hacks Main ////////////////
int main()
{
    int ch = 0;//this represents choice of a person
    do
    {
        cout << "\n\n\t\t\t ~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "\t\t\t  Menu:" << endl;
        cout << "\t\t\t 1. About Christmas" << endl;
        cout << "\t\t\t 2. Secret Santa" << endl;
        cout << "\t\t\t 3. Pictionary Game" << endl;
        cout << "\t\t\t 4. Exit" << endl;
        cout << "\t\t\t Enter your choice: ";
        cin >> ch;
        cout << "\t\t\t ~~~~~~~~~~~~~~~~~~~";
        
        switch (ch)
        {
        case 1: //write code Its Christmas
            Christmas_Message();
            break;
        case 2: //write code Its Secret Santa
            SecretSanta();
            break;
        case 3: //write code Its Pictionary
            pictionary_game();
            break;
        case 4: 
            Goodbye_Message();
            break;//this case allows you to exit out of the program
        default: cout << "\t\t Enter a correct option";
        }
    } while (ch != 4);
    return 0;
}

//////////////////// Secret Santa Functions ////////////////////
void Print_Message() {
    int i = 10;
    while (i > 0) {
        cout << "\n\n\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "\t\t\t ~~    Thanks for playing Secret Santa        ~~" << endl;
        cout << "\t\t\t ~~ We hope your holidays are filled with joy ~~" << endl;
        cout << "\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        Sleep(1000);
        system("cls");
        i--;
    }
}

/// Secret Santa : Print Names Function
void Print_SecretSanta(string name,int size,int& num, string*& check) {
    bool check2 = false;
    bool check1 = false;
    int i;
    for (int j = 0; j < size; j++) {
        if (check[j] == name) {
            check1 = true;
            check2 = true;
        }
        
        else if (name == Santa_Array[j]->getplayer_name()) {
            check[j] = name;
            check2 = true;
             num++;
            string email = Santa_Array[j]->getplayer_email();
            string receiver = Santa_Array[j]->getreceiver_name();
            i = 10;
            while (i > 0) {
                cout << "\n\n\t\t\t " << name << " your secret santa is " << receiver << endl;
                cout << "\t\t\t We will send you your secret santa to your email: " << email << endl;
                cout << "\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                cout << "\n\n\t\t\t\t\t" << i;
                Sleep(1000);
                system("cls");
                i--;
            }
        }

    }
    //Name not valit
    if (check2 == false) {
        i = 5;
        while (i > 0) {
            cout << "\n\n\t\t\t" << " The name you inserted is not valid" << endl;
            cout << "\t\t\t Let's try again " << endl;
            cout << "\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "\n\n\t\t\t\t\t" << i;
            Sleep(1000);
            system("cls");
            i--;
        }
    }
    //Name already exists in array
    else if (check1 == true) {
        i = 5;
        while (i > 0) {
          cout << "\n\n\t\t\t" << " The name you inserted has already been inserted" << endl;
          cout << "\t\t\t Let's try again " << endl;
          cout << "\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
          cout << "\n\n\t\t\t\t\t" << i;
          Sleep(1000);
          system("cls");
          i--;
        }
    }

}



/// Secret Santa: Random function
void generate_random(int n) {
    int i = 0;
    int* check;
    check = new int[n];

    while (i < n) {
        int random = rand() % n; // form 0 to n-1
        // person picked thier own name
        if (i == random)
            continue; //try again
        // person picked a different name
        if (i != random) {
            bool picked_rand = false; // random person
            bool picked_n = false;  // last person

            for (int j = 0; j < i; j++) {
                if (check[j] == random) // random person was already picked
                    picked_rand = true;
                if (check[j] == n - 1)  // last person was already picked
                    picked_n = true;
            }
            //someone already picked that random person:
            if (picked_rand == true)
                // try again:
                continue;
            // no one has picked that random person:
            else {
                // We are in the seccond to last node:
                if (i == n - 2) {
                    // last was picked:
                    if (picked_n == true) {
                        check[i] = random;
                        i++;
                        continue;
                    }
                    // last was not picked:
                    else {
                        check[i] = n - 1;  // we need to assign the last person to the second to last
                        i++;               //  otherwise the last person will pick themselves
                        continue;
                    }
                }
                //we are not in the second to last node:
                else {
                    check[i] = random;
                    i++;
                    continue;
                }
            }
        }
    }
    // Assign names to each person:
    for (int j = 0; j < n; j++) {
        int num = check[j];
        string name = Santa_Array[num]->getplayer_name();
        Santa_Array[j]->setreceiver_name(name);
    }
    delete[] check;
    check = nullptr;
}

///Secret Santa : Main function 
void SecretSanta() {
    system("cls");
    int size;
    cout << "\n\n\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "\t\t\t  Welcome to SecretSanta!!!" << endl;
    cout << "\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "\t\t\t  OBS: Secret santa is not sending emials to you just yet" << endl;
    cout << "\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cout << "\t\t\t Please, insert number of players (more than 1): ";
    cin >> size;
    cout << "\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    // Array of SecretSantaNodes pointers is created dynamically:

    Santa_Array = new SecretSantaNode * [size];

    // SecretSantaNodes Nodes are dynamically created and inicialized:
    for (int i = 0; i < size; i++) {
        string name, email;
        cout << "\t\t\t Enter player " << i + 1 << "'s name: "; 
        cin >> name;
        cout << "\t\t\t Enter player" << i + 1 << "'s email: ";
        cin >> email;
        cout << endl;
        cout << "\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        Santa_Array[i] = new SecretSantaNode(name, email, "NOT DEFINED ");
    }
    // Randomly assign secret santas:
    
    generate_random(size);
    //Secret santas randomly assigned.
    //Print friends:
    string name;//this represents choice of a person
    int  num=0;
    system("cls");
    string* check;
    check = new string[size];
    do
    {
        int i = 3;
        cout << "\n\n\t\t\t Please insert your name (exatcly as you did before), \n\t\t\t and we will tell you who your secret santa is: ";
        cin >> name;
        cout << endl;
        Sleep(1000);
        system("cls");
        while (i > 0) {
            cout << "\n\n\t\t\t SHHHHHH, only you can see who it is.......";
            cout << "\n\n\t\t\t\t\t" << i ;
            Sleep(1300);
            system("cls");
            i--;
        }
        // call a print name function


        Print_SecretSanta(name, size, num, check);
       
        

        }while (num<size);
        system("cls");
        Print_Message();
        system("cls");
        delete []check;
        check = nullptr;
    for (int j = 0; j < size; j++) {
        delete Santa_Array[j];
        Santa_Array[j] = nullptr;
    }

}



//////////////////// Pictionary Functions  /////////////////////

// the sleep statement will only work for the windows environment
// for a linux environment we need to use #include<unistd.h>

int* check = new int[getsize()]; // array to store the indexs of the visited data
int value = 0;

///get size//
int getsize()
{
    int i = 0;
    while (datalist[i] != "\0")
    {
        i++;
    }
    return i;
}

///check for duplicate//
bool duplicate(int n)
{
    int num = getsize();
    for (int i = 0; i < num; i++)
    {
        if (n != check[i])
        {
            return true;
            break;
        }
    }
    return false;
}
// generade word//
string generateWord()
{

    int num = getsize();

    string w = "";
    int index = 0;
    if (value != 0)
    {
        while (duplicate(index) == false);
        {
            index = rand() % num; // 0 to length of the array
            w = datalist[index];
            check[value] = index;
            value++;

        }
    }
    else
    {
        index = rand() % num;
        w = datalist[index];
        check[value] = index;
        value++;
    }

    return w;
}


// Pictionary Main function//
void pictionary_game()
{
    int numberOfPlayers = 0;
    int time = 0;
    int team = 1;//whenever this is odd team blue pays and whenever it is even team red plays
    int blueTeamPoints = 0;
    int redTeamPoints = 0;

    system("cls");
    cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\tRULES OF THE GAME" << endl;
    cout << "1. There are two teams:  Red and Blue." << endl;
    cout << "2. The Blue team will play first and whichever team gets 20 points first wins the game." << endl;
    cout << "3. Each team will be given an X amount of time to get as many drawings in as possible. (X is a time limit which needs to be decided by the user)" << endl;
    cout << "4. Each team will recieve a point when they press any character on the keyboard to recieve the next word" << endl;
    string a = "";
    cout << "Press any Key to continue..." << endl;
    cin >> a;
    system("cls");

    //Taking the required input
    cout << "Enter the number of players: ";
    cin >> numberOfPlayers;
    //cout << endl;

    cout << "Enter the time for each round(in minutes): ";
    cin >> time;
    time = time * 60; // converting to seconds
    cout << endl;

    system("cls");
    while (redTeamPoints < 20 && blueTeamPoints < 20)
    {
        cout << "It is " << ((team % 2 == 0) ? "RED" : "BLUE") << " team's turn " << endl;
        cout << "Starting in 3" << endl;
        Sleep(1000);
        cout << "2" << endl;
        Sleep(1000);
        cout << "1" << endl;
        Sleep(1000);
        cout << "GO" << endl;

        int seconds = 0;
        cout << "The word is: " << generateWord() << endl;
        cout << "Press any key to continue ... ";
        a = "";

        auto start = std::chrono::steady_clock::now();
        while (std::chrono::steady_clock::now() - start < std::chrono::seconds(time))
        {
            cin >> a;
            if (cin.eof() != true)
            {
                cout << endl;
                if (team % 2 == 0)
                {
                    if (redTeamPoints >= 20)
                        break;
                    redTeamPoints++;
                }
                else
                {
                    if (blueTeamPoints >= 20)
                        break;
                    blueTeamPoints++;
                }
                cout << "Time Remaining : " << (time - chrono::duration_cast<chrono::seconds>(std::chrono::steady_clock::now() - start).count()) << " seconds" << endl;
                cout << "The next word is: " << generateWord() << endl;
                cout << "Press any key to continue ... ";
                cin.clear();
            }
            cin.clear();

            //display timer here
        }
        team++;

        cout << endl << "---------------------------------------------------------------------------------" << endl;
        system("cls");
    }
    cout << endl << "---------------------------------------------------------------------------------" << endl;
    if (redTeamPoints >= 20)
    {
        cout << "The winner is ..." << endl;
        Sleep(1000);
        cout << "_______   _______    _" << endl;
        cout << "|      |  |          | \\ " << endl;
        cout << "|      |  |          |   \\" << endl;
        cout << "|______|  |______    |    |" << endl;
        cout << "| \\       |          |   /  " << endl;
        cout << "|  \\      |          |  /" << endl;
        cout << "|   \\     |_______   |/" << endl;

    }
    else if (blueTeamPoints >= 20)
    {
        cout << "The winner is ..." << endl;
        Sleep(1000);
        cout << "_______                               _______ " << endl;
        cout << "|      |   |           |         |    |       " << endl;
        cout << "|      |   |           |         |    |       " << endl;
        cout << "|______|   |           |         |    |______ " << endl;
        cout << "|      |   |           |         |    |       " << endl;
        cout << "|      |   |           |         |    |       " << endl;
        cout << "|______|   |________   |_________|    |_______" << endl;
    }
    cout << endl << "---------------------------------------------------------------------------------" << endl;
    Sleep(4000);
    system("cls");
}

//////////////////// Christmas Message Functions  /////////////////////
void Goodbye_Message() {

    int i = 7;
    while (i > 0) {
        cout << "\n\n\t\t " << endl;
        cout << "\t\t\t " << endl << endl << endl << endl << endl << endl;
        cout << "\t\t\t                          Thank you for playing        " << endl;
        cout << "\t\t\t                          Happy Holidays       " << endl;
        cout << "\t\t\t                                                                             -by JVhacks          " << endl;

        Sleep(500);
        system("cls");

        i--;
    }


}
