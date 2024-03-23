#pragma once


class Array
{

private:

	int* _arr; 


public:
	
	Array( int value ); 
	
	~Array(); 
	
	void Print(); 
	
	int* GetArray(); 
	
	void SetArray( int* );

};

