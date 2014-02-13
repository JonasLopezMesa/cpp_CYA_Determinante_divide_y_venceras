//
//  matriz.h
//  P11CYA
//
//  Created by Jonás López Mesa on 28/11/13.
//  Copyright (c) 2013 Jonás López Mesa. All rights reserved.
//

#ifndef __P11CYA__matriz__
#define __P11CYA__matriz__

#include <iostream>
#include <math.h>
using namespace std;

typedef unsigned int 	sz_t;		// Tipo del tamaño
typedef unsigned int 	ix_t;		// Tipo del índice
typedef double 		it_t;           // Tipo del elemento de la matriz
typedef unsigned int count_t;

class Matrix_t{
private:
	it_t*    	base_;                  // Vector que contiene los elementos de la matriz
	sz_t 		m_;                     // Número de filas
	sz_t 		n_;                     // Número de columna
    count_t     n_matrix_;
    
private:
	void buildMatrix (void);            // Reserva Memoria
	void removeMatrix(void);            // Libera Memoria
    
public:
	Matrix_t(sz_t m, sz_t n);             // Constructor
	Matrix_t(void);                      // Constructor por defector. inicializa a valores nulos los atributos.
	virtual ~Matrix_t(void){
        
    }
    
	it_t& elemento(ix_t i,ix_t j);          // Acceso al elemento (i,j). Devuelve una referencia a un elemento.
	sz_t  nfilas(void);                     // Devuelve el número de filas
	sz_t  ncolumnas(void);                  // Devuelve el número de columna
    count_t time(void);
    
	void write(std::ostream& os);           // Mostrar la matriz
	void read (std::istream& is);           // Mostrar la matriz
    
	//---------------------------------------------------------------------------//
	// ESTOS Métodos son para el cálculo del determinante !!!!                   //
	//---------------------------------------------------------------------------//
private:
	int  signo(ix_t i,ix_t j);                  // Devuelve (-1)^(i+j)
    
	void subMatriz(ix_t i,ix_t j,Matrix_t& SM);	// Construye una submatrix
                                                // eliminando la fila i y la columna j
                                                // de la matriz llamante
public:
	double determinante(int& c);
    
};
#endif /* defined(__P11CYA__matriz__) */
