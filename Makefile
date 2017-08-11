CXX_FLAGS=-I../include/ -Iltensor/ -std=c++11 -Wall 

test_channel: Serialization_Channel.cpp test_channel.cpp Serialization_Channel.h
	g++ -o test_channel Serialization_Channel.cpp test_channel.cpp $(CXX_FLAGS)


clean:
	rm -f test_channel