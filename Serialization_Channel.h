#include <cereal/types/unordered_map.hpp>
#include <cereal/types/memory.hpp>
#include <cereal/archives/binary.hpp>
#include <cereal/archives/xml.hpp>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cereal/types/vector.hpp>
#include <cereal/types/string.hpp>
#include <LTensor.h>




class Serialization_Channel
{
public:
	std::string _filename;
	std::ofstream oss ;  
	std::ifstream iss ; 
	cereal::BinaryOutputArchive oarchive;
	cereal::BinaryInputArchive iarchive;


public:
	Serialization_Channel(std::string const& filename);
	~Serialization_Channel();
	
	int send_std_vector(int dbTag, int commitTag, const std::vector<int> & theVector) ;
	int receive_std_vector(int dbTag, int commitTag, std::vector<int> & theVector) ;
	// int sendVector(int dbTag, int commitTag, const Vector& theVector, ChannelAddress* theAddress = 0);
	// int receiveVector(int dbTag, int commitTag, Vector& theVector, ChannelAddress* theAddress = 0);


	int sendString(int dbTag, int commitTag,  const std::string &theString);
	int receiveString(int dbTag, int commitTag,  std::string &theString);

	// virtual int sendString(int dbTag, int commitTag,
	//                        const std::string &theString,
	//                        ChannelAddress *theAddress = 0) = 0;

	// virtual int receiveString(int dbTag, int commitTag,
	//                           std::string &theString,
	//                           ChannelAddress *theAddress = 0) = 0;


};