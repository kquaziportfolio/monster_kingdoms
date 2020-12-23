#include "GameEntity.h"
#include "GameException.h"
#include "Utility.h"

#include <iostream>
using namespace std;

GameEntity::GameEntity(string objName, string objDescription)
{
  /// TO DO:
  /// Implement this constructor.
  /// * If the name is empty, it should throw an exception with the message
  ///     "An game entity cannot have an empty name."
  /// * If the description is empty, it should throw an exception with the message
  ///     "An game entity cannot have an empty description."
      name = objName;
      description = objDescription;
      enclosure=NULL;
      if (objName == "" )
        throw GameException("An game entity cannot have an empty name.");
      else if(objDescription == "" )
        throw GameException("An game entity cannot have an empty description.");

}

/// TO DO: Implement the GetName method (return the current object's name)
string GameEntity:: GetName() const
{
    return name;
}


/// TO DO: Implement the GetDescription method (return the current object's description)
string GameEntity:: GetDescription() const
{
    return description;

}


/// TO DO: Implement the GetEnclosure method (return the current object's enclosure)
GameEntity * GameEntity::GetEnclosure() const
{
    return enclosure;

}


void GameEntity::ListContents() const
{
  /// TO DO:
  /// Print the *name* of each object in the contents map, on separate lines.
   cout << "List contents:" << endl;

   for(map<string,GameEntity*> ::const_iterator it = contents.begin();it != contents.end();it++)
   {
       cout << "  " << it->first << endl;
   }

}

GameEntity * GameEntity::FindInContents(string objName)
{
  /// TO DO:
  /// Check whether the objName exists as a key in the contents map.
  /// * If it does exist, return the corresponding value.
  /// * If it does not next, return NULL.
  map<string, GameEntity*>::iterator it = contents.find(objName);

  if(it != contents.end())
    return it->second;
  else
     return NULL; /// THIS IS JUST A PLACEHOLDER
}

void GameEntity::Add(GameEntity * obj)
{
  /// TO DO:
  /// (1) Add the given value to the contents map.
  /// (2) Adjust the enclosure value of the given object appropriately.
  /// * HOWEVER, if the map already has an item with the same name,
  ///    throw a GameException with the message
  ///    "Attempt to insert a second ___ into ___"
   if(!this->Examine(obj->name))
   {
       contents.insert(pair<string,GameEntity*>(obj->name, obj));
       obj->enclosure = this; ///adjust the obj enclosure
   }
   else
    throw GameException("Attempt to insert a second object into the map");

}


bool GameEntity::Examine(string objName)
{
  /// TO DO:
  /// (1) Search the contents map to see if an object with the given name exists.
  /// (2) If not, return false.
  /// (3) Otherwise, call the Describe() method of the object you found,
  ///       then return true.
  /// [HINT: Use the FindInContents() method that you already wrote.]
   GameEntity *found = this->FindInContents(objName);
   if(found == NULL)
     return false;
   else
   {
       found->Describe();
       return true;
   }
}

GameEntity * GameEntity::Remove(string objName)
{
  /// TO DO:
  /// (1) Search the contents map to see if an object with the given name exists.
  /// (2) If not, return NULL.
  /// (3) Otherwise:
  ///     a) remove the corresponding entry from the contents map
  ///     b) set the enclosure of that object to NULL.
  /// [HINT: Use the FindInContents() method that you already wrote.]
  GameEntity *ptrGE = this->FindInContents(objName);
  if(ptrGE == NULL)
    return NULL;
  else
  {
      contents.erase(objName);
      ptrGE->enclosure = NULL;
      return ptrGE;
  }
}


/// These are already implemented. DO NOT CHANGE THEM.

void GameEntity::Describe()
{
  Utility::PrintWrappedString(description);
}

void GameEntity::Eat()
{
  cout << "The " << name << " is not edible." << endl;
}

void GameEntity::Open()
{
  cout << "The " << name << " is not something you can open." << endl;
}

void GameEntity::Close()
{
  cout << "The " << name << " is not something you can close." << endl;
}


/*
#include "GameEntity.h"
#include "GameException.h"
#include "Utility.h"

#include <iostream>
using namespace std;

GameEntity::GameEntity(string objName, string objDescription)
{
  /// TO DO:
  /// Implement this constructor.
  /// * If the name is empty, it should throw an exception with the message
  ///     "An game entity cannot have an empty name."
  /// * If the description is empty, it should throw an exception with the message
  ///     "An game entity cannot have an empty description."
      name = objName;
      description = objDescription;
      if(objName == "")
        throw("An game entity cannot have an empty name.");
      if(objDescription =="")
        throw("An game entity cannot have an empty description.");
}

/// TO DO: Implement the GetName method (return the current object's name)
string GameEntity:: GetName() const
{
    return name;
}


/// TO DO: Implement the GetDescription method (return the current object's description)
string GameEntity:: GetDescription() const
{
    return description;

}


/// TO DO: Implement the GetEnclosure method (return the current object's enclosure)
GameEntity * GameEntity::GetEnclosure() const
{
    return enclosure;

}


void GameEntity::ListContents() const
{
  /// TO DO:
  /// Print the *name* of each object in the contents map, on separated lines.
 //  for(map<string,GameEntity*> iterator::iter = contents.begin();iter != contents.end();iter++)
 //  {
 //      cout << (*iter).first << (*iter).second << endl;
 //  }
//

   map<string,GameEntity*>::const_iterator it;// = contents.begin();
   //iterator it = this->contents.begin();

   for (it=contents.begin(); it!=contents.end(); ++it)
        cout << it->first << " => " << it->second << '\n';

}

GameEntity * GameEntity::FindInContents(string objName)
{
  /// TO DO:
  /// Check whether the objName exists as a key in the contents map.
  /// * If it does exist, return the corresponding value.
  /// * If it does not nexit, return NULL.
  map<string, GameEntity *>::iterator it;// = exits.begin();
  it = contents.find(objName);

  if(it != contents.end())
     return it->second;
  else
     return NULL; /// THIS IS JUST A PLACEHOLDER
}

void GameEntity::Add(GameEntity * obj)
{
  /// TO DO:
  /// (1) Add the given value to the contents map.
  /// (2) Adjust the enclosure value of the given object appropriately.
  /// * HOWEVER, if the map already has an item with the same name,
  ///    throw a GameException with the message
  ///    "Attempt to insert a second ___ into ___"
   contents.insert(pair<string, GameEntity *>(name, obj));

}


bool GameEntity::Examine(string objName)
{
  /// TO DO:
  /// (1) Search the contents map to see if an object with the given name exists.
  /// (2) If not, return false.
  /// (3) Otherwise, call the Describe() method of the object you found,
  ///       then return true.
  /// [HINT: Use the FindInContents() method that you already wrote.]
    if(contents.find(objName) != contents.end())
        Describe();
    else
        return false;

    return true;
}

GameEntity * GameEntity::Remove(string objName)
{
  /// TO DO:
  /// (1) Search the contents map to see if an object with the given name exists.
  /// (2) If not, return NULL.
  /// (3) Otherwise:
  ///     a) remove the corresponding entry from the contents map
  ///     b) set the enclosure of that object to NULL.
  /// [HINT: Use the FindInContents() method that you already wrote.]
  map<string, GameEntity *>::iterator it;// = exits.begin();
  it = contents.find(objName);

  if(it != contents.end())
  {
      contents.erase(it);//contents.begin() + i); ///remove entry
      enclosure == NULL;
  }

  else
      return NULL; /// THIS IS JUST A PLACEHOLDER
}



/// These are already implemented. DO NOT CHANGE THEM.

void GameEntity::Describe()
{
  Utility::PrintWrappedString(description);
}

void GameEntity::Eat()
{
  cout << "The " << name << " is not edible." << endl;
}

void GameEntity::Open()
{
  cout << "The " << name << " is not something you can open." << endl;
}

void GameEntity::Close()
{
  cout << "The " << name << " is not something you can close." << endl;
}

*/
