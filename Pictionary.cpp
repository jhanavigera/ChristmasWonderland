/// P
#include "Pictionary.h"

// Pictionary Class implementation

//////////////// constructor ///////////////
// constructor creates a dynamically allocated array of size n
PictionaryTeam::PictionaryTeam(int n)
{
    number = n;
    team = new string[n]; 
}

//////////////// Destructor ///////////////
PictionaryTeam::~PictionaryTeam() {
    delete [] team;
    team = nullptr;
}

//////////////// Acessors   ///////////////
string*  PictionaryTeam:: getplayer_names()

{
    return team;//
}

int PictionaryTeam::getplayer_numbers()
{
    return number;
}

//////////////// Mutators ///////////////
// Set player names 
void PictionaryTeam::setplayer_names(){
 
   
    for (int i=0; i < number; i++){
        cout << "Enter player" << i + 1 << "'s name:" << endl;
        cin >> team[i];
    }
}

//////////////// Helper functions ///////////////
// Print team
void PictionaryTeam::print_team()
{
    for (int i = 0; i < number; i++)
    {
        cout << team[i];
    }
}
