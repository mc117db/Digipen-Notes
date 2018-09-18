# GAM200 Week 3 - Tuesday
## Topic: Messaging Systems Lecture

### Prerequisites
1. C Programming
2. C++ Object Oriented Programming

---

## What are messages
- A way of communicating between systems or objects that does not rely on 
  directly linked functions.
- A way to decouple systems from each other, ie. remove hard dependencies to 
each other, whichs makes changes to each system propagate locally, not to other systems.
- Decouple the creator of the action from the object that processes the action.
  - For example: Windows Message Loop
  - Collision and Physics
    - Two tightly related systems, they need to call each other to work.
    - Instead of directly calling each other, they can employ messages which they
    send and receive.

## Why we need?
- Allow decoupled communication
  - Across game syustem boundaries
  - Across process boundaires
  - Across network boundaries
  - Across time! (delayed messages)
- Reduces dependencies
  - Have to agree on format and message interface
  - Enable very loose coupling

## Anatomy of a Message
- Run Time Type Identifier
  - Data to represent what kind of message it is.
  - Physic Message, Game Event Message etc.
- Payload
  - Message Specific Data which is consumed by the receiver.

## Basic functionality
- Functions
  - SendMessage
  - BroadcastMessage
  - ReceiveMessage
- Messages are encoded as objects.
- Message objects vary by content (which is their payload)
  - It differs from one system to another.
  - Need to make sure that the correct message is sent to its intended receiver.
  - Less Coupling
    - No direct function calls of other entitites
    - Using function calls may need different signatures that suits the needs of otehr entities
    - Can carry additional data
    - May know their sender
    - Can be time-stamped.
- Examples:
  - Grenade needs to send a message to all objects in its circular zone of a specific radius.
  - Destroy message is sent when all enemies are destroyed. Based on the number of destroyed enemies, a door will be unlocked.

## Messaging Types
- Broadcasting
  - Send Message to everyone
  - Broadcast to all systems/components
  - Require HandleMessage() on every object that can receive a message
  - Slow when the amount of objects are messages is very high
  - All objects have to wait for new messages
  - It can be implemented as a subset of direct delivery
- Direct Delivery
  - Send messages to one object
  - Direct message
    - Ex: Collision system sends direct message to two collided bodies.
  - Not very flexible when other objects/components need to be notified too.
  - Implemented as a single virual method call
  - Can broadcast to children
  - Easy to implement.
- Observers
  - Registers to a source object to receive messages.
  - Each object has a list of interested objects to which it will send messages.
  - Common use in game engines.


