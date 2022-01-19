#include <iomanip>
#include <cstdlib>
#include <fstream>
// This program takes a list of numbers stored in a file and produces an 
// output file which only contains one of each number found in the input
// file.
// 
// Programmer:    Andrew Coviello
// Homework 9
// Project 2
// Problem Statement: Write a program that reads a file of numbers of type 
// int and outputs all of those numbers to another file, but without any 
// duplicate numbers.  After the program is run, the output file should 
// contain all numbers that are in the original file, but no number should 
// appear more than once.  Numbers in both files should appear on separate 
// lines in the file.
// 
// 1. Establish integer values for the number that the user will
// be entering to look for in the databases, and the filenames.
// 2. Establish file streams.
// 3. Initialize a large while loop to keep track of a sentinel value,
// quit, which will exit the program if entered(the program would 
// otherwise run forever).
// 4. Prompt the user for the name.
// 5. Use an outer loop first to search the file with girl names, then on 
// the second pass search the file with boy names.
// 6. Within the outer loop:
// Open the appropriate file (either with girl names or boy names).
// Use an inner loop to scan the file looking for the specified name.  
// Use the cin object and the stream extraction operator >> to read 
// each name a number of births.
// If the name is found, then show the user the rank and number or 
// registered births for that name.
// If the name isn't found in the file, tell the user that it isn't one 
// of the ranked names.
// Close the file. 
// 7. Once both files have been processed, go back and prompt for another 
// name. Stop the program when the user enters "quit".
//
#include <iostream>
using namespace std;

int main() {

  // file input stream to receive input 
  ifstream infile;
  // file output stream to receive output
  ofstream outfile;
  // numbers used to store the values of the current and previous ints,
  // as well as the number of duplicates in the input file
  int currentInt, prevInt, count = 0, count2 = 0;
  // strings used in reading process
  string nameStr, currentName;
  // boolean flag used to check for the first integer in the file, which 
  // has no previous
  bool isFirstInteger = true;
  // constant string names used to properly link the files to their
  // readers
  const string FILE_NAME_1 = "numbers.txt", FILE_NAME_2 = "output.txt";

  // beginning display prompts user for duplicate numbers program  
  cout << setw(30) << "****** Duplicate Numbers ******\n" << endl;
  // open input file to extract input
  infile.open(FILE_NAME_1);
  // open output file to insert output
  outfile.open(FILE_NAME_2);
  // string flag to represent output file data
  cout << "Outfile: " << endl;
  // while loop parses through each number
  while(infile >> currentInt)
  {
    // if statement uses short circuit semantics to choose a case in which
    // the current int is either the first int or different from the
    // previous
    count2++;
    if(currentInt != prevInt || isFirstInteger)
    {
      // append a count of duplicates
      count++;
      isFirstInteger = false;
      cout << currentInt << endl;        
      outfile << currentInt << endl;      
    }
    prevInt = currentInt;
  }
  cout << "There are " << count2 << " numbers in the infile." << endl;
  cout << "There are " << count << " numbers in the infile, excluding duplicates. There are " << count << " numbers in the outfile." << endl;
  cout << "There are " << count2 - count << " duplicates in the infile.";
  infile.close();
  outfile.close();
}
