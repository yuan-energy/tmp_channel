CXX_FLAGS=-I../include/ -Iltensor/ -Iessi_data_type/ -std=c++11 -Wall 
Files=./essi_data_type/MovableObject.cpp ./essi_data_type/Vector.cpp \
./essi_data_type/Matrix.cpp ./essi_data_type/ID.cpp \
./essi_data_type/Message.cpp ./essi_data_type/ChannelAddress.cpp \
./essi_data_type/nDarray.cpp ./essi_data_type/FEM_ObjectBroker.cpp

test_channel: Serialization_Channel.cpp test_channel.cpp Serialization_Channel.h
	g++ -o test_channel Serialization_Channel.cpp test_channel.cpp $(CXX_FLAGS) $(Files)


clean:
	rm -f test_channel
	rm -rf essi.serial