# Particle System - How to Use
## Introduction
- The particle system is composed of a set of variables that allow a designer to design a variety of effects. Not all of these effects are compatible with each other; the following text documents how each variable works, any incompatibilities they might have, and tips to use them effectively.

  - Note that the maximum number of particles that can be in a scene at any given time is given in a configuration file - *%appdata%\September\September.config*

- **_active**:
  - The _active checkbox, located at the bottom of the particle system component, determines whether or not the particle system is updating and generating particles. If a prefab of a particle system is saved, it should be saved with the _active flag turned off (otherwise attempting to pull the prefab into the scene will generate child entities, as the prefab itself will be running in the background).

- **Renderer**:
  - The renderer determines which of the three available renderers to use. This renderer will be applied to every particle generated by a given system. 
  - The ***Mesh Renderer*** renders a shape. This shape is drawn according to the shape specified by Mesh Type, which appears only if Mesh Renderer is selected.
= The Sprite Renderer renders an alpha-blended sprite. The sprite can be chosen from the Sprite dropdown that appears; alternatively, the user can drag an appropriate sprite from the sprite window to the dropdown box.

  - The ***Animation Renderer*** renders an animated texture. The animation can be chosen from the Animation dropdown that appears; alternatively, the user can drag the appropriate animation from the animation window to the dropdown box. 

- **_Start_Delay**: 
  - Specifies how long the particle system will wait before it begins generating particles.

- **_Duration**:
  - Duration specifies the duration during which the particle system will attempt to generate particles. Note that this does not specify the full duration of the particle system; the full duration of the particle system is given by the duration *plus the _Start_Delay*. Each iteration of a given particle system's loop will go through the full _Start_Delay, followed by the full _Duration. 

- **_prewarm**:
  - Specifies whether or not a particle system should prewarm. Prewarming a particle system means that the particle system will iterate through one full loop of its delay and its duration; when the system starts, it begins as though it has already run a full cycle. Note that this does not work correctly with _Has_Collider; it will prewarm the system as though it had no colliders, and only begin colliding after prewarming. 

- **_Start_Lifetime**:
  - Specifies how long each particle in the system lasts.

- **_local**: 
  - Specifies whether or not the local coordinate system should be used. This does not currently work correctly; it is recommended that the _local checkbox is always ticked (set to true).

- **_start_speed**:
  - Specifies the speed at which the particles spawn. All particles will spawn in a random direction specified by the emitter; the velocity of the particle is in the direction that it is spawning in, but the speed is given by _start_speed.

- **_max_particles**:
  - Specifies the max particles that can be used by the system.

- **_is_looping**:
  - Specifies whether or not the particle system should continue looping after a single loop.

- **_Has_Gravity**:
  - Specifies whether or not each particle will be affected by gravity.

- **_Has_Collider**:
  - Specifies whether or not each particle has a collider.

- **_pos**:
  - Specifies the local position of each particle.

- **_scale**: 
  - Specifies the local scale of each particle. 

- **_rate**:
  - Specifies the rate at which particles spawn (in particles per second).

- **_radius**:
  - Specifies the range in which the particle can spawn, starting from the center point. 

- **_inner_radius**: 
  - Specifies the minimum distance from which particles can begin to spawn from the emitter. A combination of _radius and _inner_radius allows particles to spawn in a donut shape or a circular shape, assuming 360 degrees of emission.

- **_deg**:
  - Specifies the local rotation of the system as a whole (i.e. the direction of emission).

- **_angle**:
  - Specifies the number of degrees of emission, based on _deg. A 45 degree angle, for instance, specifies that particles can spawn from -22.5 degrees to 22.5 degrees from _deg.

- **_rotate_with_velocity**:
  - A boolean that specifies whether or not the particles should rotate according to their velocity. This assumes a default rotation of 0.

- **_render_layer**:
  - The render layer on which particles should be drawn; the higher the number, the further towards the screen the particles spawn.

## CURVES:
- The particle system editor features a number of 'curves' that allow the user to determine how the particle should act over its lifetime. These curves are relative to the lifetime of the particle. Each curve contains a 'lifetime' variable; 1.0 refers to end of each particle's lifetime, and 0.0 refers to the beginning. "Add Point" can be used to add further point to the curve and refine the way in which the particle progresses through its lifetime. 

- The following curves currently exist in the particle system:
  - **Colour Over Time:**
    - Specifies how the colour of the particle changes over time.
  - **Speed Over Time:**
    - Specifies how the speed of the particle changes over time. Incompatible with velocity over time and acceleration over time; this curve has less priority than velocity, but more than acceleration. 
  - **Velocity Over Time:**
    - Specifies how the velocity of the particle changes over time. Incompatible with speed over time and acceleration over time; this curve will take priority. 
  - **Acceleration Over Time:**
    - Specifies how the acceleration changes over time. Incompatible  with speed over time and velocity over time; this curve has the lowest priority of the three.
  - **Size Over Time:** 
    - Specifies how the size of each particle changes over time. 