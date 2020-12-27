#include "SecretSantaNode.h"

// Secret Santa Node Class
// This class represents the user that is playing the secret santa game.
// Each object of type SecretSantaNode shuld have a player_name, a player_email, a receiver_name
//Class Definition complete the acessors and constructor, we dont need a destructor



//////////////// Constructor ///////////////
SecretSantaNode::SecretSantaNode (string name, string email, string name2){
	player_name = name;
	player_email = email;
	receiver_name = name2;
}

//////////////// Acessors   ///////////////
string SecretSantaNode::getplayer_name() {
	return player_name;
}
string SecretSantaNode::getplayer_email() {
	return player_email;

}
string SecretSantaNode::getreceiver_name() {
	return receiver_name;
}

//////////////// Mutators ///////////////
void SecretSantaNode::setplayer_name(string name) {
	player_name = name;

}
void SecretSantaNode::setplayer_email(string email) {
	player_email = email;
}
void SecretSantaNode::setreceiver_name(string name) {
	receiver_name = name;
}
