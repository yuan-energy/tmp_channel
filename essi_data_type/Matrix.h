/* ****************************************************************** **
**    OpenSees - Open System for Earthquake Engineering Simulation    **
**          Pacific Earthquake Engineering Research Center            **
**                                                                    **
**                                                                    **
** (C) Copyright 1999, The Regents of the University of California    **
** All Rights Reserved.                                               **
**                                                                    **
** Commercial use of this program without express permission of the   **
** University of California, Berkeley, is strictly prohibited.  See   **
** file 'COPYRIGHT'  in main directory for information on usage and   **
** redistribution,  and for a DISCLAIMER OF ALL WARRANTIES.           **
**                                                                    **
** Developed by:                                                      **
**   Frank McKenna (fmckenna@ce.berkeley.edu)                         **
**   Gregory L. Fenves (fenves@ce.berkeley.edu)                       **
**   Filip C. Filippou (filippou@ce.berkeley.edu)                     **
**                                                                    **
** ****************************************************************** */

// $Revision: 1.10 $
// $Date: 2003/04/02 22:02:46 $
// $Source: /usr/local/cvs/OpenSees/SRC/matrix/Matrix.h,v $


#ifndef Matrix_h
#define Matrix_h

// File: ~/matrix/Matrix.h
//
// Written: fmk
// Created: 11/96
// Revision: A
//
// Description: This file contains the class definition for Matrix.
// Matrix is a concrete class implementing the matrix abstraction.
// Matrix class is used to provide the abstraction for the most
// general type of matrix, that of an unsymmetric full matrix.
//
// What: "@(#) Matrix.h, revA"

#include <OPS_Globals.h>
// Boris Jeremic 17Nov2008
#include <iostream>
using namespace std;

class Vector;
class ID;
class Message;

#include <Tensor.h> // cannot use class as Tensor is itself defined in Tensor.h


#define MATRIX_VERY_LARGE_VALUE 1.0e213

class Matrix
{
public:
    // constructors and destructor
    Matrix();
    Matrix(int nrows, int ncols);
    Matrix(double *data, int nrows, int ncols);
    Matrix(const Matrix &M);
    ~Matrix();

    // utility methods
    int setData(double *newData, int nRows, int nCols);
    const double *getData() const;
    inline int noRows() const;
    inline int noCols() const;
    void Zero(void);
    int resize(int numRow, int numCol);

    int  Assemble(const Matrix &, const ID &rows, const ID &cols,
                  double fact = 1.0);

    int Solve(const Vector &V, Vector &res) const;
    int Solve(const Matrix &M, Matrix &res) const;
    int Invert(Matrix &res) const;

    int addMatrix(double factThis, const Matrix &other, double factOther);
    int addMatrixProduct(double factThis, const Matrix &A, const Matrix &B, double factOther); // AB
    int addMatrixTripleProduct(double factThis, const Matrix &A, const Matrix &B, double factOther); // A'BA
    //int addMatrixTripleProduct(const Matrix &A, const Matrix &B, const Matrix &C double fact = 1.0); //ABC

    // overloaded operators all of which are pure
    inline double &operator()(int row, int col);
    inline double operator()(int row, int col) const;
    Matrix operator()(const ID &rows, const ID &cols) const;

    Matrix &operator=(const Matrix &M);
    Matrix &operator=(const Tensor &T);

    // matrix operations which will preserve the derived type and
    // which can be implemented efficiently without many constructor calls.

    // matrix-scalar operations
    Matrix &operator+=(double fact);
    Matrix &operator-=(double fact);
    Matrix &operator*=(double fact);
    Matrix &operator/=(double fact);

    // matrix operations which generate a new Matrix. They are not the
    // most efficient to use, as constructors must be called twice. They
    // however are usefull for matlab like expressions involving Matrices.

    // matrix-scalar operations
    Matrix operator+(double fact) const;
    Matrix operator-(double fact) const;
    Matrix operator*(double fact) const;
    Matrix operator/(double fact) const;

    // matrix-vector operations
    Vector operator*(const Vector &V) const;
    Vector operator^(const Vector &V) const;


    // matrix-matrix operations
    Matrix operator+(const Matrix &M) const;
    Matrix operator-(const Matrix &M) const;
    Matrix operator*(const Matrix &M) const;
    //     Matrix operator/(const Matrix &M) const;
    Matrix operator^(const Matrix &M) const;
    Matrix &operator+=(const Matrix &M);
    Matrix &operator-=(const Matrix &M);

    bool operator==(const Matrix &M) const;

    // methods to read/write to/from the matrix
    void Output(ostream &s) const;
    //    void Input(istream &s);

    // methods added by Remo
    int  Assemble(const Matrix &V, int init_row, int init_col, double fact = 1.0);
    int  AssembleTranspose(const Matrix &V, int init_row, int init_col, double fact = 1.0);
    int  Extract (const Matrix &V, int init_row, int init_col, double fact = 1.0);

    friend ostream &operator<<(ostream &s, const Matrix &M);
    //    friend istream &operator>>(istream &s, Matrix &M);
    friend Matrix operator*(double a, const Matrix &M);

    // NOTE: This is awful programming....
    friend class Vector;
    friend class Message;
    friend class TCP_Socket;
    friend class TCP_SocketNoDelay;
    friend class UDP_Socket;
    friend class MPI_Channel;
    friend class HDF5_Channel;
    friend class H5OutputWriter;
    friend class OutputWriter;
    friend class MySqlDatastore;
    friend class MySqlDataRecorder;
    friend class BerkeleyDbDatastore;
    friend class ElasticIsotropic3D; //Guanzhou added for PDD
    friend class TwoStageEquivalentElasticIsotropic3D;
    friend class Domain_Reduction_Method_HDF5_input;
protected:

private:
    static double MATRIX_NOT_VALID_ENTRY;
    static double *matrixWork;
    static int *intWork;
    static int sizeDoubleWork;
    static int sizeIntWork;

    int numRows;
    int numCols;
    int dataSize;
    double *data;
    int fromFree;
};


/********* INLINED MATRIX FUNCTIONS ***********/
inline int
Matrix::noRows() const
{
    return numRows;
}

inline int
Matrix::noCols() const
{
    return numCols;
}


inline double &
Matrix::operator()(int row, int col)
{
#ifdef _G3DEBUG

    if ((row < 0) || (row >= numRows))
    {
        cerr << "Matrix::operator() - row " << row << " out of range [0, " <<  numRows - 1 << endln;
        return data[0];
    }
    else if ((col < 0) || (col >= numCols))
    {
        cerr << "Matrix::operator() - row " << col << " out of range [0, " <<  numCols - 1 << endln;
        return MATRIX_NOT_VALID_ENTRY;
    }

#endif
    return data[col * numRows + row];
}


inline double
Matrix::operator()(int row, int col) const
{
#ifdef _G3DEBUG

    if ((row < 0) || (row >= numRows))
    {
        cerr << "Matrix::operator() - row " << row << " out of range [0, " <<  numRows - 1 << endln;
        return data[0];
    }
    else if ((col < 0) || (col >= numCols))
    {
        cerr << "Matrix::operator() - row " << col << " out of range [0, " <<  numCols - 1 << endln;
        return MATRIX_NOT_VALID_ENTRY;
    }

#endif
    return data[col * numRows + row];
}


inline const double *Matrix::getData() const
{
    return data;
}


#endif



