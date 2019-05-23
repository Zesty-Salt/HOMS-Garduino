#include "ReadMe.h"
#include <IRremote.h>
#include <LiquidCrystal.h>
#include <EEPROM.h>

enum keyCodes
{
    Pwr,
    Vup,
    FS,
    Rew,
    PR,
    Skp,
    Dwn,
    Vdn,
    Up,
    Nm0,
    Equ,
    SR,
    Nm1,
    Nm2,
    Nm3,
    Nm4,
    Nm5,
    Nm6,
    Nm7,
    Nm8,
    Nm9,
    Null
};

keyCodes keyCode;

String getKey(long unsigned int input, bool waitForInput)
{
    while (waitForInput)
    {
        if (irrecv.decode(&results)) // Detect input
        {
            input = results.value;
            irrecv.resume();
            delay(250);
            break;
        }
        delay(5);
    }

    if (input == 16753245)
        keyCode = Pwr;
    if (input == 16736925)
        keyCode = Vup;
    if (input == 16720605)
        keyCode = FS;
    if (input == 16720605)
        keyCode = Rew;
    if (input == 16712445)
        keyCode = PR;
    if (input == 16761405)
        keyCode = Skp;
    if (input == 16769055)
        keyCode = Dwn;
    if (input == 16754775)
        keyCode = Vdn;
    if (input == 16748655)
        keyCode = Up;
    if (input == 16738455)
        keyCode = Nm0;
    if (input == 16750695)
        keyCode = Equ;
    if (input == 16756815)
        keyCode = SR;
    if (input == 16724175)
        keyCode = Nm1;
    if (input == 16718055)
        keyCode = Nm2;
    if (input == 16743045)
        keyCode = Nm3;
    if (input == 16716015)
        keyCode = Nm4;
    if (input == 16726215)
        keyCode = Nm5;
    if (input == 16734885)
        keyCode = Nm6;
    if (input == 16728765)
        keyCode = Nm7;
    if (input == 16730805)
        keyCode = Nm8;
    if (input == 16732845)
        keyCode = Nm9;
    return;

    //Copy pasta
    //if (input ==)
    //    keyCode = ;
}

int getSensorData(int sensorType, int sensorNum)
{
    //   sensorType:
    // 1 = Moisture
    // 2 = Light
    // 3 = Temperature

    //   sensorNum:
    // 1 = Bed #1
    // 2 = Bed #2, etc

    int sensorReading;

    if (sensorType = 1)
        if (sensorNum == 1)
            sensorReading = analogRead(moisture_bed1);
        else if (sensorNum == 2)
            sensorReading = analogRead(moisture_bed2);
        else if (sensorNum == 3)
            sensorReading = analogRead(moisture_bed3);
        else if (sensorNum == 4)
            sensorReading = analogRead(moisture_bed4);

    if (sensorType = 2)
        if (sensorNum == 1)
            sensorReading = analogRead(light_bed1);
        else if (sensorNum == 2)
            sensorReading = analogRead(light_bed2);
        else if (sensorNum == 3)
            sensorReading = analogRead(light_bed3);
        else if (sensorNum == 4)
            sensorReading = analogRead(light_bed4);

    if (sensorType = 3)
        if (sensorNum == 1)
            sensorReading = analogRead(temperature_bed1);
        else if (sensorNum == 2)
            sensorReading = analogRead(temperature_bed2);
        else if (sensorNum == 3)
            sensorReading = analogRead(temperature_bed3);
        else if (sensorNum == 4)
            sensorReading = analogRead(temperature_bed4);

    return sensorReading;
}

int waterBed(int bedNum)
{
    //        ================ <- maximum characters
    lcd.clear();
    lcd.print("Watering Bed #");
    lcd.print(bedNum);
    lcd.setCursor(0, 1);
    while (1)
    {
        if (getSensorData(1, bedNum) > too_dry)
        {
            lcd.print(".");
            if (bedNum == 1)
                digitalWrite(relay_bed1, LOW);
            if (bedNum == 2)
                digitalWrite(relay_bed2, LOW);
            if (bedNum == 3)
                digitalWrite(relay_bed3, LOW);
            if (bedNum == 4)
                digitalWrite(relay_bed4, LOW);

            delay(length_of_burst);

            if (bedNum == 1)
                digitalWrite(relay_bed1, HIGH);
            if (bedNum == 2)
                digitalWrite(relay_bed2, HIGH);
            if (bedNum == 3)
                digitalWrite(relay_bed3, HIGH);
            if (bedNum == 4)
                digitalWrite(relay_bed4, HIGH);

            delay(length_of_rest);
        }
        else
        {
            return;
        }
    }
}

int saveData(int slot, int data)
{
    EEPROM.update(slot, data);
    return;
}

byte loadData(int slot)
{
    /*\
      Save slots of data
    //1, 2, 3, 4, // last writing spot ( 1 +  2 + 3 + 4 = Current position)
    // Daily memory (Deleted daily)
    5, 6, 7        // bed 1
    8, 9, 10      // bed 2
    11, 12, 13  // bed 3
    14, 15, 16  // bed 4
    // Weekly memory (Deleted weekly)
    17, 18, 19 // bed 1
    20, 21, 22 // bed 2
    23, 24, 25 // bed 3
    26, 27, 28 // bed 4
    // Settings
    29 // Take Snapshot of data (12 slots required)
    30 // 
    \*/

    byte value;
    value = EEPROM.read(slot);
    return value;
}
