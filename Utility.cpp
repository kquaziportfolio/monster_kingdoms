/***

 ABOUT THIS FILE
 ---------------

 This code is the implementation (definitions) of all the functions
 listed in utils.h.

 THERE IS NO NEED TO READ ANY OF THIS. If anything is broken, it is my
 fault and I will fix it. You should leave all of this code alone.

***/

#include "Utility.h"
#include "GameException.h"
#include <cctype>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define Fail(x) { cerr << x << endl; exit(-1); }

string Utility::ConvertToLowercase(string s)
{
  string result = "";
  for (unsigned int i = 0; i < s.length(); i++)
    {
      result += tolower(s[i]);
    }
  return result;
}

string Utility::ConvertToUppercase(string s)
{
  string result = "";
  for (unsigned int i = 0; i < s.length(); i++)
    {
      result += toupper(s[i]);
    }
  return result;
}


string Utility::ConvertToString(int iNum)
{
  char buf[100];
  int result = sprintf(buf, "%i", iNum);
  if (result < 0)
    Fail("Could not convert " << iNum << " to a string.");

  return string(buf);
}

string Utility::ConvertToString(double dNum)
{
  char buf[100];

  int result = sprintf(buf, "%lf", dNum);
  if (result < 0)
    Fail("Could not convert " << dNum << " to a string.");

  result--;
  while (result > 0 && buf[result] == '0')
    buf[result--] = '\0';

  if (buf[result] == '.')
    buf[result + 1] = '0';
  return string(buf);
}


vector<string> Utility::DivideLineIntoWords(string line)
{
  unsigned long e;
  vector<string> result;
  while (1)
  {
      e = line.find(" ");
      if (e < line.length())
      {
          result.push_back(line.substr(0, e));
          line = line.substr(e+1);
      }
      else
      {
          result.push_back(line);
          break;
      }
  }
  return result;
}

void Utility::PrintWrappedString(string text)
{
  /*const int MAX_WIDTH = 60;
    string str=text;
    unsigned long pos = 0;
    unsigned long last = 0;
    while ((pos = str.find(" ", pos)) != string::npos)
    {
      if ((pos - last) > MAX_WIDTH)
        {
            str[pos] = '\n';
            last = pos;
        }
        pos++;
    }*/
	string str=text;
    cout << str << endl;
}
int Utility::SoldToNum(string name){
	if(name=="Soldier")
		return 1;
	else if(name=="Assassin")
		return 2;
	else if(name=="Knight")
		return 3;
	throw GameException("Not a valid name!");

}
void Utility::UnAbbreviate(string & word)
{
  string std_abbrevs[14] = { "n", "s", "e", "w", "ne", "nw", "se", "sw", "u", "d", "x", "l", "i", "q" };
  string std_words[14] = { "north", "south", "east", "west", "northeast", "northwest", "southeast", "southwest", "up", "down", "examine", "look", "inventory", "quit" };

  for (int i = 0; i < 14; i++)
  {
    if (word == std_abbrevs[i])
    {
      word = std_words[i];
      return;
    }
  }
}

string Utility::whoWon(string attacker,string defender){
	int atk=Utility::SoldToNum(attacker);
	int dfn=Utility::SoldToNum(defender);
	if(atk==dfn)
		return "-1";
	else if(atk==1&&dfn==2)
		return "A";
	else if(atk==1&&dfn==3)
		return "D";
	else if(atk==2&&dfn==1)
		return "D";
	else if(atk==2&&dfn==3)
		return "A";
	else if(atk==3&&dfn==1)
		return "A";
	else if(atk==3&&dfn==2)
		return "D";
	throw GameException("Unknown Internal Error");
}
;
