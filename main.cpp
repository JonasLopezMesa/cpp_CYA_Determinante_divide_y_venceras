//
//  main.cpp
//  P11CYA
//
//  Created by Jonás López Mesa on 28/11/13.
//  Copyright (c) 2013 Jonás López Mesa. All rights reserved.
//

#include <iostream>
#include "matriz.h"


int main(int argc,const char** argv)
{
	Matrix_t A;
	A.read(std::cin);
    //A.write(std::cout);
    int c = 0;
	const double det=A.determinante(c);
	//std::cout << "Determinante: "<< det<< std::endl;
    std::cout << A.nfilas() << "x" << A.ncolumnas() << " ---- " << c << endl;
	return 0;
}