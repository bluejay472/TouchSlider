#include <CapacitiveSensor.h>
#include <Keyboard.h>
/*
 * Using CapitiveSense Library Demo Sketch - Paul Badger 2008 (for sensor input)
 * Using 1M resistors in this sketch, values between 10M and 100K can be used, but you will need to adjust sensitivity levels
 * Sending pin connects via a resistor (with resistance between 10M and 100K) to the receiving pin along with the wire connected to the detector keys
 * IMPORTANT NOTE: The Keyboard() function only currently works on a select handful of Arduinos, make sure you have one that supports it!
 * slider keys are set for: q(slide left) and e(slide right), u(slide left) and o(slide right) 
 * 
 * IMPORTANT: 1 is the right-most key on the slider (the R pad), the highest value on the slider is the left-most key (the L pad) (The keys in-between the L and R pads are the actual slider keys, the L and R pads DO NOT slide or add to slides, they are mainly for just scrolling through songs)
 * 
 * composer of this mess - bluejay472
 * shoutout to - Phaeaz, for helping me form the idea of this project
 */


CapacitiveSensor   cs_30_31 = CapacitiveSensor(30,31);        //resistor between pins 30 & 31, pin 31 is sensor pin, pin 30 is sending pin, change values depending on chosen ports
CapacitiveSensor   cs_34_35 = CapacitiveSensor(34,35);        
CapacitiveSensor   cs_36_37 = CapacitiveSensor(36,37);        
CapacitiveSensor   cs_12_13 = CapacitiveSensor(12,13);
CapacitiveSensor   cs_24_25 = CapacitiveSensor(24,25);
CapacitiveSensor   cs_42_43 = CapacitiveSensor(42,43);
CapacitiveSensor   cs_44_45 = CapacitiveSensor(44,45);
CapacitiveSensor   cs_46_47 = CapacitiveSensor(46,47);
CapacitiveSensor   cs_48_49 = CapacitiveSensor(48,49);
CapacitiveSensor   cs_50_51 = CapacitiveSensor(50,51);
CapacitiveSensor   cs_6_7 = CapacitiveSensor(6,7);
CapacitiveSensor   cs_2_3 = CapacitiveSensor(2,3);
CapacitiveSensor   cs_8_9 = CapacitiveSensor(8,9);
CapacitiveSensor   cs_10_11 = CapacitiveSensor(10,11);


// lots of vars... just bear with me...
int pastKey;
int pastKey2;
long holdu;
long holdo;
long holdq;
long holde;
bool keyq;
bool keye;
bool keyu;
bool keyo;
bool leftkey;
bool rightkey;
bool down1;
bool down2;

void setup()                    
{
   cs_30_31.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1, because why not?
   Keyboard.begin(); //starting keyboard control
   
   Serial.begin(9600); //port baud rate
}

void loop()                    
{
    //more vars, these don't have to be empty though
    int currentKey = 0;
    int currentKey2 = 0;
    bool isOne = false;
    bool isTwo = false;
    //starting all the sensor vars
    long start = millis();
    long total1 =  cs_30_31.capacitiveSensor(30); //key one
    long total2 =  cs_34_35.capacitiveSensor(30); //key two
    long total3 =  cs_36_37.capacitiveSensor(30); //key three (and so on and so forth)
    long total4 =  cs_12_13.capacitiveSensor(30);
    long total5 =  cs_24_25.capacitiveSensor(30);
    long total6 =  cs_42_43.capacitiveSensor(30);
    long total7 =  cs_44_45.capacitiveSensor(30);
    long total8 =  cs_46_47.capacitiveSensor(30);
    long total9 =  cs_50_51.capacitiveSensor(30);
    long total10 =  cs_48_49.capacitiveSensor(30);
    long total11 = cs_6_7.capacitiveSensor(30);
    long total12 = cs_8_9.capacitiveSensor(30);
    long total13 = cs_2_3.capacitiveSensor(30);
    long total14 = cs_10_11.capacitiveSensor(30);
    

    //-------------------------------------------------------------------------------------------------------------------------------key definition (desc on adding more keys at bottom of this section)
    if(total1 > 1000) // Key 1//------------------ (set with a minimum of 1000 for detection) (change this value to your own!)
    {
      //Serial.println("1");//for serial testing 
       
      if(isOne == false)
      {
        currentKey = 1;
        isOne = true;
      }
      if(isOne == true && currentKey != 1 && isTwo == false)
      {
        currentKey2 = 1;
        isTwo = true;
      }
    }
    
    if(total2 > 1000) // Key 2//------------------- (set with a minimum of 1000 for detection)(change this value to your own!)
    {
      //Serial.println("2");//for serial testing
      
      if(isOne == false)
      {
        currentKey = 2;
        isOne = true;
      }
      if(isOne == true && currentKey != 2 && isTwo == false)
      {
        currentKey2 = 2;
        isTwo = true;
      }
    }
    
    if(total3 > 1000) // Key 3//--------------------- (set with a minimum of 1000 for detection) (change this value to your own!...and so on and so forth)
    {
      //Serial.println("3");//for serial testing
      
      if(isOne == false)
      {
        currentKey = 3;
        isOne = true;
      }
      if(isOne == true && currentKey != 3 && isTwo == false)
      {
        currentKey2 = 3;
        isTwo = true;
      }
    }
    
    if(total4 > 1000) // Key 4//----------------------- (set with a minimum of 1000 for detection)
    {
      //Serial.println("4");//for serial testing
      
      if(isOne == false)
      {
        currentKey = 4;
        isOne = true;
      }
      if(isOne == true && currentKey != 4 && isTwo == false)
      {
        currentKey2 = 4;
        isTwo = true;
      }
    }
    
    if(total5 > 1000) // Key 5//----------------------- (set with a minimum of 1000 for detection)
    {
      //Serial.println("5");//for serial testing
      
      if(isOne == false)
      {
        currentKey = 5;
        isOne = true;
      }
      if(isOne == true && currentKey != 5 && isTwo == false)
      {
        currentKey2 = 5;
        isTwo = true;
      }
    }
    
    if(total6 > 1000) // Key 6//----------------------- (set with a minimum of 1000 for detection)
    {
      //Serial.println("6");//for serial testing
      
      if(isOne == false)
      {
        currentKey = 6;
        isOne = true;
      }
      if(isOne == true && currentKey != 6 && isTwo == false)
      {
        currentKey2 = 6;
        isTwo = true;
      }
    }
    
    if(total7 > 1000) // Key 7//------------------------ (set with a minimum of 1000 for detection)
    {
      //Serial.println("7");//for serial testing
      
      if(isOne == false)
      {
        currentKey = 7;
        isOne = true;
      }
      if(isOne == true && currentKey != 7 && isTwo == false)
      {
        currentKey2 = 7;
        isTwo = true;
      }
    }
    
    if(total8 > 1000) // Key 8//------------------------- (set with a minimum of 1000 for detection)
    {
      //Serial.println("8");//for serial testing
      
      if(isOne == false)
      {
        currentKey = 8;
        isOne = true;
      }
      if(isOne == true && currentKey != 8 && isTwo == false)
      {
        currentKey2 = 8;
        isTwo = true;
      }
    }
    
    if(total9 > 1000) // Key 9//-------------------------- (set with a minimum of 1000 for detection)
    {
      //Serial.println("9");//for serial testing
      ;
      if(isOne == false)
      {
        currentKey = 9;
        isOne = true;
      }
      if(isOne == true && currentKey != 9 && isTwo == false)
      {
        currentKey2 = 9;
        isTwo = true;
      }
    }
    
    if(total10 > 1000) // Key 10//------------------------- (set with a minimum of 1000 for detection)
    {
      //Serial.println("10");//for serial testing
      
      if(isOne == false)
      {
        currentKey = 10;
        isOne = true;
      }
      if(isOne == true && currentKey != 10 && isTwo == false)
      {
        currentKey2 = 10;
        isTwo = true;
      }
    }
    
    if(total11 > 1000) // Key 11//-------------------------- (set with a minimum of 1000 for detection)
    {
      //Serial.println("11");//for serial testing
      
      if(isOne == false)
      {
        currentKey = 11;
        isOne = true;
      }
      if(isOne == true && currentKey != 11 && isTwo == false)
      {
        currentKey2 = 11;
        isTwo = true;
      }
    }
    
    if(total12 > 1000) // Key 12//--------------------------- (set with a minimum of 1000 for detection)
    {
      //Serial.println("12");//for serial testing
      
      if(isOne == false)
      {
        currentKey = 12;
        isOne = true;
      }
      if(isOne == true && currentKey != 12 && isTwo == false)
      {
        currentKey2 = 12;
        isTwo = true;
      }
    }

    if(total13 > 1000) // Key 13//--------------------------- (set with a minimum of 1000 for detection)
    {
      if(isOne == false)
      {
        currentKey = 13;
        isOne = true;
      }
      if(isOne == true && currentKey != 13 && isTwo == false)
      {
        currentKey2 = 13;
        isTwo = true;
      }
    }
    
    if(total14 > 1000) // Key 14//------------------------- (set with a minimum of 1000 for detection)
    {
      if(isOne == false)
      {
        currentKey = 14;
        isOne = true;
      }
      if(isOne == true && currentKey != 14 && isTwo == false)
      {
        currentKey2 = 14;
        isTwo = true;
      }
    }

    
    //TO ADD MORE KEYS: copy a key -> paste below key 14. Change total[whatever is here] to whatever your key variable is.
    //At currentKey = xx;, currentKey != xx;, and currentKey2 = xx; change xx to whatever number that key is.
    //example: key 12 = 12, key 13 = 13, key 14 = 14 and so forth
    //NOTE: if you are adding more keys, you WILL have to change the "L/R keypad detection" section from "14" to whatever your last key is

    
    //------------------------------------------------------------------------------------------------------------------------------------------------ processing
    //------------------------------------------------L/R keypad detection
    if(currentKey == 1 || currentKey2 == 1)
    {
      rightkey = true;
    }
    else
    {
      rightkey = false;
    }
    if(currentKey == 14 || currentKey2 == 14) //set the number to the left-most key's value on the keypad
    {
      leftkey = true;
    }
    else
    {
      leftkey = false;
    }
    
    //-----------------------de-increment hold with time
    
    if(holdu > 0)
    {
      holdu -= 10;
    }
    if(holdo > 0)
    {
      holdo -= 10;
    }
    if(holdq > 0)
    {
      holdq -= 10;
    }
    if(holde > 0)
    {
      holde -= 10;
    }

    //-------------------------------release hold if has been held and hold time ran out
    if(holdu == 0 && keyu == true)
    {
      Keyboard.release('u');
      Serial.println("released u!");//for serial testing
      keyu = false;
    }
    
    if(holdo == 0 && keyo == true)
    {
      Keyboard.release('o');
      Serial.println("released o!");//for serial testing
      keyo = false;
    }
    
    if(holdq == 0 && keyq == true)
    {
      Keyboard.release('q');
      Serial.println("released q!"); //for serial testing
      keyq = false;
    }
    
    if(holde == 0 && keye == true)
    {
      Keyboard.release('e');
      Serial.println("released e!"); //for serial testing
      keye = false;
    }
    if(rightkey == true)
    {
      if(down1 == false)
      {
        down1 = true;
        Keyboard.press('e');
        Serial.println("pressed e!"); //for serial testing
      }
      return;
    }
    if(leftkey == true)
    {
      if(down2 == false)
      {
        down2 = true;
        Keyboard.press('q');
        Serial.println("pressed q!"); //for serial testing
      }
      return;
    }
    if(rightkey == false && down1 == true)
    {
      down1 = false;
      Keyboard.release('e');
      Serial.println("released e!"); //for serial testing
    }
    if(leftkey == false && down2 == true)
    {
      down2 = false;
      Keyboard.release('q');
      Serial.println("released q!"); //for serial testing
    }
    
    //----------------------------------------input filters
    if(currentKey == 0) //clear out no input
    {
      pastKey = currentKey;
      pastKey2 = currentKey2;
      delay(1);
      return;
    }
    
    if(pastKey == 0) //return if first input
    {
      pastKey = currentKey;
      pastKey2 = currentKey2;
      delay(1);
      //Serial.println("reset!");//for serial testing
      return;
    }
    
    if(isTwo == true) //grouping input correctly if more than one
    {
      int temp = 0;
      int group = abs(currentKey2 - pastKey);
      if(group <= 2)
      {
        temp = currentKey;
        currentKey = currentKey2;
        currentKey = temp;
      }
    }
    int test1 = abs(currentKey - pastKey); //-------------------------------------finding the difference between the past and current key
    int test2 = abs(currentKey2 - pastKey2); //------------------------------------ for the second key input as well
    if(isTwo == false && test1 > 2)              
    {
      pastKey = currentKey;
      pastKey2 = currentKey2;
      delay(1);
      return;
    }

    
    //-------------------------------------------------direction detection
    if(test1 <= 2)//checking direction for key1, and incrementing directional hold
    {
      int byTwo = pastKey * 2;
      int sum = currentKey + pastKey;
      if(sum > byTwo)
      {
        holdu += 140;
      }
      if(sum < byTwo)
      {
        holdo += 140;
      }
    }
    
    if(isTwo == true && test2 < 2 && pastKey2 != 0){
    
      //Serial.println("one:"); // all for serial testing
      //Serial.println(currentKey2);
      //Serial.println("two:");
      //Serial.println(pastKey2); 
      int byTwo = pastKey2 * 2;
      int sum = currentKey2 + pastKey2;
      if(sum > byTwo)
      {
        holdq += 140;  
      }
      if(sum < byTwo)
      {
        holde += 140;
      }   
    }
    //--------------------------------------------hold if not held and key is pressed
    if(holdu > 0 && keyu == false)
    {
      Keyboard.press('u');
      Serial.println("u");//for serial testing
      keyu = true;
      
      if(keyo == true && holdo > 0)//in case it tries to over-hold a key
      {
        holdo = 0;
      }
    }
    
    if(holdo > 0 && keyo == false)
    {
      Keyboard.press('o');
      Serial.println("o");//for serial testing
      keyo = true;
      
      if(keyu == true && holdu > 0)//in case it tries to over-hold a key
      {
        holdu = 0;
      }
    }
    
    if(holdq > 0 && keyq == false)
    {
      Keyboard.press('q');
      Serial.println("q");//for serial testing
      keyq = true;
      if(keye == true && holde > 0)//in case it tries to over-hold a key
      {
        holde = 0;
      }
    }
    
    if(holde > 0 && keye == false)
    {
      Keyboard.press('e');
      Serial.println("e");//for serial testing
      keye = true;
      if(keyq == true && holdq > 0)//in case it tries to over-hold a key
      {
        holdq = 0;
      }
    }
    
    //swap vars
    pastKey = currentKey;
    pastKey2 = currentKey2;    
    delay(1);                             
}
