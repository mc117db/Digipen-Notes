# GAM200 Week 3 - Tuesday
## Topic: Data-Driven Engines Lecture

### Prerequisites
1. C Programming
2. C++ Object Oriented Programming

---

## Logic vs Data
- Logic is the functinality of the object or *what the object does*
- Data describes attributes and configurations of the object or *what the object is*
  - Level editor generates the level data
  - Your game engine takes the level data and generates the level.
- You need to separate what the game object do and what the game object is.

## What does Data Driven Engine mean
- Use data files to determine behaviour
  - Level files
  - Archetype files
  - Script files
  - Tweakable files
- Very little hardcoded constants
- The only hardcoded file in the code is to run the configuration file
- Objects are always created using files/database
- No hardcoded "news" for any game object. Creation of objects should be in the data

## Why do Data Driven Engine?
- Engineers work slow, and their time cost alot.
- Game designers are crazy people
  - They need fast iterations, they don't want to touch the code.
  - Non-programmers need to be able to edit content
- Rebuilding large projects takes a long time.
- Massive amount of content
- Embrace change!

## How to implement?
- Need a generic and robust way to load data.
- This process is called **serialization**
- The key is to encapsulate the variability of the data of an object from the
  functionality of how the data is loaded.
- Or what the object needs (HP,position etc) from how the data is read 
  (file,xml,database etc)

## Serialization Pattern
- Special form of the vistior pattern
  - Participants
    - Objects that support the serialize method or interface which defines how it serializes    itself
      - Every person who writes their component needs to write the serializer for his/her component.
    - The serializer or stream object that encapsulate file/database saving and loading
    - Operators that helps to define how object serialize.

- Sample Serializer Interface
<pre><code>
    class ISerializer
    {
      void ReadFloat(float&)
      void ReadInt(int&)
    };
    class TextSerializer: public ISerializer
    {
      class BinarySerializer : public ISerializer
    };

</pre></code>

## Serialization Phases
- Construct the object
  - Constructed object has been built from the factory but is not active.
- Serialization and data setting
  - The object can be serialized and then data attributes can be adjusted.
- Initialize the object
  - Object really comes into existence using all the serialized data.

## Object Management
- Create, manage, and destroy your objects in a unified way.
  - Where you say 'new' should be the same place as you say 'delete'
- Do not use "new" whenever you need an object.
  - Create all of them at the start of game and use them as needed
  - Do not generate all of them in run-time (unless you have a good memory manager)
- Each object should have a clear owner
  - For game objects, use a factory.
    - Factory are used to create game-objects

<pre><code>
GameObject * ObjectFactory::BuildObject(string type)
{
  switch (type){
    case "PlayerObject":
      return new PlayerObject();
    case "EnemyObject":
      return new EnemyObject();
    case "BulletObject":
      return new Bullet()
    }
} 

</pre></code>

<pre><code>
GameObject * ObjectFactory::CreateObject(string type)
{
  GameObject* newObject = BuildObject(type)
  gameObjectList.Add(newObject);
  numberOfObjects++;
  return newObject;
}

</pre></code>

- Distributed Factories
  - newObj = CreatorMap[type]->Create();
  - Use a map to store "creators", which probably are function pointers.


## Data driven Composition
- All objects are just a collection of compoenents.
- Factory has a list of creators for compoennts
- It can then use the data source to determine what components are on the composition.
  - Guy has a Transform,Renderer,Health component etc
  - You can serialize the composition of Guy as its component's

## Archetypes
- An archetypes is a prototype or the original model (blueprint, recipe) for an object. aka prefabs
- The factory use the archetype to build the object and then run time data is modified as needed (like position)
  - Object = car
  - Archetype = BMW
  - Instance = Bill's BMW etc.
- Problems:
  - What data do you want to have to change per object?
    - Positiion, Scale, Rotation?
  - Can Archetypes override anything?

## Data Driven Factory
- Factory's power comes from the fact that its data-driven
- Systems register their compoennts creators to the factory.
- Objects are created through archetypes which describe what components are
on a composition and their attributes.
- Run-time data is modified as needed.