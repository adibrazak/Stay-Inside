# EV3-Stay-Inside
EV3 LEGO® Mindstorms® was programmed using Eclipse with c4ev3 software package to randomly moving while keep staying inside the box. Light Reflection Sensor was attached to detect the black tape. 
EV3 robot was programmed as follows:
  1. EV3 move straight until black tape is detected.
  2. Then, it will reverse a bit.
  3. After reverse, EV3 will randomly rotate
  4. The process will keep repeat in loops until center button is pressed.

The EV3 can differentiate between the floors and the black tape because the Light Reflection Sensor will return different percentage value when light beam reflected from different target.
Typically, the black tape will have lower sensor reading value compared to the floors. 
The reading value will be affected by the surface color, surface type, surrounding lighting, and height of the sensor from the floor.


The program is written in C/C++ using Eclipse with c4ev3 software package. Link for references on c4ev3 https://c4ev3.github.io/

EV3 demonstration https://www.youtube.com/watch?v=WsnFHsRC0JA 
