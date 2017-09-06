// #include <cereal/types/unordered_map.hpp>
// #include <cereal/types/memory.hpp>
#include <cereal/archives/binary.hpp>
#include <fstream>
#include <iostream>
#include <cereal/types/vector.hpp>

// #include "own_vector.h"
#include "Serialization_Channel.h"
#include "Serialization_output_Channel.h"
#include "Serialization_input_Channel.h"

int main(int argc, char const *argv[])
{
	if (argc != 2)	{
		std::cerr<<"argc = " << argc-1 << "\n";
		std::cerr<<"This test require one argument! \n";
		std::cerr<<"1 is output, 2 is input \n";
		exit(0); 
	}

	int command = atoi(argv[1]) ;

	std::string filename = "essi.serial";
	if (command == 1)
	{
		Serialization_output_Channel thechannel(filename)  ;
		// ******************************************************************
		// save data to disk
		// ******************************************************************
		int val1 = 2 ; 
		double val2 = 3.3; 
		thechannel.send_single_POD<int>(0,0, val1);
		thechannel.send_single_POD<double>(0,0, val2);

		// ******************************************************************
		std::vector<int> vec1 = {1,2,23,4,5,541};
		std::vector<float> vec2 = {10,20,230.4,40,50,5410.6};
		thechannel.send_std_vector<int>(0,0, vec1);
		thechannel.send_std_vector<float>(0,0, vec2);

		// ******************************************************************
		std::string str1 = "vonMises_material";
		std::string str2 = "8nodebrick";
		thechannel.sendString(0,0, str1);
		thechannel.sendString(0,0, str2);

		// ******************************************************************
		DTensor1 stress1(6,0.);
		stress1(0) = 8; stress1(2) = 12; stress1(4)=42;
		thechannel.sendDTensor1(0,0, stress1);

		// ******************************************************************
		DTensor2 stress2(2,2,0.);
		stress2(0,0) = 8; stress2(0,1) = 7; stress2(1,1)=42;
		thechannel.sendDTensor2(0,0, stress2);

		// ******************************************************************
		DTensor4 stiff4(2,2,2,2,0.);
		stiff4(0,0,0,0) = 8; stiff4(0,1,0,1) = 7; stiff4(1,1,0,0)=42;
		thechannel.sendDTensor4(0,0, stiff4);

		// ******************************************************************
		MovableObject obj1(4,2);
		thechannel.sendObj(0, obj1);

		// ******************************************************************
		Vector myVec1(4);
		myVec1(2) = 1./33;
		myVec1(3) = 1./6 ; 
		myVec1(2) = 1./100;
		thechannel.sendVector(0,0, myVec1);

		// ******************************************************************
		ID id1(2);
		id1(1) = 21 ;
		thechannel.sendID(0,0, id1);

		// ******************************************************************
		Matrix mat1(2,2);
		mat1(1,1) = 9 ;
		thechannel.sendMatrix(0,0, mat1);

		// ******************************************************************
		string str="Good";
		Message msg1( const_cast<char*>(str.c_str()), str.size());
		thechannel.sendMsg(0,0, msg1);
		string sent_msg(msg1.getData(), msg1.getSize());
		std::cout<<"Sent msg is: ";
		std::cout<< sent_msg <<"\n";

		// ******************************************************************
		// ******************************************************************
		// Important! Sync!
		// ******************************************************************
		// ******************************************************************
		thechannel.oss.flush();

		thechannel.close();
	}





	if (command == 2)
	{
		// ******************************************************************
		Serialization_input_Channel the_load_channel(filename)  ;
		// ******************************************************************
		// load data back
		// ******************************************************************
		int shadow_val1 =0 ; 
		double shadow_val2 =0 ; 
		the_load_channel.receive_single_POD<int>(0,0, shadow_val1);
		the_load_channel.receive_single_POD<double>(0,0, shadow_val2);
		std::cout<<"The received POD data is \n";
		std::cout<< shadow_val1 << " \n";
		std::cout<< shadow_val2 << " \n";

		// ******************************************************************
		std::vector<int> shadow_vec1;
		std::vector<float> shadow_vec2;
		the_load_channel.receive_std_vector<int>(0,0, shadow_vec1);
		the_load_channel.receive_std_vector<float>(0,0, shadow_vec2);
		std::cout<<"The std vector data is " <<"\n";
		for(uint i=0; i<shadow_vec1.size() ; ++i){std::cout<<shadow_vec1[i]<<"\t";} std::cout<< "\n" ;
		for(uint i=0; i<shadow_vec2.size() ; ++i){std::cout<<shadow_vec2[i]<<"\t";} std::cout<< "\n" ;
		
		// ******************************************************************
		std::string shadow_str1 ;
		std::string shadow_str2 ;
		the_load_channel.receiveString(0,0, shadow_str1);
		the_load_channel.receiveString(0,0, shadow_str2);
		std::cout<<"The string is " <<"\n";
		std::cout<<shadow_str1<<"\n";
		std::cout<<shadow_str2<<"\n";


		// ******************************************************************
		DTensor1 shadow_stress1(6) ;
		DTensor2 shadow_stress2(2,2) ;
		DTensor4 shadow_stiff4(2,2,2,2) ;
		the_load_channel.receiveDTensor1(0,0, shadow_stress1);
		the_load_channel.receiveDTensor2(0,0, shadow_stress2);
		the_load_channel.receiveDTensor4(0,0, shadow_stiff4);
		std::cout<<shadow_stress1<<"\n";
		std::cout<<shadow_stress2<<"\n";
		std::cout<<shadow_stiff4<<"\n";

		// ******************************************************************
		MovableObject shadow_obj1(0,0) ;
		FEM_ObjectBroker theBroker;
		the_load_channel.receiveObj(0, shadow_obj1, theBroker);
		std::cout<<"The shadow_obj1 is " <<"\n";
		std::cout<<shadow_obj1.classTag <<"\t"<< shadow_obj1.dbTag <<"\n";

		// ******************************************************************
		Vector shadow_myVec1(4) ;
		the_load_channel.receiveVector(0,0, shadow_myVec1);
		std::cout<<"The shadow_myVec1 is " <<"\n";
		std::cout<<shadow_myVec1 <<"\n";
		
		// ******************************************************************
		ID shadow_id1(2) ;
		the_load_channel.receiveID(0,0, shadow_id1);
		std::cout<<"The shadow_id1 is " <<"\n";
		std::cout<< shadow_id1 <<"\n";

		// ******************************************************************
		Matrix shadow_mat1(2,2) ;
		the_load_channel.receiveMatrix(0,0, shadow_mat1);
		std::cout<<"The shadow_mat1 is " <<"\n";
		std::cout<< shadow_mat1 <<"\n";

		// ******************************************************************
		Message shadow_msg1;
		the_load_channel.receiveMsg(0,0, shadow_msg1);
		std::string final_msg(shadow_msg1.getData(), shadow_msg1.getSize());
		std::cout<<"the final_msg is: "<< final_msg <<"\n";
		std::cout<<"the shadow_msg1 size is " << shadow_msg1.getSize() <<"\n" ;

		// // ******************************************************************
		// // ******************************************************************
		// // Important! Sync!
		// // ******************************************************************
		// // ******************************************************************
		// thechannel.iss.sync();
		the_load_channel.close();
	}
	
	return 0;
}