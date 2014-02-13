//
//  matriz.cpp
//  P11CYA
//
//  Created by Jonás López Mesa on 28/11/13.
//  Copyright (c) 2013 Jonás López Mesa. All rights reserved.
//

#include "matriz.h"

void Matrix_t::buildMatrix (void){
    base_ = new it_t[m_*n_];
}
void Matrix_t::removeMatrix(void){
    m_ = 0;
    n_ = 0;
    n_matrix_ = 0;
    delete[] base_;
}

Matrix_t::Matrix_t(sz_t m, sz_t n) : m_(m), n_(n), n_matrix_(0) {
    buildMatrix();
}
Matrix_t::Matrix_t(void) : m_(0), n_(0), n_matrix_(0), base_(NULL) { }

it_t& Matrix_t::elemento(ix_t i,ix_t j){
    return base_[i+(j*n_)];
}
sz_t  Matrix_t::nfilas(void){
    return m_;
}
sz_t  Matrix_t::ncolumnas(void){
    return n_;
}

count_t Matrix_t::time(void){
    return n_matrix_;
}

void Matrix_t::write(std::ostream& os){
    os << m_ << n_;
    for (int i = 0; i < m_*n_; i++) {
        os << base_[i] << " ";
    }
}
void Matrix_t::read (std::istream& is){
    is >> m_ >> n_;
    buildMatrix();
    for (int i = 0; i < m_*n_; i++) {
        is >> base_[i];
    }
}

int  Matrix_t::signo(ix_t i,ix_t j){
    return (pow(-1, i+j));
}

void Matrix_t::subMatriz(ix_t i,ix_t j,Matrix_t& SM){
    int a = 0;
    for (int x = 0; x < m_; x++) {
        for (int y = 0; y < n_; y++) {
            if ((x != i) && (y != j)) {
                SM.elemento(a/SM.nfilas(), a%SM.ncolumnas()) = base_[x+(y*n_)];
                a = a+1;
            }
        }
    }
}

double Matrix_t::determinante(int& c){
    double det = 0; int i = 0;
    if ((m_ > 1) && (n_ > 1)) {
        for (int j = 0; j < n_; j++) {
            n_matrix_ = n_matrix_+1;
            c = c+1;
            Matrix_t SM(m_-1, n_-1);
            subMatriz(i, j, SM);
            det = det + (((base_[i+(j*n_)]) * (SM.determinante(c)) * (signo(i+1, j+1))));
        }
        return det;
    } else {
        det = base_[0];
        return det;
    }
}