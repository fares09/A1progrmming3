// Course:  CS213 - Programming II  - 2018
// Title:   Assignment I - Task 1 - Problem 0
// Program: CS213-2018-A1-T1-P0
// Purpose: Skeleton code for the student to start working
// Author:  Dr. Mohammad El-Ramly
// Date:    10 August 2018
// Version: 1.0

// All tested 10/7/ sat/2018

#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

// A structure to store a matrix
struct matrix
{
  int** data;       // Pointer to 2-D array that will simulate matrix
  int row, col;
};

// Already implemented
void createMatrix (int row, int col, int num[], matrix& mat);

//-----------------------------------------------------------------------------omar
matrix operator+  (matrix mat1, matrix mat2); // Add if same dimensions
matrix operator-  (matrix mat1, matrix mat2); // Sub if same dimensions
matrix operator*  (matrix mat1, matrix mat2); // Multi if col1 == row2
matrix operator+  (matrix mat1, int scalar);  // Add a scalar
matrix operator-  (matrix mat1, int scalar);  // Subtract a scalar
matrix operator*  (matrix mat1, int scalar);  // Multiple by scalar

//----------------------------------------------------------------------------fares
matrix operator+= (matrix& mat1, matrix mat2); // mat1 changes & return
					    // new matrix with the sum
matrix operator-= (matrix& mat1, matrix mat2); // mat1 changes + return new
					     // matrix with difference
matrix operator+= (matrix& mat, int scalar);   // change mat & return new matrix
matrix operator-= (matrix& mat, int scalar);   // change mat & return new matrix
void   operator++ (matrix& mat);   	// Add 1 to each element ++mat......................................At here !!! s
void   operator-- (matrix& mat);    	// Sub 1 from each element --mat
istream& operator>> (istream& in, matrix& mat);

//--------------------------------------------------------------karim
ostream& operator<< (ostream& out, matrix mat);

bool   operator== (matrix mat1, matrix mat2);	// True if identical
bool   operator!= (matrix mat1, matrix mat2); 	// True if not same
bool   isSquare   (matrix mat);  // True if square matrix
bool   isSymetric (matrix mat);  // True if square and symmetric
bool   isIdentity (matrix mat);  // True if square and identity
matrix transpose(matrix mat);    // Return new matrix with the transpose

//__________________________________________

// I am using Assert cuz when you cascade (mat + mat1 + mat3) printing a message wont stop the execution  and the function will return a wrong matrix.
int main()
 //
{
    matrix mat1, mat2, mat3,mat4,mat5;

    // mat1 & 2 for add , 3&4 for multi.
    cin >> mat1 >> mat2 >> mat4 >> mat5;

    cout << "mat1\n:" << mat1 << endl;
    cout << "mat2\n:" << mat2 << endl;
    cout << "mat4\n:" << mat4 << endl;
    cout << "mat5\n:" << mat5 << endl;

    //----------------------------------------------omar.

    cout << "mat3 = mat1 + mat2 \n";
    mat3 = mat1 + mat2 + mat1;
    cout << mat3 << "\n\n";


    cout << "mat3 = mat1 - mat2\n";
    mat3 = mat1 - mat2 - mat1;
    cout << mat3 << "\n\n";


    cout << "mat3 = mat4 * mat5;\n";
    mat3 = (mat4 * mat5)*mat1;
    cout << mat3 << "\n\n";


    cout << "mat1 + 1\n";
    mat3 = mat1 +1;
    cout << mat3 << "\n\n";


    cout << "mat1 - 1\n";
    mat3 = mat1 - 1;
    cout << mat3 << "\n\n";



    cout << "mat1 * 2\n";
    mat3 = (mat1*2);
    cout << mat3 << "\n\n";


    //---------------------------------------karim.

    // the cout operator.

    cout << "mat1 == mat2 ?\n";
    cout << ((mat1 == mat2) ? "true\n" : "false\n");

    cout << "mat1 != mat2 ?\n";
    cout << ((mat1 != mat2)? "true\n" : "false\n");

    cout << "mat4 is square?\n";
    cout << (isSquare(mat4)? "true\n" : "false\n");
    cout << "mat5 is square?\n";
    cout << (isSquare(mat5)? "true\n" : "false\n");

    cout << "mat4 is symmetric?\n";
    cout << (isSymetric(mat4)? "true\n" : "false\n");
    cout << "mat5 is symmetric?\n";
    cout << (isSymetric(mat5)? "true\n" : "false\n");

    cout << "mat4 isIdentity?\n";
    cout << (isIdentity(mat4)? "true\n" : "false\n");
    cout << "mat5 isIdentity?";
    cout << (isIdentity(mat5)? "true\n" : "false\n");

    cout << "traspose of mat5\n";
    cout << transpose(mat5);


    // ---------------------------------------fares

    // the cin operator.
    cout << "mat1 += mat2\n";
    cout << (mat1+=mat2) << endl;


    cout << "mat2 -= mat1\n";
    cout << (mat2 -= mat1) << endl;

    cout << "mat3 += 2\n";
    cout << (mat3 += 2) << endl;

    cout << "mat3 -= 2\n";
    cout << (mat3 -= 2) << endl;

    cout << "++mat3\n";
    ++mat3;
    cout << mat3 << endl;

    cout << "--mat3\n";
    --mat3;
    cout << mat3 << endl;




  return 0;
}

//__________________________________________
// Takes an array of data and stores in matrix according
// to rows and columns
void createMatrix (int row, int col, int num[], matrix& mat) {
  mat.row = row;
  mat.col = col;
  mat.data = new int* [row];

  for (int i = 0; i < row; i++)
    mat.data[i] = new int [col];

  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
      mat.data[i][j] = num[i * col + j];
}
/*
    All functions are Tested and works well!
*/

matrix operator+= (matrix& mat1, matrix mat2){

    assert(mat1.row == mat2.row && mat1.col == mat2.col);
    for(int i =0 ; i<mat2.row ; i++){
        for(int j = 0; j<mat2.col ; j++){
            mat1.data[i][j] += mat2.data[i][j];
        }
    }

    return mat1;
}

matrix operator-= (matrix& mat1, matrix mat2){

    assert(mat1.row == mat2.row && mat1.col == mat2.col);

    for(int i =0 ; i<mat2.row ; i++){
        for(int j = 0; j<mat2.col ; j++){
            mat1.data[i][j] -= mat2.data[i][j];
        }
    }

    return mat1;


}
matrix operator+= (matrix& mat, int scalar){
    for(int i =0 ; i<mat.row ; i++){
        for(int j = 0; j<mat.col ; j++){
            mat.data[i][j] += scalar;
        }
    }

    return mat;
}

matrix operator-= (matrix& mat, int scalar){
    for(int i =0 ; i<mat.row ; i++){
        for(int j = 0; j<mat.col ; j++){
            mat.data[i][j] -= scalar;
        }
    }

    return mat;

}

void   operator++ (matrix& mat){
    for(int i =0 ; i<mat.row ; i++){
        for(int j = 0; j<mat.col ; j++){
            mat.data[i][j]++;
        }
    }


}

void   operator-- (matrix& mat){
    for(int i =0 ; i<mat.row ; i++){
        for(int j = 0; j<mat.col ; j++){
            mat.data[i][j]--;
        }
    }


}


istream& operator>> (istream& in, matrix& mat){
    in >> mat.row ;
    in >> mat.col;
    int data[mat.row*mat.col];

    for(int i = 0 ; i < mat.row*mat.col; i++){
        in >> data[i];
    }

    createMatrix(mat.row,mat.col,data,mat);


    return in;
}



//----------------------------------------------------------------Karim
// cout ----> out.
ostream& operator<<(ostream& out, matrix mat){
  for (int i = 0; i <mat.row; i++){
    for (int j = 0; j <mat.col; j++){
     out<< mat.data[i][j]<<" ";
    }
    out << endl;
  }
   out<<endl;
}



bool   operator== (matrix mat1, matrix mat2){

   if (mat1.row == mat2.row && mat1.col == mat2.col){
        for (int i = 0; i < mat1.row; i++) {
            for (int j = 0; j < mat2.col; j++){
                if (mat1.data[i][j] != mat2.data[i][j]){
                    //cout<<"two matrix are not equal"<<endl;
                    //return false;
                    return false;
                }
            }
        }
    }else{
        return false;

    }
    //cout<<"two matrix are equal"<<endl;;
    return true;
}


bool operator!= (matrix mat1, matrix mat2){
    return  !(mat1 == mat2);

}





bool   isSquare   (matrix mat1){
    cout<<endl;
    if(mat1.row == mat1.col){
       // cout<<"the matrix is square"<<endl;
        return true;
    }
    //cout<<"the matrix is not square"<<endl;
    return false;
}


bool   isSymetric (matrix mat1){
    //cout<<endl;
    if(mat1.row == mat1.col){
        //cout<<"the matrix is square"<<endl;
        for(int i=0;i<mat1.row;i++){
            for(int j=0;j<mat1.col;j++){
                if(mat1.data[i][j]!=mat1.data[j][i])
                {
                   // cout<<"Matrix is not symmetric matrix "<<endl;
                    return false;
                }
            }
        }
    //cout<<"Matrix is symmetric"<<endl;}
    }else{
       // cout<<"Matrix is not symmetric and not square"<<endl;
       return false;
    }
    return true;
}


bool   isIdentity (matrix mat1){
    //cout<<endl;
    for(int i=0; i<mat1.row; i++){
         for(int j=0; j<mat1.col ;j++){
            if(i==j && mat1.data[i][j]!=1)
            {
                //cout<<"the matrix is not identity"<<endl;
                return false;
            } else if(i!=j && mat1.data[i][j]!=0)
            {
               // cout<<"the matrix is not identity"<<endl;
                return false;
            }

        }
    }
   //cout<<"the matrix is identity"<<endl;
   return true;
}


matrix transpose(matrix mat1){
    //cout<<endl;
    //cout << "the Entered Matrix:  "<<endl;
   /* for(int i=0; i<mat1.row; i++){
        for(int j=0; j<mat1.col; j++){
            cout<<mat1.data[i][j]<<" ";
        }
    }
    */

    matrix newmat1;
    newmat1.row = mat1.col;
    newmat1.col = mat1.row;

    newmat1.data = new int* [newmat1.row];
    //newmat1.data = new int* [mat1.col];

    for (int i = 0; i < newmat1.row; i++)
        newmat1.data[i] = new int [newmat1.col];

        //cout<<endl;
        //cout<<"Transpose of Matrix: "<<endl;
    for (int i = 0; i < mat1.row; i++){
        for (int j = 0; j < mat1.col; j++){
            newmat1.data[j][i] = mat1.data[i][j] ; //  was : newmat1.data[i][j] = mat1.data[j][i]
        }

    }
    return newmat1;

}



//-----------------------------------------------------------------------------OMAR

matrix operator+(matrix mat1, matrix mat2){

    matrix mat3;
    mat3.row = mat1.row;
    mat3.col = mat1.col;
    //create empty mat

    mat3.data = new int*[mat3.row];
    for(int i =0; i<mat3.col; i++)
        mat3.data[i] = new int[mat3.col];

    assert((mat1.row==mat2.row)&&(mat1.col==mat2.col));


    for(int i=0;i<mat1.row;i++)
    {
        for(int j=0;j<mat1.col;j++)
        {
            mat3.data[i][j]=mat1.data[i][j]+mat2.data[i][j];
        }
    }


    return mat3;

}


matrix operator-  (matrix mat1, matrix mat2)
{
    matrix mat3;
    mat3.row = mat1.row;
    mat3.col = mat1.col;
    //create empty mat

    mat3.data = new int*[mat3.row];
    for(int i =0; i<mat3.col; i++)
        mat3.data[i] = new int[mat3.col];


    assert((mat1.row==mat2.row)&&(mat1.col==mat2.col));


    for(int i=0;i<mat1.row;i++)
    {
        for(int j=0;j<mat1.col;j++)
        {

            mat3.data[i][j]=mat1.data[i][j]-mat2.data[i][j];

        }


    }
    return mat3;
}




matrix operator*  (matrix mat1, matrix mat2)
{

    matrix mat3;
    mat3.row = mat1.row;
    mat3.col = mat2.col;
    //create empty mat

    mat3.data = new int*[mat3.row];
    for(int i =0; i<mat3.col; i++)
        mat3.data[i] = new int[mat3.col];



    int sum=0;
    assert((mat1.col)==(mat2.row));

    for(int i=0;i<mat1.row;i++)
    {
        for(int j=0;j<mat2.col;j++)
        {
            for(int k=0;k<mat2.row;k++)
            {
                sum += mat1.data[i][k]*mat2.data[k][j];
            }
            mat3.data[i][j]=sum;
            sum=0;
        }
    }

    return mat3;
}


matrix operator+(matrix mat1, int scalar)
{

    matrix mat3;
    mat3.row = mat1.row;
    mat3.col = mat1.col;
    //create empty mat

    mat3.data = new int*[mat3.row];
    for(int i =0; i<mat3.col; i++)
        mat3.data[i] = new int[mat3.col];


    for(int i=0;i<mat1.row;i++)
    {
        for(int j=0;j<mat1.col;j++)
        {
            mat3.data[i][j] = mat1.data[i][j]+scalar;
        }
    }

    return mat3;
}


matrix operator-(matrix mat1, int scalar)
{
    matrix mat3;
    mat3.row = mat1.row;
    mat3.col = mat1.col;

    //create empty mat
    mat3.data = new int*[mat3.row];
    for(int i =0; i<mat3.col; i++)
        mat3.data[i] = new int[mat3.col];



    for(int i=0;i<mat1.row;i++)
    {
        for(int j=0;j<mat1.col;j++)
        {
            mat3.data[i][j] = mat1.data[i][j]-scalar;
        }

    }
    return mat3;
}

matrix operator*  (matrix mat1, int scalar)
{
    matrix mat3;
    mat3.row = mat1.row;
    mat3.col = mat1.col;

    //create empty mat
    mat3.data = new int*[mat3.row];
    for(int i =0; i<mat3.col; i++)
        mat3.data[i] = new int[mat3.col];



    for(int i=0;i<mat1.row;i++)
    {
        for(int j=0;j<mat1.col;j++)
        {
            mat3.data[i][j] = mat1.data[i][j]*scalar;

        }
    }

    return mat3;
}


















