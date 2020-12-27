#ifndef SecretSantaNode_h
#define SecretSantaNode_h

#include <iostream>
#include <string>

using namespace std;


// Secret Santa Node Class
// This class represents the user that is playing the secret santa game.
// Each object of type SecretSantaNode shuld have a player_name, a player_email, a receiver_name


//Class Definition
class SecretSantaNode {
	string player_name;
	string player_email;
	string receiver_name;
public:
	// constructor
	SecretSantaNode(string name, string email, string name2);

	//acessors
	string getplayer_name();
	string getplayer_email();
	string getreceiver_name();

	void setplayer_name(string anme);
	void setplayer_email(string email);
	void setreceiver_name(string email);


};
#endif

