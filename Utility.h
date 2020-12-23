#ifndef UTILITY_H
#define UTILITY_H
#include <vector>
#include <string>
#include <iostream>
using namespace std;

/***

 ABOUT THIS FILE

 The Utility class provides a set of STATIC utility functions
 that are likely to be useful for this project.

***/

class Utility
{
  public:
	/// Returns a version of the given string with all
	/// characters converted to lowercase.
	static string ConvertToLowercase(string s);

	/// Returns a version of the given string with all
	/// characters converted to uppercase.
	static string ConvertToUppercase(string s);

	/// Converts the given integer to a string.
	static string ConvertToString(int iNum);

	/// Converts the given double to a string.
	static string ConvertToString(double dNum);

	/// Returns a vector whose components are the individual
	/// words from the given string
	static vector<string> DivideLineIntoWords(string line);

	/// Returns a string that is equivalent to the given string,
	/// but with newlines added so it is divided into lines within the
	/// given maximum width.
	static void PrintWrappedString(string text);

	/// If the given string is a common abbrevation (e.g., "i" for "inventory"),
	/// this *changes* that string to the full-word equivalent.
	static void UnAbbreviate(string & word);

	static int SoldToNum(string name);
	static string whoWon(string attacker, string defender);
};


#endif // UTILITY_H
