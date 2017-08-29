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
#pragma once
// #include <Channel.h>
#include <LTensor.h>
#include <MovableObject.h>
#include <Vector.h>
#include <ID.h>
#include <Matrix.h>
#include <Message.h>
#include <Message.h>

#include <cereal/archives/binary.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/string.hpp>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <ChannelAddress.h>
#include <nDarray.h>
#include <FEM_ObjectBroker.h>
#include "Serialization_Channel.h"
// class ChannelAddress;

// class Serialization_input_Channel: public Channel
class Serialization_input_Channel: public Serialization_Channel
{
public:
	std::string _filename;
	// std::ofstream oss ;  
	std::ifstream iss ; 
	// cereal::BinaryOutputArchive oarchive;
	cereal::BinaryInputArchive iarchive;


public:
	Serialization_input_Channel(std::string const& filename);
	~Serialization_input_Channel();
	void close();
	// void set_output_archive(std::string const& filename);
	// void set_input_archive(std::string const& filename);

	// int send_std_vector(int dbTag, int commitTag, const std::vector<int> & theVector, ChannelAddress* theAddress = 0) ;
	int receive_std_vector(int dbTag, int commitTag, std::vector<int> & theVector, ChannelAddress* theAddress = 0) ;

	// int sendString(int dbTag, int commitTag,  const std::string &theString, ChannelAddress* theAddress = 0);
	int receiveString(int dbTag, int commitTag,  std::string &theString, ChannelAddress* theAddress = 0);

	// int sendDTensor1(int dbTag, int commitTag,  const DTensor1 &theTensor, ChannelAddress* theAddress = 0);
	int receiveDTensor1(int dbTag, int commitTag,  DTensor1 &theTensor, ChannelAddress* theAddress = 0);

	// int sendDTensor2(int dbTag, int commitTag,  const DTensor2 &theTensor, ChannelAddress* theAddress = 0);
	int receiveDTensor2(int dbTag, int commitTag,  DTensor2 &theTensor, ChannelAddress* theAddress = 0);

	// int sendDTensor3(int dbTag, int commitTag,  const DTensor3 &theTensor, ChannelAddress* theAddress = 0);
	int receiveDTensor3(int dbTag, int commitTag,  DTensor3 &theTensor, ChannelAddress* theAddress = 0);

	// int sendDTensor4(int dbTag, int commitTag,  const DTensor4 &theTensor, ChannelAddress* theAddress = 0);
	int receiveDTensor4(int dbTag, int commitTag,  DTensor4 &theTensor, ChannelAddress* theAddress = 0);

	// int sendObj(int commitTag,  MovableObject &theObj, ChannelAddress* theAddress = 0);
	int receiveObj(int commitTag,  MovableObject &theObj, FEM_ObjectBroker &theBroker, ChannelAddress* theAddress = 0);

	// int sendVector(int dbTag, int commitTag, const Vector& theVector, ChannelAddress* theAddress = 0);
	int receiveVector(int dbTag, int commitTag, Vector& theVector, ChannelAddress* theAddress = 0);

	// int sendID(int dbTag, int commitTag, const ID& theID, ChannelAddress* theAddress = 0);
	int receiveID(int dbTag, int commitTag, ID& theID, ChannelAddress* theAddress = 0);

	// int sendMatrix(int dbTag, int commitTag, const Matrix& theMatrix, ChannelAddress* theAddress = 0);
	int receiveMatrix(int dbTag, int commitTag, Matrix& theMatrix, ChannelAddress* theAddress = 0);

	// int sendMsg(int dbTag, int commitTag, const Message& theMessage, ChannelAddress* theAddress = 0);
	int receiveMsg(int dbTag, int commitTag, Message& theMessage, ChannelAddress* theAddress = 0);

	// int sendnDarray(int dbTag, int commitTag, const nDarray &theNDarray, ChannelAddress* theAddress = 0);
	// int receivenDarray(int dbTag, int commitTag, nDarray &theNDarray, ChannelAddress* theAddress = 0);

	// char* addToProgram();
	// int setUpConnection();
	// // ChannelAddress* getLastSendersAddress();
	// int setNextAddress(const ChannelAddress& otherChannelAddress);
};