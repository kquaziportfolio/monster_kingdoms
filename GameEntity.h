#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include <string>
#include <map>
using namespace std;

class GameEntity
{
 //static map<string, GameEntity *> contents;

 protected:
  /// All objects in the entire game have a name and description.
  string name;
  string description;

  /// A map of which objects are contained inside this one (possibly none),
  ///  with their names as the keys
  map<string, GameEntity *> contents;

  /// A pointer to the object this object is inside (possibly NULL)
  GameEntity * enclosure;

 public:
  /// Constructor
  GameEntity(string objName, string objDescription);

  /// Basic accessors -- these should never be overridden
  string GetName() const;
  string GetDescription() const;
  GameEntity * GetEnclosure() const;
  void ListContents() const;

  /// Mutators to find/add/remove objects
  virtual GameEntity * FindInContents(string objName);
  virtual void Add(GameEntity * obj);

  /// Methods that handle player actions applied to the current object
  virtual void Describe();
  virtual void Eat();
  virtual void Open();
  virtual void Close();

  /// Methods that handle player actions applied to CONTENTS OF the current object
  virtual bool Examine(string objName);
  virtual GameEntity * Remove(string objName);
};

#endif // GAMEENTITY_H

