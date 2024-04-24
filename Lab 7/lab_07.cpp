// 3/29/23
// Vincent Fealy

#include <iostream>
#include <fstream>
#include <string>
#include "d_hash.h"
#include "d_hashf.h"
#include "d_except.h"

void getWord(ifstream& fin, string& w);

int main(){
    std::cout << " " << std::endl;

    int bucket = 1373; //1373 buckets as said in instructions

    myhash<string, hFstring>htable(bucket);
    //Read the "dict.dat" file and insert the words into a hash table with with 1373 buckets. The file "dict.dat" contains 25,025 frequently used words, each on a separate line in lowercase
    //Opening the file dict.dat
    ifstream dict ("dict.dat");

    if(dict.is_open()){
        ///this string is keeping the current word
        string words;
        // this string is needed to hold that word as you will need it
        //for loop to insert word into the hash table
        for(int i = 0; i < 25025; i++ ){
            dict >> words;
            htable.insert(words);
        }
    }
    else{
        std::cout << "Error!!!" << std::endl;
    }

    dict.close();
    // string holding the document name
    string document;

    //Once the document is entered, it will then read the file
    std::cout << "Enter the document name: " << std::endl;
    std::cin >> document;

    ifstream myExample (document);
    string myExampleWord;
    if(myExample.is_open()){
        
        while(!myExample.eof()){
            getWord(myExample, myExampleWord);

            if(htable.end() == htable.find(myExampleWord)){
                std::cout << myExampleWord << std::endl;
            }
        }
        myExample.close();
    }
    else{
        std::cout << "Error!" << std::endl;
    }
}

// getWord function provided
void getWord(ifstream& fin, string& w)
{
	char c;

	w = "";	// clear the string of characters

	while (fin.get(c) && !isalpha(c));	// do nothing. just ignore c

	// return on end-of-file
	if (fin.eof())
		return;

	// record first letter of the word
	w += tolower(c);

	// collect letters and digits
	while (fin.get(c) && (isalpha(c) || isdigit(c)))
		w += tolower(c);
}
