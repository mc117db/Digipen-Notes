# Week 6 - GAM200 (Tuesday)
## Topic: Game Physics
- Prerequisites: CS230
---
## Game Physics
- Physic Based Motion
  - Want games objects to move consistent with real world expectations
  - Player expectations include movie physics (stylished).
  - Need to be stable
  - Need to be deterministic (predictable and reproducable)
  - Needs to be fast
- Simple Physics
  - Newtonian rigid body dynamics
  - Basic equations of motions
- Continuous Physics
  - Look ahead and predict whether objects going to collide.
    - Good for small fast moving objects
  - Search for collision in continuous time and find expected time of impact for each object pair
  - Determine the first colliding pair, move forward to that time and resolve collision
  - Problems
    - Expensive and complex.
- Discrete Physics
  - Objects moved via basic Newtonian physics by a time interval (a frame)
  - Collision are detected at sample intervals in time
  - Inaccurate but realistic looking
  - Very fast.
  - Problems
    - Objects can tunnel (miss collisions when object moves too fast).
    - Late Detection
      - What is the collision normal?
        - How did these objects get this way? and how will I do the collision response?
        - Solutions:
          - Move objects in small steps within a frame
            - Expensive
          - Increase collision data size eg. Bounding Rectangle.
  - Favour Discrete Physics when...
    - In cases where you don't need accuracy
    - Much faster and simpler than continuous
    - Result is good enough.
    - Can be scaled to higher frame-rates

# Linear Dynamics
- Have:
  - Last frame position
  - Last frame velocity
  - Mass
  - Set of forces
- Need to determine
    - Current frame position
    - Current frame velocity

# Newtonian physics
- All objects affected by forces
- Forces determine acceleration
- Acceleration changes velocity
- Velocity changes position.
  - Summing Forces
    - All forces on a body can be summed into a single forces
      - Just add all forces together.

# Forces type
- Linear direction forces - Props
  - Unit direction
    - Where the force pushes
  - Magnitude
    - How strong the force
  - Lifetime
    - How long to apply the forces.
    - Lifetime 0 = forever.
  - Age (current time since created/activated)
    - When activated, age = 0
  - Is active
- Rotational Forces
  - Torque
  - Lifetime
  - Age
  - IsActive
- Drag Force
  - Directional Drag
    - A scalar: applies opposite to velocity
  - Rotational Drag
    - A scale: opposite from angular velocity
  - Lifetime
  - Is active

# Dynamics
- A component that holds the physics dynamics for an entity
- Possible properties
  - Mass
  - Inertia Mass
  - Position
  - Velocity and Acceleration
  - Angular velocity and angular acceleration
  - Center of mass (affects rotational physics)
- Directional Form
  - Sum(Forces) = mass * acceleration
  - Acceleration integrates velocity
  - Velocity integrates position.
- Rotational Form
  - Sum(Torques) = inertia mass * angular accel.
  - Angular acceleration integrates angular velocity.
  - Angular velocity integrates angle.
