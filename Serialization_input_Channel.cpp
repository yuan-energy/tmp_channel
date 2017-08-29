///////////////////////////////////////////////////////////////////////////////
//
// COPYRIGHT (C):      Version of a Creative Commons License,
//                     for details contact Boris Jeremic, jeremic@ucdavis.edu
// PROJECT:            Real ESSI Simulator
// PROGRAMMER:         Yuan Feng and Boris Jeremic 
// DATE:               Sep. 2017
// UPDATE HISTORY:     Full update history in git repository.
// QUALITY ASSURANCE:  Developers have worked really hard to develop
//                     an extensive verification of developed implementation
//                     and with that can claim quality and fitness for intended
//                     purpose (modeling and simulation of Real ESSI Problems)
//                     within confines of verification effort
//
// LEGACY/DEFUNCT COPYLEFT (C):
//                     Woody's viral GPL-like license (adapted by BJ):
//                     ``This    source  code is Copyrighted in
//                     worldwide for  an  indefinite  period,  and anybody
//                     caught  using it without our permission, will be
//                     mighty good friends of ourn, cause we don't give
//                     a  darn.  Hack it. Compile it. Debug it. Run it.
//                     Yodel  it.  Enjoy it. We wrote it, that's all we
//                     wanted to do.''
//
/////////////////////////////////////////////////////////////////////////////

#include "Serialization_input_Channel.h"



Serialization_input_Channel
::Serialization_input_Channel
(std::string const& filename)
:
_filename(filename)
// ,oss(filename, std::ios::binary)
,iss(filename, std::ios::binary)
// ,oarchive(oss)
,iarchive(iss)
{
}

Serialization_input_Channel
::~Serialization_input_Channel()
{
	this->close();
}

void
Serialization_input_Channel
::close
(){
	// oss.close();
	iss.close();
	std::cerr<<" --> Serialization_input_Channel is closed!"<<std::endl;
}

// void
// Serialization_input_Channel
// ::set_output_archive
// (std::string const& filename){
// 	_filename = filename;
// 	oss = std::ofstream(filename, std::ios::binary);
// 	oarchive = cereal::BinaryOutputArchive( oss );
// }

// void
// Serialization_input_Channel
// ::set_input_archive
// (std::string const& filename){
// 	_filename = filename;
// 	iss = std::ifstream(filename, std::ios::binary);
// 	iarchive = cereal::BinaryInputArchive( iss );
// }

// std::string _filename;
// std::ofstream oss ;  
// std::ifstream iss ; 
// cereal::BinaryOutputArchive oarchive;
// cereal::BinaryInputArchive iarchive;

// int 
// Serialization_input_Channel
// ::send_std_vector
// (int dbTag, int commitTag, const std::vector<int> & theVector, ChannelAddress *theAddress){
// 	oarchive(theVector);
// 	return 0;
// }

int 
Serialization_input_Channel
::receive_std_vector
(int dbTag, int commitTag, std::vector<int> & theVector, ChannelAddress *theAddress){
	iarchive(theVector);
	return 0;
}


// int 
// Serialization_input_Channel
// ::sendString
// (int dbTag, int commitTag,  const std::string &theString, ChannelAddress *theAddress){
// 	oarchive(theString);
// 	return 0;
// }


int 
Serialization_input_Channel
::receiveString
(int dbTag, int commitTag,  std::string &theString, ChannelAddress *theAddress){
	iarchive(theString);
	return 0;
}

// int 
// Serialization_input_Channel
// ::sendDTensor1
// (int dbTag, int commitTag,  const DTensor1 &theTensor, ChannelAddress *theAddress){
// 	oarchive(theTensor.dataCount);
// 	for (int i = 0; i < 1; ++i){oarchive(theTensor.size[i]);}
// 	for (int i = 0; i < 1; ++i){oarchive(theTensor.stride[i]);}
// 	for (int i = 0; i < theTensor.dataCount; ++i){oarchive( *(theTensor.data + i) );}
// 	return 0;
// }

int 
Serialization_input_Channel
::receiveDTensor1
(int dbTag, int commitTag,  DTensor1 &theTensor, ChannelAddress *theAddress){
	iarchive(theTensor.dataCount);
	for (int i = 0; i < 1; ++i){iarchive(theTensor.size[i]);}
	for (int i = 0; i < 1; ++i){iarchive(theTensor.stride[i]);}
	theTensor.data = new double[theTensor.dataCount];
	for (int i = 0; i < theTensor.dataCount; ++i){iarchive( *(theTensor.data + i) );}
	return 0;
}

// int 
// Serialization_input_Channel
// ::sendDTensor2
// (int dbTag, int commitTag,  const DTensor2 &theTensor, ChannelAddress *theAddress){
// 	oarchive(theTensor.dataCount);
// 	for (int i = 0; i < 2; ++i){oarchive(theTensor.size[i]);}
// 	for (int i = 0; i < 2; ++i){oarchive(theTensor.stride[i]);}
// 	for (int i = 0; i < theTensor.dataCount; ++i){oarchive( *(theTensor.data + i) );}
// 	return 0;
// }


int 
Serialization_input_Channel
::receiveDTensor2
(int dbTag, int commitTag,  DTensor2 &theTensor, ChannelAddress *theAddress){
	iarchive(theTensor.dataCount);
	for (int i = 0; i < 2; ++i){iarchive(theTensor.size[i]);}
	for (int i = 0; i < 2; ++i){iarchive(theTensor.stride[i]);}
	theTensor.data = new double[theTensor.dataCount];
	for (int i = 0; i < theTensor.dataCount; ++i){iarchive( *(theTensor.data + i) );}
	return 0;
}



// int 
// Serialization_input_Channel
// ::sendDTensor3
// (int dbTag, int commitTag,  const DTensor3 &theTensor, ChannelAddress *theAddress){
// 	oarchive(theTensor.dataCount);
// 	for (int i = 0; i < 3; ++i){oarchive(theTensor.size[i]);}
// 	for (int i = 0; i < 3; ++i){oarchive(theTensor.stride[i]);}
// 	for (int i = 0; i < theTensor.dataCount; ++i){oarchive( *(theTensor.data + i) );}
// 	return 0;
// }


int 
Serialization_input_Channel
::receiveDTensor3
(int dbTag, int commitTag,  DTensor3 &theTensor, ChannelAddress *theAddress){
	iarchive(theTensor.dataCount);
	for (int i = 0; i < 3; ++i){iarchive(theTensor.size[i]);}
	for (int i = 0; i < 3; ++i){iarchive(theTensor.stride[i]);}
	theTensor.data = new double[theTensor.dataCount];
	for (int i = 0; i < theTensor.dataCount; ++i){iarchive( *(theTensor.data + i) );}
	return 0;
}



// int 
// Serialization_input_Channel
// ::sendDTensor4
// (int dbTag, int commitTag,  const DTensor4 &theTensor, ChannelAddress *theAddress){
// 	oarchive(theTensor.dataCount);
// 	for (int i = 0; i < 4; ++i){oarchive(theTensor.size[i]);}
// 	for (int i = 0; i < 4; ++i){oarchive(theTensor.stride[i]);}
// 	for (int i = 0; i < theTensor.dataCount; ++i){oarchive( *(theTensor.data + i) );}
// 	return 0;
// }


int 
Serialization_input_Channel
::receiveDTensor4
(int dbTag, int commitTag,  DTensor4 &theTensor, ChannelAddress *theAddress){
	iarchive(theTensor.dataCount);
	for (int i = 0; i < 4; ++i){iarchive(theTensor.size[i]);}
	for (int i = 0; i < 4; ++i){iarchive(theTensor.stride[i]);}
	theTensor.data = new double[theTensor.dataCount];
	for (int i = 0; i < theTensor.dataCount; ++i){iarchive( *(theTensor.data + i) );}
	return 0;
}




// int 
// Serialization_input_Channel
// ::sendObj
// (int commitTag, MovableObject &theObj, ChannelAddress *theAddress){
// 	oarchive(theObj);
// 	return 0;
// }



int 
Serialization_input_Channel
::receiveObj
(int commitTag,  MovableObject &theObj, FEM_ObjectBroker &theBroker, ChannelAddress *theAddress){
	iarchive(theObj);
	return 0;
}




// int 
// Serialization_input_Channel
// ::sendVector
// (int dbTag, int commitTag,  const Vector &theVector, ChannelAddress *theAddress){
// 	oarchive(theVector);
// 	return 0;
// }



int 
Serialization_input_Channel
::receiveVector
(int dbTag, int commitTag,  Vector &theVector, ChannelAddress *theAddress){
	iarchive(theVector);
	return 0;
}


// int 
// Serialization_input_Channel
// ::sendID
// (int dbTag, int commitTag,  const ID &theID, ChannelAddress *theAddress){
// 	oarchive(theID);
// 	return 0;
// }



int 
Serialization_input_Channel
::receiveID
(int dbTag, int commitTag,  ID &theID, ChannelAddress *theAddress){
	iarchive(theID);
	return 0;
}




// int 
// Serialization_input_Channel
// ::sendMatrix
// (int dbTag, int commitTag,  const Matrix &theMatrix, ChannelAddress *theAddress){
// 	oarchive(theMatrix);
// 	return 0;
// }



int 
Serialization_input_Channel
::receiveMatrix
(int dbTag, int commitTag,  Matrix &theMatrix, ChannelAddress *theAddress){
	iarchive(theMatrix);
	return 0;
}



// int 
// Serialization_input_Channel
// ::sendMsg
// (int dbTag, int commitTag,  const Message &theMessage, ChannelAddress *theAddress){
// 	std::string tmp(theMessage.getData() , theMessage.getSize());
// 	oarchive(tmp);
// 	return 0;
// }

int 
Serialization_input_Channel
::receiveMsg
(int dbTag, int commitTag,  Message &theMessage, ChannelAddress *theAddress){
	std::string tmp;
	iarchive(tmp);
	theMessage.setData(tmp.c_str(), tmp.size());

	string channel_msg(theMessage.getData(), theMessage.getSize());
	std::cout<<"channel_msg is: " ;
	std::cout<< channel_msg <<"\n";

	return 0;
}


// 
// int Serialization_input_Channel
// ::sendnDarray
// (int dbTag, int commitTag, const nDarray &theNDarray, ChannelAddress *theAddress){
	// std::cerr<<"Serialization_input_Channel::sendnDarray is not implemented yet!"<<std::endl;
	// return -1;
// }


// int Serialization_input_Channel
// ::receivenDarray
// (int dbTag, int commitTag, nDarray &theNDarray, ChannelAddress *theAddress){
// 	std::cerr<<"Serialization_input_Channel::receivenDarray is not implemented yet!"<<std::endl;
// 	return -1;
// }

// char *
// Serialization_input_Channel
// ::addToProgram
// (){
//     cerr << "Serialization_input_Channel::addToProgram() - ";
//     cerr << "should not be called \n";
//     // char *newStuff = (char *)malloc(10 * sizeof(char));
//     // for (int i = 0; i < 10; i++)
//     // {
//     //     newStuff[i] = ' ';
//     // }
//     return nullptr ;
// }

// int
// Serialization_input_Channel
// ::setUpConnection
// (){
// 	cerr << "Serialization_input_Channel::setUpConnection() - ";
// 	cerr << "should not be called \n";
//     return 0;
// }
// ChannelAddress *
// Serialization_input_Channel
// ::getLastSendersAddress
// (){
//     cerr << "Serialization_input_Channel::getLastSendersAddress() - ";
//     cerr << "should not be called \n";
//     return nullptr;
// }


// int
// Serialization_input_Channel
// ::setNextAddress
// (const ChannelAddress &theAddress){
// 	cerr << "Serialization_input_Channel::setNextAddress(const ChannelAddress &theAddress) - ";
// 	cerr << "should not be called \n";
//     return 0;
// }