#include <CapacitiveSensor.h>
/*
 * Using CapitiveSense Library Demo Sketch - Paul Badger 2008 (for sensor input)
 * Using 1M resistors in this sketch, values between 10M and 100K can be used
 * Sending pin connects via a resistor (with resistance between 10M and 100K) to the receiving pin along with the wire connected to the detector keys
 * 
 * composer - bluejay472
 * shoutout to - Phaeaz, for helping me form the idea of this project
 */

//----------------------------------------------Change these pins AND the variables down below (you can add more if you have more keys)
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

void setup()                    
{
   cs_30_31.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1, because why not?
   
   Serial.begin(9600); //port baud rate
}

void loop()                    
{
    //------------------------------------------Change these to match your sensors above (if you add more keys, add more variables to here AND and more print commands below)
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

    Serial.println("\t one");
    Serial.println(total1);                  // print key 1 output
    Serial.println("\t two :");
    Serial.println(total2);                 // print key 2 output
    Serial.println("\t three :");
    Serial.println(total3);                // print key 3 output
    Serial.println("\t four :");
    Serial.println(total4);               //print key 4 output (and so on and so forth)
    Serial.println("\t five :");
    Serial.println(total5);
    Serial.println("\t six :");
    Serial.println(total6);
    Serial.println("\t seven :");
    Serial.println(total7);
    Serial.println("\t eight :");
    Serial.println(total8);
    Serial.println("\t nine :");
    Serial.println(total9);
    Serial.println("\t ten :");
    Serial.println(total10);
    Serial.println("\t eleven :");
    Serial.println(total11);
    Serial.println("\t twelve :");
    Serial.println(total12);
    Serial.println("\t thirteen :");
    Serial.println(total13);
    Serial.println("\t fourteen :");
    Serial.println(total14);
    //-------------------------------- add more print commands here if you have more keys
    
    delay(10);                             
}
