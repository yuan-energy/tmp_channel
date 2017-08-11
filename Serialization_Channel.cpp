#include "Serialization_Channel.h"



Serialization_Channel
::Serialization_Channel
(std::string const& filename)
: 
_filename(filename)
,oss(filename, std::ios::binary)
,iss(filename, std::ios::binary)
,oarchive(oss)
,iarchive(iss)
{
}

Serialization_Channel
::~Serialization_Channel()
{
}

int 
Serialization_Channel
::send_std_vector
(int dbTag, int commitTag, const std::vector<int> & theVector){
	oarchive(theVector);
	return 0;
}

int 
Serialization_Channel
::receive_std_vector
(int dbTag, int commitTag, std::vector<int> & theVector){
	iarchive(theVector);
	return 0;
}


int 
Serialization_Channel
::sendString
(int dbTag, int commitTag,  const std::string &theString){
	oarchive(theString);
	return 0;
}


int 
Serialization_Channel
::receiveString
(int dbTag, int commitTag,  std::string &theString){
	iarchive(theString);
	return 0;
}

