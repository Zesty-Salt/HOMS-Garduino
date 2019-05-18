#include <IRremote.h>
#include <LiquidCrystal.h>
#include "Functions.h"

/*
    === Instructions For User!

    == To manually water a bed:
    Step 1: Press >|| (Pause/Resume)
    Step 2: Using >>| and |<<, navigate the menu and press "1" for "Water Bed"
    Step 3: Select a bed to water (PLEASE PRESS 1 UNTIL LATER NOTICE)
    Step 4: Select watering method (PLEASE PRESS 1 UNTIL LATER NOTICE)
    Step 5: (If Normal mode) press power button to stop watering when needed

    == To check a sensor:
    Step 1: Press >|| (Pause/Resume)
    Step 2: Using >>| and |<<, navigate the menu and press "2" for "Check Sensor"
    Step 3: Choose your target sensor using "1," "2," or "3" (Other sensors are not set up at the moment)
    Step 4: Press Func/Stop for a readings
    Step 5: Press power key to exit

    == To change settings

    == To read saved data
*/

// Timer stuff
unsigned long previousMillis = 0;
int tab = 0;

void setup()
{
  digitalWrite(relay_bed1, HIGH);
  digitalWrite(relay_bed2, HIGH);
  digitalWrite(relay_bed3, HIGH);
  digitalWrite(relay_bed4, HIGH);

  lcd.createChar(1, Temperature);
  lcd.createChar(2, Moisture);
  lcd.createChar(3, Brightness);
  lcd.createChar(4, Down);
  lcd.createChar(5, Up);

  irrecv.enableIRIn();
  lcd.begin(16, 2);
  lcd.clear();

  pinMode(relay_bed1, OUTPUT);
  pinMode(relay_bed2, OUTPUT);
  pinMode(relay_bed3, OUTPUT);
  pinMode(relay_bed4, OUTPUT);
}

void loop()
{
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval_check)
  {
    previousMillis = currentMillis;

    lcd.clear();
    //            ================ If your curious, this tells me if the message fits on screen
    lcd.print("Checking Bed #");
    lcd.setCursor(0, 1);

    lcd.print("");
  }
  if (currentMillis - previousMillis >= interval_tabChg)
  {
    previousMillis = currentMillis;
    switch (tab)
    {
    case 0:
      lcd.clear();
      lcd.print("Welcome to the");
      lcd.setCursor(0, 1);
      lcd.print("HOMS Garden!");
      break;
    case 1:
      //         ================
      lcd.clear();
      lcd.print("Use >|| to bring");
      lcd.setCursor(0, 1);
      lcd.print("up dev menu");
      break;
    case 2:
      //         ================
      lcd.clear();
      lcd.print("Readings Bed #1:");
      lcd.setCursor(0, 1);
      lcd.write(1);
      lcd.print("Err ");
      lcd.write(2);
      lcd.print(analogRead(moisture_bed1));
      lcd.print(" ");
      lcd.write(3);
      lcd.print("Err");
      break;
    case 3:

      //         ================
      lcd.clear();
      lcd.print("Readings Bed #2:");
      lcd.setCursor(0, 1);
      lcd.write(1);
      lcd.print("Err ");
      lcd.write(2);
      lcd.print("Err ");
      lcd.print(" ");
      lcd.write(3);
      lcd.print("Err");
      break;

    case 4:
      //         ================
      lcd.clear();
      lcd.print("Readings Bed #3:");
      lcd.setCursor(0, 1);
      lcd.write(1);
      lcd.print("Err ");
      lcd.write(2);
      lcd.print("Err ");
      lcd.print(" ");
      lcd.write(3);
      lcd.print("Err");
      break;

    case 5:
      //         ================
      lcd.clear();
      lcd.print("Readings Bed #4:");
      lcd.setCursor(0, 1);
      lcd.write(1);
      lcd.print("Err ");
      lcd.write(2);
      lcd.print("Err ");
      lcd.print(" ");
      lcd.write(3);
      lcd.print("Err");
      break;
    }

    if (tab < 5)
    {
      tab++;
    }
    else
    {
      tab = 0;
    }
  }

  // Detect input
  if (irrecv.decode(&results))
  {
    return_button(results.value);
    irrecv.resume();
    delay(250);
  }

  // If you press pause / resume, Bring up menu

  // need help organizing this code with functions, for loops, etc
  /* - - -    Need help starting here    - - -*/
  if (key_code == "P/R")
  {
    lcd.clear();
    lcd.print("Main Menu");

    delay(500);

    lcd.clear();
    lcd.print("Select An Option");
    lcd.setCursor(0, 1);
    //         ================
    lcd.print("using >>| & |<<");

    delay(2500);

    lcd.clear();
    lcd.setCursor(0, 0);
    //         ================
    lcd.print("1| Water Bed 1/2");
    lcd.setCursor(0, 1);
    lcd.print("2| Check Sensor");
    lcd.setCursor(16, 0);
    lcd.print("3| Settings  2/2");
    lcd.setCursor(16, 1);
    lcd.print("4| View data");

    bool right_on = true;
    bool left_on = false;
    while (1)
    {
      if (irrecv.decode(&results))
      {
        return_button(results.value);
        irrecv.resume();
        delay(250);
      }

      if (key_code == "Skp" && right_on)
      {
        right_on = false;
        left_on = true;
        key_code = "";
        for (int i = 16; i > 0; i--)
        {
          lcd.scrollDisplayLeft();
          delay(75);
        }
      }

      if (key_code == "Rew" && left_on)
      {
        left_on = false;
        right_on = true;
        key_code = "";
        for (int i = 16; i > 0; i--)
        {
          lcd.scrollDisplayRight();
          delay(75);
        }
      }

      if (key_code == "Pwr")
        break;

      if (key_code == "Nm1")
      {
        key_code = "";
        lcd.clear();
        lcd.print("Choose target");
        lcd.setCursor(0, 1);
        lcd.print("bed 1-4");
        while (1)
        {
          if (irrecv.decode(&results))
          {
            return_button(results.value);
            irrecv.resume();
            delay(250);
          }
          if (key_code == "Pwr")
            break;

          if (key_code == "Nm1")
          {
            lcd.clear();
            //         ================
            lcd.print("You have");
            lcd.setCursor(0, 1);
            lcd.print("selected bed 1");
            delay(1500);
            water_bed(1);
          }
          if (key_code == "Nm2")
          {
            lcd.clear();
            //         ================
            lcd.print("You have");
            lcd.setCursor(0, 1);
            lcd.print("selected bed 2");
            delay(1500);
            water_bed(2);
          }
          if (key_code == "Nm3")
          {
            lcd.clear();
            //         ================
            lcd.print("You have");
            lcd.setCursor(0, 1);
            lcd.print("selected bed 3");
            delay(1500);
            water_bed(3);
          }
          if (key_code == "Nm4")
          {
            lcd.clear();
            //         ================
            lcd.print("You have");
            lcd.setCursor(0, 1);
            lcd.print("selected bed 4");
            delay(1500);
            water_bed(4);
          }
        }
      }
      if (key_code == "Nm2")
      {
        int target_bed;
        //         ================
        lcd.clear();
        lcd.print("Sensor Dashboard");
        lcd.setCursor(0, 1);
        lcd.print("Select a bed 1-4");

        while (1)
        {
          if (irrecv.decode(&results))
          {
            return_button(results.value);
            irrecv.resume();
            delay(250);
          }

          if (key_code == "Pwr")
            return;

          if (key_code == "Nm1")
          {
            target_bed = 1;
            break;
          }
          if (key_code == "Nm2")
          {
            target_bed = 2;
            break;
          }
          if (key_code == "Nm3")
          {
            target_bed = 3;
            break;
          }
          if (key_code == "Nm4")
          {
            target_bed = 4;
            break;
          }
        }

        //         ================
        lcd.clear();
        lcd.print("Select a sensor");
        lcd.setCursor(0, 1);

        delay(2500);

        lcd.clear();
        lcd.setCursor(0, 0);
        //         ================
        lcd.print("1| Moisture  1/2");
        lcd.setCursor(0, 1);
        lcd.print("2| Brightness");
        lcd.setCursor(16, 0);
        lcd.print("3| Temperature");
        lcd.setCursor(16, 1);
        lcd.print("             2/2");

        left_on = false;
        right_on = true;
        key_code = "";
        while (1)
        {
          if (irrecv.decode(&results))
          {
            return_button(results.value);
            irrecv.resume();
            delay(250);
          }

          if (key_code == "Skp" && right_on)
          {
            right_on = false;
            left_on = true;
            key_code = "";
            for (int i = 16; i > 0; i--)
            {
              lcd.scrollDisplayLeft();
              delay(75);
            }
          }

          if (key_code == "Rew" && left_on)
          {
            left_on = false;
            right_on = true;
            key_code = "";
            for (int i = 16; i > 0; i--)
            {
              lcd.scrollDisplayRight();
              delay(75);
            }
          }

          if (key_code == "Nm1")
          {
            lcd.clear();
            lcd.print("Press Func/Stop");
            lcd.setCursor(0, 1);
            lcd.print("For readings");
            while (1)
            {

              if (irrecv.decode(&results))
              {
                return_button(results.value);
                irrecv.resume();
                delay(75);
              }

              if (key_code == "Pwr")
              {
                key_code = "Pwr";
                break;
              }
              if (key_code == "F/S")
              {
                lcd.clear();
                lcd.print("Moisture");
                if (target_bed == 1)
                  lcd.print(" Bed #1");
                if (target_bed == 2)
                  lcd.print(" Bed #2");
                if (target_bed == 3)
                  lcd.print(" Bed #3");
                if (target_bed == 4)
                  lcd.print(" Bed #4");
                lcd.setCursor(0, 1);
                lcd.write(2);
                lcd.print(" ");

                if (target_bed == 1)
                  lcd.print(analogRead(moisture_bed1));
                if (target_bed == 2)
                  lcd.print(analogRead(moisture_bed2));
                if (target_bed == 3)
                  lcd.print(analogRead(moisture_bed3));
                if (target_bed == 4)
                  lcd.print(analogRead(moisture_bed4));

                key_code = "";
              }
              if (key_code == "Nm1")
                target_bed = 1;
              if (key_code == "Nm2")
                target_bed = 2;
              if (key_code == "Nm3")
                target_bed = 3;
              if (key_code == "Nm4")
                target_bed = 4;
            }
          }
          if (key_code == "Nm2")
          {
            lcd.clear();
            lcd.print("Press Func/Stop");
            lcd.setCursor(0, 1);
            lcd.print("For readings");
            while (1)
            {
              if (irrecv.decode(&results))
              {
                return_button(results.value);
                irrecv.resume();
                delay(75);
              }

              if (key_code == "Pwr")
              {
                key_code = "Pwr";
                break;
              }
              if (key_code == "F/S")
              {
                lcd.clear();
                lcd.print("Brightness");
                lcd.setCursor(0, 1);
                lcd.write(3);
                lcd.print(" ");

                if (target_bed == 1)
                  lcd.print(analogRead(light_bed1));
                if (target_bed == 2)
                  lcd.print(analogRead(light_bed2));
                if (target_bed == 3)
                  lcd.print(analogRead(light_bed3));
                if (target_bed == 4)
                  lcd.print(analogRead(light_bed4));

                key_code = "";
              }
            }
          }
          if (key_code == "Nm3")
          {
            lcd.clear();
            lcd.print("Press Func/Stop");
            lcd.setCursor(0, 1);
            lcd.print("For readings");
            while (1)
            {
              if (irrecv.decode(&results))
              {
                return_button(results.value);
                irrecv.resume();
                delay(75);
              }

              if (key_code == "Pwr")
              {
                key_code = "Pwr";
                break;
              }
              if (key_code == "F/S")
              {
                lcd.clear();
                lcd.print("Temperature");
                lcd.setCursor(0, 1);
                lcd.write(1);
                lcd.print(" ");

                if (target_bed == 1)
                  lcd.print(analogRead(temperature_bed1));
                if (target_bed == 2)
                  lcd.print(analogRead(temperature_bed2));
                if (target_bed == 3)
                  lcd.print(analogRead(temperature_bed3));
                if (target_bed == 4)
                  lcd.print(analogRead(temperature_bed4));

                key_code = "";
              }
            }
          }
        }
      }
      if (key_code == "Nm3")
      {
      }
      if (key_code == "Nm4")
      {
      }
    }
  }
  delay(250);
}
