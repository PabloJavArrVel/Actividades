// =================================================================
//
// File: main.cpp
// Author: Pablo Javier Arreola Velasco
// Date: 31 de Agosto de 2020
//
// =================================================================
#include <iostream>
#include <string.h>
#include <vector>
#include "header.h"
#include "search.h"
#include "bubble.h"
#include "selection.h"
#include "insertion.h"
#include <fstream>

std::vector <int> retrieve(std::fstream &file, int startLine){
	//We get the size of the vector and initialize it with it
	std::string Auxsize;
	int size;
	int j = 0;
	//We iterate to get to the line we're interested in and get the size
	for (int i = 0;i<startLine;i++){
		std::getline(file,Auxsize);
	}
	size=stoi(Auxsize);
	//With the size we set a vector and we get to the line with the elements of it
	std::vector <int> arr(size);
	std::string line,currentNumber;
	//We read each element in the line and add it to the vector 
	std::getline(file,line);
	for (int i = 0;i<line.size();i++){
		if (line[i] == ' '){
			arr.at(j)=(stoi(currentNumber));
			currentNumber=' ';
			j++;
		}
		else{
			currentNumber+=line[i];
		}
	}
	return arr;
}

void printVector(std::vector <int> x){
	for (int i=0;i<x.size();i++){
		std::cout<<x.at(i)<<std::endl;
	}
}

//To test diff:
//diff mysolution1.txt solution1.txt
//diff mysolution2.txt solution2.txt
//diff mysolution3.txt solution3.txt
//diff mysolution4.txt solution4.txt
int main(int argc, char* argv[]) {
	//We open the file 
	std::fstream inFile;
	std::fstream output1;
	inFile.open("input1.txt",ios::in);
	output1.open("mysolution1.txt",fstream::out);
	//We retrieve arr 1 wich contains the elements to be sorted and arr2 wich contains the elements 
	// to be found in arr1
	std::vector <int> arr1=retrieve(inFile,1);
	std::vector <int> arr2=retrieve(inFile,1);
	std::vector <int> aux=arr1;
	//We perform each sorting algorithm and add the comparisons to file
	output1<<to_string(bubbleSort(arr1).back());
	arr1 = aux;
	output1<<' ' + to_string(selectionSort(arr1).back());
	arr1 = aux;
	output1<<' '+ to_string(insertionSort(arr1).back())<<endl;
	arr1.pop_back();
	output1<<endl;
	//We perform each searching algorithm using arr2 as a guide and add them to the file
	for(int i = 0;i<arr2.size();i++){
		output1<<to_string(sequentialSearch(arr1,arr2.at(i)));
		sequentialSearchII(arr1,arr2.at(i));
		output1<<' ' +to_string(arr1.back());
		arr1.pop_back();
		binarySearchII(arr1,arr2.at(i));
		output1<<' '+to_string(arr1.back())<<endl;
		arr1.pop_back();
	}
	inFile.close();
	output1.close();
	return 0;
}
