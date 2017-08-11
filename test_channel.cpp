#include <cereal/types/unordered_map.hpp>
#include <cereal/types/memory.hpp>
#include <cereal/archives/binary.hpp>
#include <fstream>
#include <iostream>
#include <cereal/types/vector.hpp>

// #include "own_vector.h"
#include "Serialization_Channel.h"

int main(int argc, char const *argv[])
{
	// ******************************************************************
	// save data to disk
	// ******************************************************************
	std::vector<int> vec1 = {1,2,23,4,5,541};
	std::vector<int> vec2 = {10,20,230,40,50,5410};
	std::string filename = "essi.serial";

	Serialization_Channel thechannel(filename)  ;
	thechannel.send_std_vector(0,0, vec1);
	thechannel.send_std_vector(0,0, vec2);

	// ******************************************************************
	std::string str1 = "vonMises_material";
	std::string str2 = "8nodebrick";
	thechannel.sendString(0,0, str1);
	thechannel.sendString(0,0, str2);


	// ******************************************************************
	// ******************************************************************
	// Important! Sync!
	// ******************************************************************
	// ******************************************************************
	thechannel.oss.flush();



	// ******************************************************************
	// load data back
	// ******************************************************************
	std::vector<int> shadow_vec1;
	std::vector<int> shadow_vec2;
	thechannel.receive_std_vector(0,0, shadow_vec1);
	thechannel.receive_std_vector(0,0, shadow_vec2);
	std::cout<<"The data is " <<"\n";
	for(uint i=0; i<shadow_vec1.size() ; ++i){std::cout<<shadow_vec1[i]<<"\t";} std::cout<< "\n" ;
	for(uint i=0; i<shadow_vec2.size() ; ++i){std::cout<<shadow_vec2[i]<<"\t";} std::cout<< "\n" ;
	
	// ******************************************************************
	std::string shadow_str1 ;
	std::string shadow_str2 ;
	thechannel.receiveString(0,0, shadow_str1);
	thechannel.receiveString(0,0, shadow_str2);
	std::cout<<"The string is " <<"\n";
	std::cout<<shadow_str1<<"\n";
	std::cout<<shadow_str2<<"\n";

	return 0;
}