#ifndef PictionaryTeam_h
#define  PictionaryTeam_h

#include <iostream>
#include <string>
using namespace std;

// Pictionary Class
// This class represents the team that is playing the pictionary game.
// Each object of type SecretSantaNode shuld have a player_name, a player_email, a receiver_name


//Class Definition
class  PictionaryTeam {
private:
	int number;
	string *team;
	
public:
//////////////// constructor ///////////////
	PictionaryTeam(int number);

//////////////// Destructor ///////////////
	~PictionaryTeam();

//////////////// Acessors   ///////////////
	string* getplayer_names(); // parse thorugh the array we will return all names
	int getplayer_numbers();
//////////////// Mutators ///////////////
	void setplayer_names();  // parse thorugh the array and insert names

//////////////// Helper functions /////////
	void print_team();

};

#endif
