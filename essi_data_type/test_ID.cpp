#include "ID.h"


int main(int argc, char const *argv[])
{
	ID id1(2);
	id1(1) = 21 ;
	
	cout<<"id1 = " ;
	for (int i = 0; i < (int)id1.size() ; ++i){
		cout<< id1(i) << " ";
	}
	cout<<endl;

	int* dat = &id1[0];
	cout<<"id1 = " ;
	for (int i = 0; i < (int)id1.size() ; ++i){
		cout<< *(dat+i) << " ";
	}
	cout<<endl;

// *************************
	ID id2 ;
	cout<<"id2 = " ;
	for (int i = 0; i < (int)id2.size() ; ++i){
		cout<< id2(i) << " ";
	}
	cout<<endl;

	int* dat2 = &id2[0];
	cout<<"id2 = " ;
	for (int i = 0; i < (int)id2.size() ; ++i){
		cout<< *(dat2+i) << " ";
	}
	cout<<endl;


// *************************
	ID id3 ;
	id3[2] = 42;
	cout<<"id3 = " ;
	for (int i = 0; i < (int)id3.size() ; ++i){
		cout<< id3(i) << " ";
	}
	cout<<endl;

	int* dat3 = &id3[0];
	cout<<"id3 = " ;
	for (int i = 0; i < (int)id3.size() ; ++i){
		cout<< *(dat3+i) << " ";
	}
	cout<<endl;


// *************************
	ID id5 = id3;
	// id5[2] = 42;
	cout<<"id5 = " ;
	for (int i = 0; i < (int)id5.size() ; ++i){
		cout<< id5(i) << " ";
	}
	cout<<endl;

	int* dat5 = &id5[0];
	cout<<"id5 = " ;
	for (int i = 0; i < (int)id5.size() ; ++i){
		cout<< *(dat5+i) << " ";
	}
	cout<<endl;

// *************************
	ID id6(&id5[0], (int)id5.size());
	// id5[2] = 42;
	cout<<"id6 = " ;
	for (int i = 0; i < (int)id6.size() ; ++i){
		cout<< id6(i) << " ";
	}
	cout<<endl;

	int* dat6 = &id6[0];
	cout<<"id6 = " ;
	for (int i = 0; i < (int)id6.size() ; ++i){
		cout<< *(dat6+i) << " ";
	}
	cout<<endl;
// *************************
	ID id7;
	id7.setData(&id5[0], (int)id5.size());
	// id5[2] = 42;
	cout<<"id7 = " ;
	for (int i = 0; i < (int)id7.size() ; ++i){
		cout<< id7(i) << " ";
	}
	cout<<endl;

	int* dat7 = &id7[0];
	cout<<"id7 = " ;
	for (int i = 0; i < (int)id7.size() ; ++i){
		cout<< *(dat7+i) << " ";
	}
	cout<<endl;

// *************************
	ID id8(3,4,42);
	// id5[2] = 42;
	cout<<"id8 = " ;
	for (int i = 0; i < (int)id8.size() ; ++i){
		cout<< id8(i) << " ";
	}
	cout<<endl;

	int* dat8 = &id8[0];
	cout<<"id8 = " ;
	for (int i = 0; i < (int)id8.size() ; ++i){
		cout<< *(dat8+i) << " ";
	}
	cout<<endl;
	return 0;
}

