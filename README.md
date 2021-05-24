# TouchSlider
An alpha-stage touch-sensitive slider designed for use with PDAFT

WARNING: This slider is still in its alpha phase. This is a slightly difficult build. It WILL mis-read some input. Most of its accuracy depends on your calibration.

ANOTHER WARNING: I am very new to Arduino, so I probably won't be much help in fixing issues (Google is your best friend)

I apologize in advance to any programmers trying to read my code

image of alpha slider:
![alt text](https://github.com/bluejay472/TouchSlider/blob/main/Slider_alpha.jpg?raw=true)

NOTE: for buttons, I am using a simple Zero Delay USB encoder and 5 60mm arcade dome buttons. The original machine uses larger buttons, but this is a compact model

Required materials for the slider:
1. Arduino that supports the Keyboard() function - there are only a handful that do, make sure you have the right one!
2. A breadboard (with enough space for selected number of keys)
3. 10M - 100K resistors, NOTE: these do not have to have the same resistance values, as you will be manually calibrating the threshold for each key (also make sure you have one for each key!)
4. Wires, lots of wires. You will be needing Male -> Male and Female -> Male (you will need two Male -> Male and one Female -> Male per key) Long Male->Male wires recommended!!
5. The Keys themselves. These can be out of any conductive material, in my model, I used copper foil tape.
6. General soldering materials (I used a soldering iron and some solder wire)
7. (Optional) a sort of protective cover. The keys can sense resistance through some materials. In my model, I am using simple paper as a cover for my keys, but will eventually add an 1/8" plexiglass cover over the paper.

Note: If you are directly touching the key (no protective cover), static electricity can damage the recieving pin. Some people put low-value resistors in between the key and the receiving pin just in case.

Required Software:
1. The Arduino software: https://www.arduino.cc/en/software
2. Paul Stoffregen's Capacitive Sensor Library: https://github.com/PaulStoffregen/CapacitiveSensor
3. Yes, that's it.

NOTE: if you are as new as I was to Arduino, look up how to get an Arduino set up (based on your model), and how to add a .ZIP library

----Building Instructions-----

You will NOT want to build this like I did (I learned that the hard way), however, the concept is still the same.

How I built it:

(all wood is 1/2" plywood) I used an 11" x 19" board for the baseplate, and 4" walls at 2x(19" x 4") and 2x(10" x 4"), with an 8" x 19" faceplate and an additional 2.5" x 3.5" insert for the start button. While this is very compact, it leaves little room for maintenance without removing screws.

A better alternative:

(again 1/2" plywood for stability) 12" x 19" board for the baseplate, 2x(19" x 5") and 2x(11" x 5") walls, 8" x 19" faceplate, and an additional insert for the start button. This will give you some room to maintenance the controller if the need arises.

NOTE: This is just a possible (and untested) construction of the slider system! There is no set way to construct this yet, as it is still in an alpha stage.


The circuit connections are as follows:


This is a (very) basic diagram of how the touch system works:
![alt text](https://github.com/bluejay472/TouchSlider/blob/main/circuit_diagram.png?raw=true)

And how the diagram above looks like connected to a breadboard:
![alt text](https://github.com/bluejay472/TouchSlider/blob/main/Breadboard_layout.png?raw=true)

And how you can connect the wire to the keys:
![alt text](https://github.com/bluejay472/TouchSlider/blob/main/Slider_connection.jpg?raw=true)


The sending and receiving pins are set in the code itself, so as long as you adjust the code, you can connect the sending and receiving wires to any of these pins:
![alt text](https://github.com/bluejay472/TouchSlider/blob/main/Due_ports.png?raw=true)


----Calibrating Instructions----
1. Find the Key_calibration sketch, change the pins to match what you have connected, and upload it to your arduino
2. If you see a rapid string of numbers in the serial monitor that get larger when you touch a key, success!
3. If some of the keys are unresponsive/there are very large constantly varying numbers/input is stuttering or lagging, jump to the issues section (which is probably where most of you are headed, it's pretty picky)
4. Now the main part of calibration is pretty intuitive. You'll want something to write down numbers, and will probably be toggling autoscroll on and off frequently. Essentially what you're doing is checking each sensor's values when nothing is touching it, and when you are touching it. You'll want to get values from quick touches and long touches to find a good threshold, and find a number that you think will only trigger when you touch it.
5. If you've got numbers, success! you can continue on to the final step.

----Calibating Issues----

If you are getting input issues, it you can have either: a. bad wire(s), b. bad resistor(s), or c. picky ports <-and this is the most common one

To fix:

Find keys that are returning no input (they don't change values when you touch the keys).

Try moving them to new ports (don't forget to change the ports in the sketch and re-upload it!)

Try swapping wires

Try swapping resistors

Unfortuantely that's all I've got. Sorry.

----Slider Code----

At this point you've hopefully made it through and gotten your key values, so it's down to the final monstrosity of code.

Find the Final_Slider_Codev(whatever version I'm on), and change the pins just like you did in calibration

If you added pins, you'll need to add more keys down below in the "key definition section", this is essentially copy and pase (more description in the code itself).

At each key, you will find an if statement with an if(total[key number] > xxx) (xxx is standing for whatever value is currently there), you will want to replace this current value with the value you have for that key (gained from calibration).

Upload the sketch to your Arduino

Hopefully everything should go smoothly!

WARNING: While uing Keyboard(), the Arduino takes control of your keyboard. Be sure to click into something that you don't mind being spammed with letters in case of an input glitch
NOTE: the code is currently set to the default keys q, e, u, and o.

Bonus:
If you want to add labels to your buttons, you can use vinyl sticker printer paper and an inkjet printer to print the note designs for the buttons (I used GIMP to correctly size the picture for the printer)
