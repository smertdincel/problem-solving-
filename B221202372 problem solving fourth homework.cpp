//***********************************************************************************************************************************************************************
//****************************************                        STUDENT NAME=SADIK MERT DÝNCEL                          ***********************************************
//****************************************                        STUDENT NUMBER=B221202372                               ***********************************************
//****************************************                        HONOR CODE= I  DID  MYSELF HOMEWORK                     ***********************************************
//****************************************            ASSIGNMENT=PROBLEM SOLVING IN SOFTWARE ENGINEERING FOURTH HOMEWORK  ***********************************************
//***********************************************************************************************************************************************************************

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <ctime>				
#include <cctype>     
#include <cstring> 
#include <cstdlib>

using namespace std;
 int SIZE;

int main (){
	srand(time(NULL));
	cout<<"***************INPUT MATRIX******************\n";
	
	cout << "Elements should be between 0 and 10" << endl;
	int SIZE = rand() % 16 + 5; //size randomly between 5-20
	
	
	int **inputmatrix;                  //------------------->
     inputmatrix = new int*[SIZE];      //------------------------>
     for (int i = 0; i < SIZE; i++) {   //-------------------------->>>>>>>Dynamically defining the input matrix 
     inputmatrix[i] = new int[SIZE];    //------------------------>
   }                                    // ------------------>
	

	
	
	
	 for(int i=0;i<SIZE;i++)
	  for(int j=0;j<SIZE;j++)         // Input matrix randomly generated from 1 to 10  
		inputmatrix[i][j]=rand()%10;
		
	
	for(int i=0;i<SIZE;i++)
	{
	  for(int j=0;j<SIZE;j++)
	  {
	  	cout<<setw(5)<<inputmatrix[i][j];    //print screen
	  }	
	  cout<<endl;
		
	}
	
		int coreSIZE= rand() % 4 + 2;       //create coresize between 2-5
	
		cout << "******************CORE MATRIX******************\n";
	int **coreMatrix;                      //---------------->
	coreMatrix = new int*[coreSIZE];       //-------------------->
    for (int i = 0; i < coreSIZE; i++) {   //------------------------>>>>>> Dynamically defining the core matrix
    coreMatrix[i] = new int[coreSIZE];     //-------------------->
   }                 					   //---------------->
	
	
	
	cout << "Elements should be between 0 and 10" << endl;
	

	// For loops for taking every element of matrix
	for (int i = 0; i < coreSIZE; i++)       //-------------->
	    for (int j = 0; j < coreSIZE; j++)   //------------------->>>> The core matrix consists of random numbers between 1and 10
		      coreMatrix[i][j]=rand() % 10;  //-------------->
		      

	for (int i = 0; i < coreSIZE; i++){       //---------->
		for (int j = 0; j < coreSIZE; j++){   //-------------->
			cout<<setw(5)<<coreMatrix[i][j];  //------------------>>>> print screen core matrix
		}	                                  //-------------->
		cout<<endl;                           //--------->
		
	}
	          
	
		                                       
    
	int outputSIZE = (SIZE - coreSIZE) + 1;                 // Calculating output matrix sizes
	
	
	int **outputMatrix;                           //-------------->
	outputMatrix = new int*[outputSIZE];          //------------------->
    for (int i = 0; i < outputSIZE; i++) {        // ------------------------>>>> Dynamically defining the output matrix
    outputMatrix[i] = new int[outputSIZE];        //------------------->
   }                                              //-------------->
	
	
    int temp =0;            //temporary variable
	// Calculating every element of output matrix
	for (int i = 0; i < outputSIZE; i++)
	{
		for (int j = 0; j < outputSIZE; j++)
		{
			// For every output multiple core matrix and input matrix
			for (int A = 0; A < coreSIZE; A++)
			{
				for (int B = 0; B < coreSIZE; B++)
				{
					temp+= coreMatrix[A][B]  * inputmatrix[i+coreSIZE-1-A][j + coreSIZE-1-B ];     //calculation of matrices as shown on the slide
				}
			}
			
			outputMatrix[i][j]=temp;             //equating temporary variable to output Matrix 
			temp=0;
		
		}
	}
	
		cout << "*******************OUTPUT MATRIX*********************\n";
		
		
		for (int i = 0; i < outputSIZE; i++)                  		//--------------->
	{														  		//----------------------->
		for (int j = 0; j < outputSIZE; j++)                  		//------------------------------------->>>>print screen outputmatrix
			cout << setw(5) << outputMatrix[i][j] << setw(5);		//------------------------------>
		cout << "\n";												//----------------------->
	}															    //--------------->
	cout << "****************************************\n";
	
	delete[] inputmatrix; 
	delete[] coreMatrix;
	delete[] outputMatrix;

	// Program end
	system("pause");
	
	return 0;
}
