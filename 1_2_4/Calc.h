#pragma once


class Calc
{

private:

    int _result;

    void Count( char, int, int );


public:

    void FirstOperation( char, int, int );

    void NextOperation( char, int );

    int GetResult();

};
