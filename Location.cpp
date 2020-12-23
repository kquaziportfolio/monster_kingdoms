#include "Location.h"
#include "GameException.h"
#include "Utility.h"


/// TO DO:
/// Implement the Location constructor
/// [Hint: The body of this method will remain empty]
  Location::Location(string locName, string locDescription)
       : GameEntity(locName, locDescription)
  {

  }



void Location::AddExit(string direction, Location * whereTo)
{
      /// TO DO:
      /// Add the given exit to the exits map.
      /// * HOWEVER, if the given direction already exists as a key in the map,
      ///    throw a GameException with the message
      ///    "Cannot add an second exit from ___ with direction"
     map<string, Location*>::iterator it = exits.find(direction);
     if(it != exits.end())   ///direction already in exits maps
        throw GameException("Cannot add an second exit from " + direction + "with direction");
     else
        exits.insert(pair<string,Location*>(direction, whereTo));  ///insert only if not exits

}

Location * Location::FindExit(string direction) const
{
      /// TO DO:
      /// Check the exits map for an entry with the given direction as its key.
      /// If there is no such exit, return NULL.
      /// If there is, return the corresponding pointer-to-Location
       map<string,Location*>::const_iterator it = exits.find(direction);

       if(it !=exits.end())
          return it->second;
       else
       return NULL; /// THIS IS JUST A PLACEHOLDER
}

void Location::Describe()
{
  /// TO DO:
  /// (1) Print the location's name in *ALL CAPS*.
  /// (2) Print the location's description.
  /// (3) If there are any objects in the location's contents:
  ///     a) Print "Here you can see __ things:"
  ///     b) Call ListContents()


    string nameUpperCase = Utility::ConvertToUppercase(name);
//    Utility::PrintWrappedString(nameUpperCase);
//    cout << description << endl;
    cout << "Location in upper case: " <<  nameUpperCase << endl;
    if(exits.size() > 0)
    {
        cout << "Here you can see " << exits.size() << " " << "things:" << endl;
        ListContents();
    }

}


