Description: Instructions for making the "WalkerBot" robot
Author: Farhan Nur Shabab
Date: 12/11/2015

The first thing to do would be to go through the video, pausing at the frames where a lot of details
is revealed. The video summarizes the entire build and would help to understand what tools required
and when to start working on different parts of the project. When needed, refer the data sheets 
provided.

3D print the parts for which the .stl files have been provided. Print two copies of the "motor_holder"
and "crank_connector". Make sure to use a high infill density (60-100%) for the crank connectors.

Using the "Leg_Linkages_LineDiagram_forLaserCutter" file, lasercut the leg linkages twice, using the
same line diagram file. You might need to do some processing on the image to extract the vectors.
You will need two 1/4 inch thick 1 foot by foot acrylic plates.

---------------------------------------------- optional-----------------------------------------------

If you don't have access to a lasercutter, you can 3D print the leg linkages, though this is not
recommended. To do so, open the "WalkerBot_Assembly.stp" file in your preferred CAD program as an
assembly, and open each leg part. Then export each of these parts as a .stl file.

Also, if you would like to make your own line diagram of the leg linkages for lasercutting, then 
assemble each leg linkage part on a flat plane and export a drawing file (.dwg or .dxf) of the top
down view. 

------------------------------------------------------------------------------------------------------

Solder wires onto the motor terminals. Tape and screw the motors (RA27GM02) into their 3D printed 
holders. If you want to use a different set of motors, then make sure those are gearhead motors. You
will also need to change motor holders. Extract the motor_holder part file from the "Chassis_Assembly", 
make edits to fit your motors and export it as a .stl file for printing. The "crank_connector" will need
to be edited as well at the keyed slot for mating with the motor shaft. Bolt the motor holders with the
motors in them onto the chassis.

Mount the crank connectors onto the motor shaft. Be sure to match the flat in the slot hole with the key
flat on the motor shaft. Use hot glue or superglue to secure.

Insert two long threaded rods (or four and join each pair at the middle using a nut) into the holes at
the sides of the chassis. Refer to the provided "Parts_List" file to ascertain the standards for the rods,
nuts and bolts and to gauge how many of them you will need.

From here on, assemble the leg linkages using the images on the "WalkerBot_Leg_Arrangement" file. Many 
permutations of arrangements are possible. Just be sure to use spacers and nuts as necessary and make
sure the legs on the left are mirror reflections of those on the right.

Glue the breadboard holder part on top of the Arduino holder. Mount the Arduino and partially make 
the connections according to the wiring diagram in the file "WalkerBot_Wiring_Diagram". The L293D and 
the sensors sit on the breadboard. There is a battery segment in the Arduino holder to place a 9V battery
to power the Arduino. Upload the code provided in the "Arduino_WalkerBot_code" onto the microncontroller.
Using a serial monitor in the Arduino IDE, check if everything is working properly.

Make a hole on the front on the chassis and attach an SPST switch using hot glue. Solder long wires to its
terminals. Slot in the subassembly consisting of the breadboard and Arduino holders, the arduino, breadboard
and sensors into the middle of the chassis. Connect the motors to the motor logic terminals on the L293D. 
Connect the SPST switch as well.

The build is more or less complete. You can power the motors through the VCC2 terminal on the L293D using 
a DC power source. Or you can get a battery pack and attach it at the bottom of the chassis.

Making sure the Arduino and the motors are powered, turning the SPST switch to on should get the WalkerBot
started. Clap close to the mike to trigger the bot to "dance". If it faces an obstacle, it should turn right.
Note, you can tune the IR sensor by turning its potentiometer knobs.

- Best
  Farhan Nur Shabab
  B.E Mechanical Engineering
  Vanderbilt University 2015